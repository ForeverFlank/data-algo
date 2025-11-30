#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "map_bst.h"

template <typename KeyT, typename MappedT, typename CompareT >
size_t CP::map_bst<KeyT, MappedT, CompareT>::process(node *n)
{
  if (n == nullptr) return 0;
  return 1 + process(n->left) + process(n->right);
}

template <typename KeyT, typename MappedT, typename CompareT >
std::pair<KeyT, MappedT> CP::map_bst<KeyT, MappedT, CompareT>::subtree(map_bst<KeyT, MappedT, CompareT> &left, map_bst<KeyT, MappedT, CompareT> &right)
{
  if (mRoot == nullptr) return std::pair<KeyT, MappedT>();

  left.mRoot = mRoot->left;
  left.mSize = process(mRoot->left);
  if (left.mRoot != nullptr)
    left.mRoot->parent = nullptr;

  right.mRoot = mRoot->right;
  right.mSize = process(mRoot->right);
  if (right.mRoot != nullptr)
    right.mRoot->parent = nullptr;

  mSize = 1;
  mRoot->left = nullptr;
  mRoot->right = nullptr;

  return mRoot->data;
}

#endif

