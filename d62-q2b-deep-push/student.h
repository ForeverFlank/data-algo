#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::stack<T>::deep_push(size_t pos, const T &value)
{
  ensureCapacity(mSize + 1);
  mSize++;
  for (size_t i = 0; i < pos; i++)
  {
    mData[mSize - i - 1] = mData[mSize - i - 2]; 
  }
  mData[mSize - pos - 1] = value;
}

#endif
