/**
 * \file TreeImageItem.h
 *
 * \author Tom Choi
 *
 * tree image item class
 */

#pragma once
#include <gdiplus.h>
#include <memory>
#include <string>
/** treeimageitem class
*/
class CTreeImageItem
{
public:
	/** \param name
	* constructor
	*/
	CTreeImageItem(const std::wstring name) { LoadImage(name); }
	/** \brief Default constructor disabled */
	//CTreeImageItem() = delete;
	/** \brief Copy constructor disabled */
	//CTreeImageItem(const CTreeImageItem&) = delete;
	/** \brief Assignment operator disabled */
	void operator=(const CTreeImageItem&) = delete;
	///destructor
	virtual ~CTreeImageItem() {}
	/** \param name
	*/
	void LoadImage(const std::wstring& name);
	/** \param graphics, angle, scale, rootLocation
	*/
	void DrawImage(Gdiplus::Graphics* graphics, double angle, double scale, Gdiplus::Point rootLocation);

private:
	std::shared_ptr<Gdiplus::Bitmap> mImage; ///< The part image


};

