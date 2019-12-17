/**
 * \file Floor.h
 *
 * \author Tom Choi
 *
 * 
 */

#pragma once


class CController;

/**
 * floor class
 */
class CFloor
{
public:
    /** setup
    */
    void SetUp(bool t);
    /** setdown
    */
    void SetDown(bool t);
    /** setpanel
    */
    void SetPanel(bool t);
    /** setfloor \param floor
    */
    void SetFloor(int floor) { mFloor = floor; }

    /** \return mUp
    */
    bool IsUp() { return mUp; }
    /** \return mDown
    */
    bool IsDown() { return mDown; }
    /** \return mPanel
    */
    bool IsPanel() { return mPanel; }
    /** \return mFloor
    */
    int GetFloor() { return mFloor; }

    /** \param control
    */
    void SetController(CController* control) { mController = control; }
private:
    ///mUp
    bool mUp = false;
    ///mDown
    bool mDown = false;
    ///mPanel
    bool mPanel = false;
    ///mFloor
    int mFloor = 0;
    CController* mController = nullptr;   ///< Controller for this object
};

