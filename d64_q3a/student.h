#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T, typename Comp >
T CP::priority_queue<T, Comp>::get_kth(size_t k) const
{
    size_t max_size = (1 << k) - 1;
    size_t size = std::min(mSize, max_size);
    T arr[size];
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = mData[i];
    }
    std::sort(arr, arr + size, mLess);
    return arr[size - k];
}

#endif
