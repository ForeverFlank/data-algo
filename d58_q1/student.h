#ifndef __STUDENT_H_
#define __STUDENT_H_


template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos)
{
    if (pos.size() == 0) return;
    size_t offset = 0;
    for (auto &x : pos) erase(begin() + x - offset++);
}

#endif
