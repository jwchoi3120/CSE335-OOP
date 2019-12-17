/**
 * \file Controller.cpp
 *
 * \author Tom Choi
 */

#include "stdafx.h"
#include "Controller.h"

/// Location of the Wardrobe station in conveyor units
const double WardrobeStation = 1;

/// Location of the Inspection station in conveyor units
const double InspectionStation = 4;

/// Location considered to be off the screen in conveyor units
const double OffScreen = 5;

/**
 * Constructor
 */
CController::CController()
{
}

/**
 * Destructor
 */
CController::~CController()
{
}

/** Initialization function.
*
* This function is called when the system is initialized. This is
* later than when it is constructed, since the controller is not installed on
* a kitchen when it is constructed. This function is called when the kitchen
* controller is installed and ready to control a kitchen.
*/
void CController::Initialize()
{
    EnableButtonNext();
}

void CController::SetState(States state)
{
    mState = state;
    mStateTime = 0;
    switch (mState)
    {
    case Idle:
        EnableButtonNext();
    default:
        break;
    }
}

/** Service the kitchen.
*
* This function is called once every millisecond during kitchen
* operation. It provides a place to put code the controls the
* kitchen. Override in a local function.
*/
void CController::Service()
{
    // Increment state time by 1 millisecond
    mStateTime += 0.001;

    switch (mState)
    {
    case Idle:
        break;

    case MoveToWardrobe:
        if (GetTurkeyPosition() >= 0.99 && GetTurkeyPosition() < 1.01)
        {
            SetConveyorSpeed(0);
            DisableButtonNext();
            EnableButtonAdvance();
            EnableButtonWardrobe();
            SetState(Wardrobe);
        }
        break;

    case MoveToInspection:
        if (GetTurkeyPosition() >= InspectionStation)
        {
            SetConveyorSpeed(0);
            DisableButtonAdvance();
            DisableButtonWardrobe();
            EnableButtonInspect();
            SetState(Inspection);
        }
        break;

    case Inspecting:
    {
        bool notGood = WardrobeMalfunction();
        
        if (mStateTime <= 1.0)
        {
            Say(L"Inspecting");
        }
        
        else
        {
            if (notGood)
            {
                Say(L"");
                SetConveyorSpeed(-1);
                SetState(MoveToWardrobe);
            }
            else
            {
                Say(L"Passed");
                if (mStateTime >= 2.0)
                {
                    SetConveyorSpeed(1);
                }
            }

            DisableButtonInspect();
        
        }

        if (GetTurkeyPosition() >= 4.99)
        {
            Say(L"");
            SetConveyorSpeed(0);
            NextTurkey();
            SetState(Idle);
        }
    }
    break;

    default:
        break;
    }
}



/**
* Indication that the Next Turkey button has been pressed
*
* This function is called whenever the Next On List button is pressed.
* It is only called if the button is enabled.
*/
void CController::OnNextPressed()
{
    switch (mState)
    {
    case Idle:
        NextTurkey();
        SetConveyorSpeed(1);   // Positive values move to the right
        SetState(MoveToWardrobe);
        break;

    default:
        break;
    }
}


/**
* Indication that the Advance button has been pressed
*
* This function is called whenever the Advance button is pressed.
* It is only called if the button is enabled.
*/
void CController::OnAdvancePressed()
{
    switch (mState)
    {

    case Wardrobe:
        SetConveyorSpeed(1);   // Positive values move to the right
        SetState(MoveToInspection);
        break;

    default:
        break;

    }
}


/**
* Indication that a Wardrobe button has been pressed
* \param item The item that was selected
*/
void CController::OnWardrobePressed(CKitchenController::Wardrobe item)
{
    mClothes = item;
    switch (mState)
    {
    case Wardrobe:
        if (!HasClothing(mClothes))
        {
            DressTurkey(mClothes);
        }
        else
        {
            UndressTurkey(mClothes);
        }

        WardrobeDone();
        
        break;

    default:
        break;
    }
}

/**
* Called when the Turkey has been dressed in a clothing item
*
* The process is started by a call to DressTurkey() or UndressTurkey()
* This function is called when the process is complete.
*/
void CController::WardrobeDone()
{
    switch (mState)
    {
    case Wardrobe:
        break;

    default:
        break;
    }
}



/**
* Indication that the Inspect button has been pressed
*
* This function is called whenever the Inspect button is pressed.
* It is only called if the button is enabled.
*/
void CController::OnInspectPressed()
{
    switch (mState)
    {
    case Inspection:
        SetState(Inspecting);
        break;

    default:
        break;
    }
}