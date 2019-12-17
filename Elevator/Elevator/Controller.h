/**
 * \file Controller.h
 *
 * \author Tom Choi
 *
 * 
 */

#pragma once
#include "ElevatorController.h"
#include "Floor.h"
/**
 * controller class
 */
class CController :
	public CElevatorController
{
public:
	CController();
	virtual void OnOpenPressed() override;

	/// The state machine states
	enum States { Idle, DoorOpening, DoorOpen, DoorClosing, Moving, Stop };
	virtual void Service() override;
	virtual void OnClosePressed();
	///Initialize
	virtual void Initialize() override;
	/** \param floor
	*/
	virtual void OnPanelFloorPressed(int floor) override;
	virtual void OnCallUpPressed(int floor) override;
	/** \param floor
	*/
	virtual void OnCallDownPressed(int floor) override;
	int WhatFloorToGoTo();
	int WhatFloorUp();
	int WhatFloorDown();
private:
	int    mFloor = 1;      ///< The current floor
	States mState = Idle;   ///< The current state
	void SetState(States state); ///sets state \param state
	double mStateTime = 0;  ///< The time in a current state
	/// An object for each floor
	CFloor mFloors[NumFloors];
	///goingup
	bool mGoingUp = true;
};

