#ifndef _ICODE_H_
#define _ICODE_H_

#include <bits/stdc++.h>

using namespace std;

static auto fast = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
};

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinaryMatrix
{
public:
    int get(int x, int y);
    vector<int> dimensions();
};

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class icode
{
private:
    /* data */
public:
    virtual void run() = 0;

    template <typename T>
    void print_res(vector<T> data);
    template <typename T>
    void print_res(vector<vector<T> > data);
};

template <typename T>
void icode::print_res(vector<T> data)
{
    for (auto i : data)
    {
        cout << i << " ";
    }
    cout << endl;
}

template <typename T>
void icode::print_res(vector<vector<T> > data)
{
    for (auto ip : data)
    {
        this->print_res(ip);
    }
}

#endif