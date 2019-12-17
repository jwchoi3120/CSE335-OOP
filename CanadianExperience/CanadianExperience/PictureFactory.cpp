/**
 * \file PictureFactory.cpp
 *
 * \author Charles B. Owen
 */

#include "pch.h"
#include "PictureFactory.h"
#include "HaroldFactory.h"
#include "SpartyFactory.h"
#include "ImageDrawable.h"
#include "TreeFactory.h"
#include "TreeDrawable.h"
#include "BasketDrawable.h"
#include "ActualBasket.h"

using namespace std;
using namespace Gdiplus;

CPictureFactory::CPictureFactory()
{
}


CPictureFactory::~CPictureFactory()
{
}


/** Factory method to create a new picture.
* \returns The created picture
*/
std::shared_ptr<CPicture> CPictureFactory::Create()
{
    shared_ptr<CPicture> picture = make_shared<CPicture>();

    // Create the background and add it
    auto background = make_shared<CActor>(L"Background");
    background->SetClickable(false);
    background->SetPosition(Point(-100, 0));
    auto backgroundI = make_shared<CImageDrawable>(L"Background", L"images/Background.png");
    background->AddDrawable(backgroundI);
    background->SetRoot(backgroundI);
    picture->AddActor(background);

    // Create and add Harold
    CHaroldFactory factory;
    auto harold = factory.Create();

    // This is where Harold will start out.
    harold->SetPosition(Point(400, 500));


	CTreeFactory treefactory;
	
	//Create the Basket
	auto basket = treefactory.CreateBasket();
	auto actorBasket = make_shared<CActor>(L"Basket");
	actorBasket->SetClickable(false);
	auto firstBasket = make_shared<CBasketDrawable>(L"Basket");
	firstBasket->SetBasket(basket);
	firstBasket->SetPosition(1000, 300);
	actorBasket->AddDrawable(firstBasket);
	picture->AddActor(actorBasket);
	

	// first tree
	auto tree = treefactory.CreateTree();
	auto actorTree = make_shared<CActor>(L"tree");
	auto firstTree = make_shared<CTreeDrawable>(L"tree");
	firstTree->SetPosition(300, 400);
	firstTree->SetTimeline(picture->GetTimeline());
	firstTree->SetKeyFrame(700);
	firstTree->SetTree(tree);
	actorTree->AddDrawable(firstTree);
	
	picture->AddActor(actorTree);

	// second tree
	auto tree2 = treefactory.CreateTree();
	auto actorTree2 = make_shared<CActor>(L"tree");
	auto secondTree = make_shared<CTreeDrawable>(L"tree");
	secondTree->SetPosition(500, 500);
	secondTree->SetTimeline(picture->GetTimeline());
	secondTree->SetKeyFrame(600);
	secondTree->SetTree(tree2);
	actorTree2->AddDrawable(secondTree);
	
	picture->AddActor(actorTree2);
    picture->AddActor(harold);

    // Create and add Sparty
    CSpartyFactory sfactory;
    auto sparty = sfactory.Create();

    sparty->SetPosition(Point(200, 500));
    picture->AddActor(sparty);

    return picture;
}
