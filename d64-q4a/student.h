#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls)
{
  auto it = ls.begin();
  while (it != ls.end())
  {
    auto &curr = *it;

    if (curr.mSize > 0)
    {
      mHeader->prev->next = curr.mHeader->next;
      curr.mHeader->next->prev = mHeader->prev;
      
      curr.mHeader->prev->next = mHeader;
      mHeader->prev = curr.mHeader->prev;
      
      mSize += curr.mSize;
      
      curr.mHeader->next = curr.mHeader;
      curr.mHeader->prev = curr.mHeader;
      curr.mSize = 0;
    }
    
    it++;
  }
}

#endif
