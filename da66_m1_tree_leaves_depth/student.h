#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "map_bst.h"

template <typename KeyT, typename MappedT, typename CompareT>
long long CP::map_bst<KeyT, MappedT, CompareT>::my_recur(node* n, size_t aux) {
    bool l = n->left == nullptr;
    bool r = n->right == nullptr;
    size_t res = 0;
    if (!l) res += my_recur(n->left, aux + 1);
    if (!r) res += my_recur(n->right, aux + 1);
    return l && r ? aux : res;
}

template <typename KeyT, typename MappedT, typename CompareT>
long long CP::map_bst<KeyT, MappedT, CompareT>::sum_leaves_depth() {
  if (mRoot == nullptr) return 0;
  return my_recur(mRoot, 0);
}

#endif
