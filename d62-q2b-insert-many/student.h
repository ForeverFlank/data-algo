#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>

template <typename T>
void CP::vector<T>::insert_many(CP::vector<std::pair<int, T>> data)
{
    sort(data.begin(), data.end());

    size_t data_size = data.size();
    size_t j = data_size;
    size_t new_size = mSize + data_size;

    ensureCapacity(new_size);

    for (size_t i = new_size - 1; i <= new_size - 1; i--)
    {
        if (j > 0 && data[j - 1].first == i - j + 1)
        {
            mData[i] = data[j - 1].second;
            j--;
        }
        else
        {
            mData[i] = mData[i - j];
        }
    }
    mSize = new_size;
}

#endif
