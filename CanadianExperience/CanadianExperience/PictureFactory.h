/**
 * \file PictureFactory.h
 *
 * \author Charles B. Owen
 *
 * A factory class that builds our picture.
 */

#pragma once

#include <memory>

#include "Picture.h"
#include "TreeDrawable.h"
/**
 * A factory class that builds our picture.
 */
class CPictureFactory
{
public:
    CPictureFactory();
    virtual ~CPictureFactory();
	///create
    std::shared_ptr<CPicture> Create();
	/** \return mFirstTree
	*/
	std::shared_ptr<CTreeDrawable> GetFirstTree() { return mFirstTree; }
	/** \return mSecondTree
	*/
	std::shared_ptr<CTreeDrawable> GetSecondTree() { return mSecondTree; }
private:
	///first tree
	std::shared_ptr<CTreeDrawable> mFirstTree;
	///second tree
	std::shared_ptr<CTreeDrawable> mSecondTree;
};

