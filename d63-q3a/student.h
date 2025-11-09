#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <iostream>


template <typename T>
void CP::queue<T>::move_to_back(size_t pos)
{
  T item = mData[(mFront + pos) % mCap];
  for (size_t i = pos; i < mSize; i++)
  {
    mData[(mFront + i) % mCap] = mData[(mFront + i + 1) % mCap];
  }
  mData[(mFront + mSize - 1) % mCap] = item;
}

#endif
