#include <iostream>
using namespace std;

struct TreeNode {
    TreeNode *l, *r;
    int item;

    TreeNode(int item) {
        this->item = item;
        l = nullptr;
        r = nullptr;
    }
};

int main() {
    TreeNode* root = new TreeNode(4);
    root->l = new TreeNode(20);
    root->r = new TreeNode(6);
    root->r->l = new TreeNode(9);
    
    cout << root->item << endl;
    cout << root->l->item << endl;
    cout << root->r->item << endl;
    cout << root->r->l->item;

    return 0;
}

