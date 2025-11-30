#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>

template <typename T>
void CP::queue<T>::move_to_front(size_t pos)
{
    if (pos == 0) return;
    
    T item = mData[(mFront + pos) % mCap];
    // std::cout << item << "  ";
    for (size_t i = pos - 1; i <= pos - 1; i--)
    {
        // std::cout << i + 1 << " <- " << i << "\n";
        mData[(mFront + i + 1) % mCap] = mData[(mFront + i) % mCap];
    }
    mData[mFront % mCap] = item;
}

#endif
