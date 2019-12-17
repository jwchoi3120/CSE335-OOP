/**
 * \file Item.h
 *
 * \author Tom Choi
 *
 * Base class for any item in our aquarium.
 */

#pragma once
#include<memory>
#include<string>
#include"XmlNode.h"
class CAquarium;
/**
*	Implement of Item Class
*
*/
class CItem
{
public:
	virtual ~CItem();
	/** The X location of the item
	 * \returns X location in pixels */
	double GetX() const { return mX; }

	/** The Y location of the item
	* \returns Y location in pixels */
	double GetY() const { return mY; }

	/// Set the item location
	/// \param x X location
	/// \param y Y location
	virtual void SetLocation(double x, double y) { mX = x; mY = y; }
	/// Default constructor (disabled)
	CItem() = delete;

	/// Copy constructor (disabled)
	CItem(const CItem&) = delete;

	/// Draw this item
	/// \param graphics Graphics device to draw on
	void Draw(Gdiplus::Graphics* graphics);
	
	/** Test this item to see if it has been clicked on
		 * \param x X location on the aquarium to test
		 * \param y Y location on the aquarium to test
		 * \return true if clicked on */
	bool HitTest(int x, int y);
	/**
	* move the fish
	* \param stinkyX stinky x position
	* \param stinkyY stinky y position
	*/
	void Move(double stinkyX, double stinkyY);
	/**
	* Save the attributes for an item node.
	*
	* This is the  base class version that saves the attributes
	* common to all items. Override this to save custom attributes
	* for specific items.
	*
	* \param node The Xml node we are loading the item from
	* \return itemNode node
	*/
	virtual std::shared_ptr<xmlnode::CXmlNode>XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node);
	/**
	* Load the attributes for an item node.
	*
	* This is the  base class version that loads the attributes
	* common to all items. Override this to load custom attributes
	* for specific items.
	*
	* \param node The Xml node we are loading the item from
	*/	
	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

	/// Handle updates for animation
	/// \param elapsed The time since the last update
	virtual void Update(double elapsed) {}

	/// Get the aquarium this item is in
	/// \returns Aquarium pointer
	CAquarium* GetAquarium() { return mAquarium; }

	bool mMirror = false;   ///< True mirrors the item image

	/// Set the mirror status
	/// \param m New mirror flag
	void SetMirror(bool m) { mMirror = m; }

	/// Get the height of the aquarium
	/// \returns Aquarium height
	int GetFishWidth() const { return mItemImage->GetWidth(); }

	/// Get the height of the aquarium
	/// \returns Aquarium height
	int GetFishHeight() const { return mItemImage->GetHeight(); }

protected:
	/**
	* \param aquarium aquarium
	* \param filename name of a file
	*/
	CItem(CAquarium* aquarium, const std::wstring &filename);

private:
	// Item location in the aquarium
	double  mX = 0;     ///< X location for the center of the item
	double  mY = 0;     ///< Y location for the center of the item
	/// The aquarium this item is contained in
	CAquarium* mAquarium;
	///image of fish
	std::unique_ptr<Gdiplus::Bitmap> mItemImage;
};

