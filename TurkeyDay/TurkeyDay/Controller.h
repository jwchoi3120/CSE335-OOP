/**
 * \file Controller.h
 *
 * \author Charles Owen
 *
 * Main controller for the Turkey Day system
 */

#include "KitchenController.h"

#pragma once

/**
 * Main controller for the Turkey Day system
 */
class CController :
    public CKitchenController
{
public:
    CController();
    virtual ~CController();
    ///states
    enum States { Idle, MoveToWardrobe, Wardrobe, MoveToInspection, Inspection, Inspecting};
    virtual void Initialize() override;
    virtual void Service() override;

	virtual void OnNextPressed() override;
	virtual void OnAdvancePressed() override;
	virtual void OnWardrobePressed(CKitchenController::Wardrobe item) override;
	virtual void WardrobeDone() override;
	virtual void OnInspectPressed() override;
private:
    ///states
    States mState = Idle;   ///< The current state
    /** \param state
    */
    void SetState(States state); ///sets state \param state
    ///clothes
    CKitchenController::Wardrobe mClothes;
    ///statetime
    double mStateTime = 0;
};

