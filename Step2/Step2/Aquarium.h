/**
 * \file Aquarium.h
 *
 * \author Tom Choi
 *
 * Creating Aquarium which fishes will go in
 */

#pragma once
#include<memory>
#include<vector>
#include "Item.h"
/**
*	Implement of Aquarium Class
*
*/
class CAquarium
{
public:
	CAquarium();
	virtual ~CAquarium();

	void OnDraw(Gdiplus::Graphics* graphics);
	
	void Add(std::shared_ptr<CItem> item);
	
	std::shared_ptr<CItem> HitTest(int x, int y);
	
	/** Deleting image from aquarium
	* \param mGrabbedItem
	*/
	void Delete(std::shared_ptr<CItem> mGrabbedItem);
	
	/** Nudging image from aquarium
	* \param item
	*/
	void Nudge(CItem* item);
	/**
	* Save the aquarium as a .aqua XML file.
	*
	* Open an XML file and stream the aquarium data to it.
	*
	* \param filename The filename of the file to save the aquarium to
	*/
	void Save(const std::wstring& filename);
	/**
	* Load the aquarium from a .aqua XML file.
	*
	* Opens the XML file and reads the nodes, creating items as appropriate.
	*
	* \param filename The filename of the file to load the aquarium from.
	*/
	void Load(const std::wstring& filename);
	/**
	* Clear the aquarium data.
	*
	* Deletes all known items in the aquarium.
	*/
	void Clear();
	/**
	* Handle an item node.
	* \param node Pointer to XML node we are handling
	*/
	void XmlItem(const std::shared_ptr<xmlnode::CXmlNode>& node);

	/** Handle updates for animation
	* \param elapsed The time since the last update
	*/
	void Update(double elapsed);
	/// Get the width of the aquarium
	/// \returns Aquarium width
	int GetWidth() const { return mBackground->GetWidth(); }

	/// Get the height of the aquarium
	/// \returns Aquarium height
	int GetHeight() const { return mBackground->GetHeight(); }

private:
	std::unique_ptr<Gdiplus::Bitmap> mBackground; ///< Background image

	/// All of the items to populate our aquarium
	std::vector<std::shared_ptr<CItem> > mItems;
};