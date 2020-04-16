#include <iostream>
#include <queue>
#include <cmath>

using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print_right(TreeNode* root) {
    queue<TreeNode*> nodes;
    TreeNode* pre;
    nodes.push(root);
    // flag
    nodes.push(new TreeNode(INT_MAX));
    while(!nodes.empty())
    {
        TreeNode* temp = nodes.front();
        nodes.pop();
        if(temp->left!=NULL)
        {
            nodes.push(temp->left);
        }
        if(temp->right!=NULL){
            nodes.push(temp->right);
        }
        // determine if this row is end
        if(temp->val == INT_MAX)
        {
            if(!nodes.empty())
                nodes.push(new TreeNode(INT_MAX));
            cout << pre->val << endl;
        }
        pre = temp;
    }
}

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(7);
    root->left->right->left = new TreeNode(4);
    print_right(root);
    return 0;
}