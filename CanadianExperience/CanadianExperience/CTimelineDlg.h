#pragma once
#include "Timeline.h"

// CTimelineDlg dialog
/**
*dialog
*/
class CTimelineDlg : public CDialog
{
	DECLARE_DYNAMIC(CTimelineDlg)

public:
	/**
	* timelinedlg
	* \param pParent
	*/
	CTimelineDlg(CWnd* pParent = nullptr); 
	///destructor
	virtual ~CTimelineDlg();
	void SetTimeline(CTimeline* timeline);
	void Take();
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TIMELINEDLG };
#endif

protected:
	/**
	* \param pDX
	*/
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	///numframes
	int mNumFrames;
	/// The timeline we are editing
	CTimeline* mTimeline = nullptr;
	///frame rate
	int mFrameRate;
};
