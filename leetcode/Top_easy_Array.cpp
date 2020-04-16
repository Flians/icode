#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int num = 0, i=1;
    for(;i < nums.size(); i++)
    {
        if(nums[i]==nums[i-1])
        {
            nums.erase(nums.begin()+i);
        }
    }
    return nums.size();
}

int maxProfit(vector<int>& prices) {
    int sum=0, i=0, j=0;
    for(;i<prices.size();i++)
    {
        for(j=i+1;j<prices.size();j++)
        {
            if(prices[j] < prices[j-1])
                break;
        }
        sum += prices[j-1] - prices[i];
        i = j-1;
    }
    return sum;
}

void rotate(vector<int>& nums, int k) {
    while(k--)
    {
        nums.insert(nums.begin(),nums.back());
        nums.pop_back();
    }
}

bool containsDuplicate(vector<int>& nums) {
    unsigned old_len = nums.size();
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    if(old_len > nums.size())
        return true;
    else
        return false;
}

int singleNumber(vector<int>& nums) {
    int i = 0, result=0;
    for(;i<nums.size();i++)
    {
        result ^= nums[i];
    }
    return result;
}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int v1=0,v2=0;
    vector<int> nums;
    while(v1 < nums1.size() && v2 < nums2.size())
    {
        if(nums1[v1]>nums2[v2])
            v2++;
        else if(nums1[v1]<nums2[v2])
            v1++;
        else
        {
            v1++;
            v2++;
            nums.push_back(nums1[v1]);
        }
    }
    return nums;
}

vector<int> plusOne(vector<int>& digits) {
    int i=digits.size()-1;
    for(;i>=0;i--)
    {
        if(digits[i]<9)
        {
            digits[i]++;
            return digits;
        } else
        {
            digits[i] = 0;
        }
    }
    vector<int> new_digits(digits.size()+1,0);
    new_digits[0]=1;
    return new_digits;
}

void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    int i=n-1, j=n-1;
    for(; i>=0; i--)
    {
        if(nums[i]==0)
        {
            for(j=i+1; j<n && nums[j]!=0 ;j++)
            {
                nums[j-1] = nums[j-1] + nums[j];
                nums[j] = nums[j-1] - nums[j];
                nums[j-1] = nums[j-1] - nums[j];
            }
        }
    }
}

vector<int> twoSum(vector<int>& nums, int target) {
    int i=0;
    vector<int> indices;
    /*
    for(;i<(int)nums.size();i++)
    {
        for(int j=i+1;j<(int)nums.size();j++)
        {
            if(nums[i]+nums[j] == target)
            {
                indices.push_back(i);
                indices.push_back(j);
            }
        }
    }
    */
    map<int,int> hash;
    int temp=0;
    for(i=0; i<(int)nums.size(); i++)
    {
        temp=target-nums[i];
        if(hash.count(temp) > 0)
        {
            indices.push_back(hash[temp]);
            indices.push_back(i);
            break; 
        }else
        {
            hash[nums[i]] = i;
        }
    }
    return indices;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {
    ListNode* temp = node->next;
    *node = *temp;
    delete temp;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* pre = head;
    ListNode* begin=head; 
    ListNode* end=head;
    while(n--)
    {
        end = end->next;
    }
    while(end != NULL)
    {
        pre = begin;
        begin = begin->next;
        end = end->next;
    }
    if(head == begin)
    {
        head = begin->next;
    } else if(begin->next == NULL)
    {
        pre->next = NULL;
    } else{
        pre->next = begin->next;
    }
    delete begin;
    return head;
}

ListNode* reverseList(ListNode* head) {
    ListNode* pre = head;
    ListNode* next = head;
    ListNode* new_head = NULL;
    while(pre!=NULL)
    {
        next = pre->next;
        pre->next = new_head;
        new_head = pre;
        pre = next;
    }
    return new_head;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* new_node = new ListNode(0);
    ListNode* temp=new_node;
    while(l1!=NULL || l2!=NULL)
    {
        if(l1==NULL)
        {
            temp->next=l2;
            break;
        }
        if(l2==NULL)
        {
            temp->next=l1;
            break;
        }
        if(l1->val<=l2->val)
        {
            temp->next=l1;
            l1=l1->next;
        }else
        {
            temp->next=l2;
            l2=l2->next;
        }
        temp = temp->next;
    }
    return new_node->next;
}



// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print_right(TreeNode* root) {
    queue<TreeNode*> nodes;
    TreeNode* temp;
    nodes.push(root);
    nodes.push(new TreeNode(INT_MAX));
    while(!nodes.empty())
    {
        temp = nodes.front();
        nodes.pop();
        nodes.push(temp->left);
        nodes.push(temp->right);
        if(temp->val == INT_MAX)
        {
            nodes.push(new TreeNode(INT_MAX));
            cout << temp->val << endl;
        }
    }
}

int maxDepth(TreeNode* root) {
    if(root == NULL)
        return 0;
    
    /*
    // recursively
    return 1+max(maxDepth(root->left), maxDepth(root->right));
    */
    
    /*
    //dfs
    stack<TreeNode*> nodes;
    stack<int> deeps;
    int deepth = 0;
    nodes.push(root);
    deeps.push(1);
    while(!nodes.empty())
    {
        TreeNode* temp_node = nodes.top();
        nodes.pop();
        int temp_deep = deeps.top();
        deeps.pop();
        deepth = max(temp_deep, deepth);
        if(temp_node->left!=NULL)
        {
            nodes.push(temp_node->left);
            deeps.push(temp_deep+1);
        }
        if(temp_node->right!=NULL){
            nodes.push(temp_node->right);
            deeps.push(temp_deep+1);
        }
    }
    return deepth;
    */
    
    //bfs
    queue<TreeNode*> nodes;
    int deepth=0;
    nodes.push(root);
    while(!nodes.empty())
    {
        int width = nodes.size();
        while(width--)
        {
            TreeNode* temp_node = nodes.front();
            nodes.pop();
            if(temp_node->left!=NULL)
            {
                nodes.push(temp_node->left);
            }
            if(temp_node->right!=NULL){
                nodes.push(temp_node->right);
            }
        }
        deepth++;
    }
    return deepth;
}

bool isValidBST(TreeNode* root, TreeNode* minn, TreeNode* maxn) {
    if(root==NULL)
        return true;
    
    if(minn && root->val <= minn->val || maxn && root->val >= maxn->val)
        return false;
    return isValidBST(root->left, minn, root) && isValidBST(root->right, root, maxn);
}

bool isSymmetric(TreeNode* root) {
    if(root == NULL)
        return true;
    return isSymmetric(root->left, root->right);
}

bool isSymmetric(TreeNode* left, TreeNode* right) {
    if(!left && !right)
        return true;
    if(!left || !right)
        return false;
    if(left->val != right->val)
        return false;
    return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
}

int main(){
    int a[] = {1,1,1,3,3,4,3,2,4,2};
    vector<int> ilist(a, a+10);
    containsDuplicate(ilist);
    return 0;
}