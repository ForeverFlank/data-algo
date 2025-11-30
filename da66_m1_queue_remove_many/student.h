#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <vector>
#include <algorithm>
#include "queue.h"

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos)
{
    size_t pos_size = pos.size();
    if (pos_size == 0) return;
    sort(pos.begin(), pos.end());
    size_t first_pos = pos[0];
    for (size_t i = first_pos, j = 0; i < mSize; i++)
    {
        if (i == pos[j])
        {
            j++;
        }
        else
        {
            mData[(mFront + i - j) % mCap] = mData[(mFront + i) % mCap];
        }
    }
    mSize -= pos_size;
}

#endif
