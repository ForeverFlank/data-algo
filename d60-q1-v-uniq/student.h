#ifndef __STUDENT_H_
#define __STUDENT_H_

//you can include any other file here
//you are allow to use any data structure
#include <unordered_set>

template <typename T>
void CP::vector<T>::uniq()
{
    std::unordered_set<T> s;
    size_t i = 0, j = 0;
    for (; i < mSize; i++)
    {
        if (s.find(mData[i]) == s.end())
        {
            mData[i - j] = mData[i];
            s.insert(mData[i]);
        }
        else
        {
            j++;
        }
    }
    mSize = i - j;
}

#endif
