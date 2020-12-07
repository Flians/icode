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
    ListNode *create_list(vector<T> nums);

    template <typename T, typename C>
    C *create_tree(vector<T> nums);

    template <typename T>
    Node *create_BPlusTree(vector<T> nums);

    void print_res(ListNode *root);

    void print_res(TreeNode *root);

    void print_res(Node *root);

    template <typename T>
    void print_res(vector<T> data);
    template <typename T>
    void print_res(vector<vector<T>> data);
};

template <typename T>
ListNode *icode::create_list(vector<T> nums)
{
    ListNode *root = NULL;
    if (nums.empty())
    {
        return root;
    }
    root = new ListNode(nums[0]);
    ListNode *tmp = root;
    for (size_t i = 1; i < nums.size(); ++i)
    {
        tmp->next = new ListNode(nums[i]);
        tmp = tmp->next;
    }
    return root;
}

template <typename T, typename C>
C *icode::create_tree(vector<T> nums)
{
    C *root = NULL;
    if (nums.empty())
    {
        return root;
    }
    root = new C(nums[0]);
    queue<C *> level;
    level.push(root);
    size_t i = 1;
    while (!level.empty() && i < nums.size())
    {
        C *tmp = level.front();
        if (nums[i] != INT_MIN)
        {
            tmp->left = new C(nums[i]);
            level.push(tmp->left);
        }
        i++;
        if (i < nums.size() && nums[i] != INT_MIN)
        {
            tmp->right = new C(nums[i]);
            level.push(tmp->right);
        }
        i++;
        level.pop();
    }
    return root;
}

template <typename T>
Node *icode::create_BPlusTree(vector<T> nums)
{
    Node *root = NULL;
    if (nums.empty())
    {
        return root;
    }
    root = new Node(nums[0]);
    queue<Node *> level;
    level.push(root);
    size_t i = 1;
    while (!level.empty() && i < nums.size())
    {
        int len = level.size();
        Node *last = NULL;
        while (len-- && i < nums.size())
        {
            Node *tmp = level.front();
            if (!tmp->left)
            {
                if (last)
                {
                    last->next = tmp;
                }
                else
                {
                    last = tmp;
                }
                tmp->left = new Node(nums[i++]);
                level.push(tmp->left);
            }
            else
            {
                tmp->right = new Node(nums[i++]);
                tmp->left->next = tmp->right;
                level.push(tmp->right);
                level.pop();
            }
        }
    }
    return root;
}

void icode::print_res(ListNode *root)
{
    while (root)
    {
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;
}

void icode::print_res(TreeNode *root)
{
    queue<TreeNode *> level;
    level.push(root);
    while (!level.empty())
    {
        TreeNode *tmp = level.front();
        cout << tmp->val << " ";
        if (tmp->left)
        {
            level.push(tmp->left);
        }
        if (tmp->right)
        {
            level.push(tmp->right);
        }
        level.pop();
    }
    cout << endl;
}

void icode::print_res(Node *root) {
    queue<Node *> level;
    level.push(root);
    while (!level.empty())
    {
        Node *tmp = level.front();
        cout << tmp->val << " ";
        if (!tmp->next) {
            cout << "# ";
        }
        if (tmp->left)
        {
            level.push(tmp->left);
        }
        if (tmp->right)
        {
            level.push(tmp->right);
        }
        level.pop();
    }
    cout << endl;
}

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
void icode::print_res(vector<vector<T>> data)
{
    for (auto ip : data)
    {
        this->print_res(ip);
    }
}

#endif