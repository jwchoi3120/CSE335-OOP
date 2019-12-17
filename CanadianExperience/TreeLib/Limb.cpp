/**
 * \file Limb.cpp
 *
 * \author Tom Choi
 */

#include "pch.h"
#include "PseudoRandom.h"
#include "Limb.h"
#include "ActualTree.h"
#include "CActualFruit.h"
#include "Leaf.h"
using namespace Gdiplus;
using namespace std;
///growth rate
const double GrowthRate = 0.45;

CLimb::CLimb(CActualTree* tree, int depth) : CTreeItem(tree, depth)
{

}

void CLimb::Draw(Gdiplus::Graphics* graphics, double angle, Gdiplus::Point rootLocation)
{
	double windspeed = GetTree()->GetWindSpeed() * 0.3 * this->GetDepth();
	double useAngle = angle + this->GetAngle() + windspeed;

	double dy = cos(useAngle) * mHeight;
	double dx = sin(useAngle) * mHeight;


	Gdiplus::Pen limb(Gdiplus::Color(139, 69, 19), mWidth);
	limb.SetEndCap(LineCapRound);
	graphics->DrawLine(&limb, rootLocation, Gdiplus::Point(rootLocation.X - dx, rootLocation.Y - dy));

	if (!mChildren.empty())
	{
		for (auto child : mChildren)
		{
			child->Draw(graphics, useAngle, Gdiplus::Point(rootLocation.X - dx, rootLocation.Y - dy));
		}
	}
}

void CLimb::Grow()
{
	double delta = 1 / 30.0;
	double growRate = pow((1.0 + GrowthRate), delta);

	mHeight *= growRate;
	mWidth *= growRate;
	for (auto child : mChildren)
	{
		child->Grow();
	}

	CActualTree* tree = GetTree();
	CPseudoRandom* rand = tree->GetRandom();
	double depth = this->GetDepth();

	if (depth < 12 && rand->Random(0.0, 1.0) < 0.05 && mChildren.size() < 2)
	{
		auto limb = std::make_shared<CLimb>(tree, depth + 1);
		double rot2 = rand->Random(-0.5, 0.5);
		limb->SetAngle(rot2);
		this->AddChild(limb);
	}
	else if (depth > 7 && rand->Random(0.0, 1.0) < 0.7 && mChildren.size() < 2)
	{
		auto leaf = std::make_shared<CLeaf>(tree, depth, L"images/leaf.png");
		double rot2 = rand->Random(-0.5, 0.5);
		leaf->SetAngle(rot2);
		this->AddChild(leaf);
	}
	else if (depth > 7 && rand->Random(0.0, 1.0) < 0.6 && mChildren.size() < 2)
	{
		auto fruit = std::make_shared<CActualFruit>(tree, depth, L"images/apple.png");
		double rot2 = 3.141592;
		fruit->SetAngle(rot2);
		this->AddChild(fruit);
		tree->AddFruit(fruit);
	}
}

void CLimb::AddChild(std::shared_ptr<CTreeItem> child)
{
	mChildren.push_back(child);
	child->SetParent(this);
	child->SetTree(this->GetTree());
}

void CLimb::EraseChildren(shared_ptr<CActualFruit> fruit)
{
	vector<shared_ptr<CTreeItem>>::iterator iter;
	iter = find(mChildren.begin(), mChildren.end(), fruit);
	auto dist = distance(mChildren.begin(), iter);
	mChildren.erase(mChildren.begin() + dist);
}