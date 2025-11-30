#ifndef __STUDENT_H_
#define __STUDENT_H_

template <typename T>
bool CP::vector<T>::block_swap(iterator a, iterator b, size_t m)
{
  if (m <= 0) return false;

  int a_start = a - begin();
  int a_end = a_start + m - 1;
  int b_start = b - begin();
  int b_end = b_start + m - 1;

  if (a_start < 0 ||
      b_start < 0 ||
      a_end >= mSize ||
      b_end >= mSize) return false;

  if (a == b) return false;
  if (a < b && b_start <= a_end) return false;
  if (b < a && a_start <= b_end) return false;

  for (size_t i = 0; i < m; i++)
  {
    std::swap(mData[a_start + i], mData[b_start + i]);
  }

  return true;
}

#endif
