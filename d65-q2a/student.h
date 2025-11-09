#ifndef __STACK_STUDENT_H__
#define __STACK_STUDENT_H__
#include "stack.h"

template <typename T>
void CP::stack<T>::mitosis(int a, int b)
{
    size_t dup_size = b - a + 1;
    size_t new_size = mSize + dup_size;
    size_t new_cap = mCap;

    if (new_cap < new_size)
    {
        new_cap *= 2;
        expand(new_cap);
    }

    for (size_t i = 0; i <= b; i++)
    {
        if (i < a)
        {
            mData[new_size - i - 1] = mData[mSize - i - 1];
        }
        else if (i <= b)
        {
            size_t diff = i - a;
            mData[new_size - a - 2 * diff - 1] = mData[mSize - i - 1];
            mData[new_size - a - 2 * diff - 2] = mData[mSize - i - 1];
        }
    }
    mSize = new_size;
}

#endif