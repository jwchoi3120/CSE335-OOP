/**
 * \file Leaf.cpp
 *
 * \author Tom Choi
 */

#include "pch.h"
#include "Leaf.h"

CLeaf::CLeaf(CActualTree* tree, int depth, const std::wstring& filename) : CGrowingStuff(tree, depth, filename)
{

}
