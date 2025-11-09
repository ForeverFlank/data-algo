#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
void CP::vector<T>::compress()
{
    mCap = mSize;
    T *arr = new T[mSize]();
    for (size_t i = 0; i < mSize; i++)
    {
        arr[i] = mData[i];
    }
    T *old = mData;
    mData = arr;
    delete old;
}

#endif
