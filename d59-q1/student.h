#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::insert(iterator position, iterator first, iterator last)
{
    size_t other_size = last - first;
    long long pos = position - begin();
    ensureCapacity(mSize + other_size);

    for (size_t i = mSize - 1; i >= pos && i <= mSize - 1; i--)
    {
        mData[i + other_size] = mData[i];
    }
    for (size_t i = 0; i < other_size; i++)
    {
        mData[i + pos] = *(first + i);
    }

    mSize += other_size;
}

#endif
