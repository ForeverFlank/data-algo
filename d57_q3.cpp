#include <iostream>

using namespace std;

struct node
{
    int val;
    node *prev = nullptr;
    node *next = nullptr;
};

int main()
{
    int n, k, v;
    cin >> n >> k >> v;

    node *head = new node();
    node *p = head;
    for (int i = 0; i < n; i++)
    {
        node *p_new = new node();
        p_new->prev = p;
        p->next = p_new;
        cin >> p_new->val;
        p = p->next;
    }

    p = head;
    for (int i = 0; i < k; i++) p = p->next;
    node* curr = new node();
    curr->val = v;
    p->next->prev = curr;
    curr->prev = p;
    curr->next = p->next;
    p->next = curr;

    while (curr != nullptr)
    {
        int count = 1;
        node *r = curr->next;
        while (r != nullptr && r->val == curr->val)
        {
            count++;
            r = r->next;
        }
        node *l = curr->prev;
        while (l != nullptr && l != head && l->val == curr->val)
        {
            count++;
            l = l->prev;
        }

        if (count < 3) break;

        l->next = r;
        if (r != nullptr)
        {
            r->prev = l;
        }
        curr = l;
    }

    p = head->next;
    while (p != nullptr)
    {
        cout << p->val << " ";
        p = p->next;
    }

    return 0;
}