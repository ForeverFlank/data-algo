#ifndef __STUDENT_H_
#define __STUDENT_H_
#include <algorithm>

template <typename T>
void CP::list<T>::merge(CP::list<CP::list<T>> &ls)
{
  auto it = ls.begin();
  while (it != ls.end())
  {        
    mHeader->prev->next = it->mHeader->next;
    it->mHeader->next->prev = mHeader->prev;
    
    it->mHeader->prev->next = mHeader;
    mHeader->prev = it->mHeader->prev;
    
    mSize += it->mSize;
    it->mHeader = NULL;
    it++;
  }
}

#endif
