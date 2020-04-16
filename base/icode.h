#ifndef _ICODE_H_
#define _ICODE_H_

#include<bits/stdc++.h>

using namespace std;

static auto fast = [](){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class icode
{
private:
    /* data */
public:
    icode(/* args */);
    ~icode();
    virtual void run(){};

    void print_res(vector<int> data)
    {
        for (auto i : data)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    void print_res(vector<vector<int>> data)
    {
        for (auto ip : data)
        {
            this->print_res(ip);
        }
    }
};

icode::icode(/* args */)
{
}

icode::~icode()
{
}

#endif