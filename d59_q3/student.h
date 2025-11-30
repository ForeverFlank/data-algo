#ifndef __STUDENT_H_
#define __STUDENT_H_

template<
    typename KeyT,
    typename MappedT,
    typename CompareT>
CP::map_bst<KeyT, MappedT, CompareT> CP::map_bst<KeyT, MappedT, CompareT>::split(KeyT val)
{
    node *p = mRoot;
    while (p != nullptr)
    {
        std::cout << val << " -- " << p->data.first << "\n";
        if (mLess(p->data.first, val))
        {
            p = p->left;
        }
        else
        {
            if (p != mRoot)
            {
                node *parent = p->parent;
                parent->left = p->right;
            }
            else
            {
                mRoot = p->right;
            }
            p = p->right;
        }
    }

    CP::map_bst<KeyT, MappedT, CompareT> result;
    return result;
}

#endif
