/**
 * \file Aquarium.cpp
 *
 * \author Tom Choi
 */

#include "pch.h"
#include "Aquarium.h"
#include "FishBeta.h"
#include "Neemo.h"
#include "Buddha.h"
#include "DecorCastle.h"
#include "XmlNode.h"
#include <algorithm>
using namespace std;
using namespace xmlnode;
using namespace Gdiplus;
/**
 * Aquarium constructor
 */
CAquarium::CAquarium()
{
	mBackground = unique_ptr<Gdiplus::Bitmap>(Bitmap::FromFile(L"images/background1.png"));
	if (mBackground->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/background1.png");
	}
	
}
/**
* Aquarium destructor
*/
CAquarium::~CAquarium()
{
}

/** Draw the aquarium
* \param graphics The GDI+ graphics context to draw on
*/
void CAquarium::OnDraw(Gdiplus::Graphics* graphics)
{
	graphics->DrawImage(mBackground.get(), 0, 0, mBackground->GetWidth(), mBackground->GetHeight());

	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 16);

	SolidBrush green(Color(0, 64, 0));
	graphics->DrawString(L"Under the Sea!", -1, &font, PointF(2, 2), &green);

	for (auto item : mItems)
	{
		item->Draw(graphics);
	}
}

/**
 * Add an item to the aquarium
 * \param item New item to add
 */
void CAquarium::Add(std::shared_ptr<CItem> item)
{
	mItems.push_back(item);
}

/** Test an x,y click location to see if it clicked
* on some item in the aquarium.
* \param x X location
* \param y Y location
* \returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<CItem> CAquarium::HitTest(int x, int y)
{
	for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
	{
		if ((*i)->HitTest(x, y))
		{
			return *i;
		}
	}

	return  nullptr;
}

void CAquarium::Delete(std::shared_ptr<CItem> mGrabbedItem)
{
	auto loc = find(begin(mItems), end(mItems), mGrabbedItem);
	if (loc != end(mItems))
	{
		mItems.erase(loc);
	}
}

void CAquarium::Nudge(CItem* item)
{
	for (auto i : mItems)
	{
		if (i.get() != item) 
		{
			i->Move(item->GetX(), item->GetY());
		}
	}
}

void CAquarium::Save(const std::wstring& filename)
{
	//
	// Create an XML document
	//
	auto root = CXmlNode::CreateDocument(L"aqua");

	// Iterate over all items and save them
	for (auto item : mItems)
	{
		item->XmlSave(root);
	}

	try
	{
		root->Save(filename);
	}
	catch (CXmlNode::Exception ex)
	{
		AfxMessageBox(ex.Message().c_str());
	}
}

void CAquarium::Load(const std::wstring& filename)
{
	// We surround with a try/catch to handle errors
	try
	{
		// Open the document to read
		shared_ptr<CXmlNode> root = CXmlNode::OpenDocument(filename);

		// Once we know it is open, clear the existing data
		Clear();
		//
		// Traverse the children of the root
		// node of the XML document in memory!!!!
		//
		for (auto node : root->GetChildren())
		{
			if (node->GetType() == NODE_ELEMENT && node->GetName() == L"item")
			{
				XmlItem(node);
			}
		}


	}
	catch (CXmlNode::Exception ex)
	{
		AfxMessageBox(ex.Message().c_str());
	}
}

void CAquarium::Clear()
{
	mItems.clear();
}

void CAquarium::XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
	// A pointer for the item we are loading
	shared_ptr<CItem> item;

	// We have an item. What type?
	wstring type = node->GetAttributeValue(L"type", L"");
	if (type == L"beta")
	{
		item = make_shared<CFishBeta>(this);
	}

	else if (type == L"neemo")
	{
		item = make_shared<CNeemo>(this);
	}
	
	else if (type == L"buddha")
	{
		item = make_shared<CBuddha>(this);
	}
	
	else if (type == L"castle")
	{
		item = make_shared<CDecorCastle>(this);
	}
	if (item != nullptr)
	{
		item->XmlLoad(node);
		Add(item);
	}
}

void CAquarium::Update(double elapsed)
{
	for (auto item : mItems)
	{
		item->Update(elapsed);
	}
}