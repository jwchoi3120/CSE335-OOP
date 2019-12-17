/**
 * \file ChildView.h
 *
 * \author Tom Choi
 *
 * Class that implements the child window our program draws in.
 *
 * The window is a child of the main frame, which holds this
 * window, the menu bar, and the status bar.
 */
// ChildView.h : interface of the CChildView class
//

#pragma once

#include "Aquarium.h"

// CChildView window
/**
 * The child window our program draws in.
 */
class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();
private:
	/// An object that describes our aquarium
	CAquarium  mAquarium;
	/// Any item we are currently dragging
	std::shared_ptr<CItem> mGrabbedItem;
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
public:
	///add beta fish
	afx_msg void OnAddfishBetafish();
	/// Initial fish X location
	const int InitialX = 200;

	/// Initial fish Y location
	const int InitialY = 200;
	///click left mouse button down
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	///click left mouse button up
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	///drag fish with mouse
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	///add buddha fish
	afx_msg void OnAddfishBuddha();
	///add neemo fish
	afx_msg void OnAddfishNeemo();
	/**
	*erase the background
	*\param pDC
	*\return FALSE
	*/
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	/**
	* Handler for the add decorcastle As menu option
	*/
	afx_msg void OnAdddecorCastle();
	/**
	* Handler for the File/Save As menu option
	*/
	afx_msg void OnFileSaveas();
	/**
	* This function is called when an File Open menu item is selected.
	*
	* It loads the aquarium from a file.
	*/
	afx_msg void OnFileOpen();

	/// True until the first time we draw
	bool mFirstDraw = true;
	/**
	*	counts the time
	* \param nIDEvent event
	*/
	afx_msg void OnTimer(UINT_PTR nIDEvent);

	long long mLastTime;    ///< Last time we read the timer
	double mTimeFreq;       ///< Rate the timer updates
};

