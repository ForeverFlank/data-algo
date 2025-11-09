#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T, typename Comp >
T CP::priority_queue<T, Comp>::get_kth(size_t k) const
{
    if (k == 3)
    {
        T m1 = mData[0], m2 = mData[1], m3 = mData[2];
        if (mLess(m1, m2)) std::swap(m1, m2);
        if (mLess(m1, m3)) std::swap(m1, m3);
        if (mLess(m2, m3)) std::swap(m2, m3);
        for (size_t i = 2; i < mSize; i++)
        {
            T d = mData[i];
            if (mLess(m1, d))
            {
                m3 = m2;
                m2 = m1;
                m1 = d;
            }
            else if (mLess(m2, d))
            {
                m3 = m2;
                m2 = d;
            }
            else if (mLess(m3, d))
            {
                m3 = d;
            }
        }
        return m3;
    }
    if (k == 2)
    {
        T m1 = mData[0], m2 = mData[1];
        if (mLess(m1, m2)) std::swap(m1, m2);
        for (size_t i = 1; i < mSize; i++)
        {
            T d = mData[i];
            if (mLess(m1, d))
            {
                m2 = m1;
                m1 = d;
            }
            else if (mLess(m2, d))
            {
                m2 = d;
            }
        }
        return m2;
    }
    return mData[0];
}

#endif
