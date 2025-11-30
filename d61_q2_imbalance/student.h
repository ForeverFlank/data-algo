// Your code here

int traverse_height(node *p, int &max_imbalance, KeyT &res)
{
    if (p == nullptr) return -1;
    int hl = traverse_height(p->left, max_imbalance, res);
    int hr = traverse_height(p->right, max_imbalance, res);
    int imbalance = hl > hr ? hl - hr : hr - hl;
    if (imbalance > max_imbalance)
    {
        max_imbalance = imbalance;
        res = p->data.first;
    }
    else if (imbalance == max_imbalance)
    {
        res = mLess(res, p->data.first) ? res : p->data.first;
    }
    return 1 + std::max(hl, hr);
}

KeyT getValueOfMostImbalanceNode()
{
    int max_imbalance = 0;
    KeyT res = mRoot->data.first;
    traverse_height(mRoot, max_imbalance, res);
    return res;
}
