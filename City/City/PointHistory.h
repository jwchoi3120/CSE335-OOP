/**
* \file PointHistory.cpp
*
* \author Charles Owen
*
* Class that maintains a collection of Point objects in order.
*/

#pragma once
#include <memory>
#include <random>


/**
 * Class that maintains a collection of Point objects in order.
 */
class CPointHistory
{
public:
    CPointHistory();
    virtual ~CPointHistory();

    void Add(Gdiplus::Point p);


protected:
    /**
    * Nested class that stores up to five points in a bin.
    */
    class PointBin
    {
    public:
        PointBin(int max);
        virtual ~PointBin();

        /// Get the current count of items in this bin
        /// \return Count (zero to MaxPoints)
        int GetCnt() { return mCnt; }

        /// Get the maximum points we allow in this bin
        /// \return Maximum integer value
        int GetMax() { return mMax; }

        bool Add(Gdiplus::Point point);

        /// Get a stored point
        /// \param i Index to the point (0 to mCnt-1)
        /// \return Stored point value
        Gdiplus::Point Get(int i) { return mPoints[i]; }

        /// Get the next bin in the list
        /// \return Pointer to next bin or null if none
        std::shared_ptr<PointBin> GetNext() { return mNext; }

        /// Set the next bin in the list
        /// \param next Next pointer to set
        void SetNext(std::shared_ptr<PointBin> next) { mNext = next; }
	
    private:
        PointBin() = delete;

        /// Array to store the points
        Gdiplus::Point *mPoints;

        /// Maximum number of elements we can store in the array
        int mMax;

        /// Number of elements currently stored in array
        int mCnt = 0;

        /// Next bin
        std::shared_ptr<PointBin> mNext;
    };


    /// Pointer to the head of the linked list of bins
    std::shared_ptr<PointBin> mHead;

private:
    int MakeSize();


    /// Random number generator
    std::mt19937 mGen;

    /// Pointer to the tail of the linked list of bins (last node)
    std::shared_ptr<PointBin> mTail;

public:
	/**
	* class of iterator
	*/
	class Iter
	{
	public:
		/** constructor 
		* \param track
		* \param bin
		* \param position
		*/
		Iter(CPointHistory* track, int position, std::shared_ptr<PointBin> bin) : mMouseHistory(track), mPointBin(bin), mPos(position) {}
		/** operator not equal
		* \param compare
		* \return true or false
		*/
		bool operator != (const Iter& compare) const
		{
			return mPos != compare.mPos || mPointBin != compare.mPointBin;
		}
		/** pointer 
		* \return Point
		*/
		Gdiplus::Point operator* () const { return mPointBin->Get(mPos); }
		/** adding one to interate through
		* \return *this
		*/
		const Iter& operator++()
		{
			if (mPos == mPointBin->GetCnt() - 1)
			{
				mPointBin = mPointBin->GetNext();
				mPos = 0;
				return *this;
			}
			else
			{
				mPos++;

				return *this;
			}
		}

	private:
		/** member of mouse history*/
		CPointHistory* mMouseHistory;
		/**bin that stores points*/
		std::shared_ptr<PointBin> mPointBin;
		/** position*/
		int mPos = 0;
	};
	/** begin 
	* \return Iter(this, 0, mHead)
	*/
	Iter begin() { return Iter(this, 0, mHead); }
	/** end
	* \return Iter(this, 0, nullptr)
	*/
	Iter end() { return Iter(this, 0, nullptr); }
};