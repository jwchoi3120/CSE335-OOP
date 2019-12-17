/**
 * \file TimelineDlg.h
 *
 * \author Charles B. Owen
 *
 * The timeline parameters dialog box.
 */

#pragma once

class CTimeline;


/**
 * The timeline parameters dialog box.
 */
class CTimelineDlg : public CDialog
{
	DECLARE_DYNAMIC(CTimelineDlg)

public:
	/** \param pParent
	*/
	CTimelineDlg(CWnd* pParent = NULL);   // standard constructor
	/** destructor
	*/
	virtual ~CTimelineDlg();

    /// Dialog box Id
	enum { IDD = IDD_TIMELINEDLG };
	/** \param timeline
	*/
    void SetTimeline(CTimeline *timeline);
    /** take
	*/
	void Take();

protected:
	/** \param pDX
	*/
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

private:
    int mNumFrames;     ///< Number of frames in the animation
    int mFrameRate;     ///< Animation frame rate in frames per second

    /// The timeline we are editing
    CTimeline *mTimeline = nullptr;
};
