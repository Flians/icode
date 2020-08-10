/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /*
    void verticalTraversal(TreeNode* root, int &index, vector<vector<int>> &res) {
        if (!root)
            return;
        cout << index << endl;
        if (index == 0) {
            vector<int> item;
            item.emplace_back(root->val);
            res.insert(res.begin(), item);
            verticalTraversal(root->left, index, res);
            verticalTraversal(root->right, ++index, res);
        } else if (index >= res.size()) {
            vector<int> item;
            item.emplace_back(root->val);
            res.emplace_back(item);
            verticalTraversal(root->left, --index, res);
            ++index;
            verticalTraversal(root->right, ++index, res);
        } else {
            res[index].emplace_back(root->val);
            verticalTraversal(root->left, --index, res);
            ++index;
            verticalTraversal(root->right, ++index, res);
        }
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int index = 0;
        vector<vector<int> > res;
        verticalTraversal(root, index, res);
        return res;
    }
    */
    map<int,vector<pair<int,int>>> m;
    
    vector<vector<int>> ans;
    
    static bool cmp(pair<int,int>& a,pair<int,int>& b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second<b.second;
    }
    
    void rec(TreeNode* cur,int hd,int height){
        m[hd].push_back({(cur->val),height});
        
        if(cur->left!=nullptr){
            rec(cur->left,hd-1,height+1);
        }
        
        if(cur->right!=nullptr){
            rec(cur->right,hd+1,height+1);
        }
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        rec(root,0,0);
        for(auto it:m){
            sort(it.second.begin(),it.second.end(),cmp);
            vector<int> tans;
            for (auto it1:it.second){
                tans.push_back(it1.first);
            }
            ans.push_back(tans);
        }
        return ans;
    }
};