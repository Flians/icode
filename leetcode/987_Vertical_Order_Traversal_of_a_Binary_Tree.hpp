#include "../base/icode.hpp"
class L987 : public icode
{
public:
	void run() {}

    void rec(TreeNode* cur,int hd,int height, map<int,vector<pair<int,int>>> &m){
        m[hd].push_back({(cur->val),height});
        
        if(cur->left!=nullptr){
            rec(cur->left,hd-1,height+1,m);
        }
        
        if(cur->right!=nullptr){
            rec(cur->right,hd+1,height+1,m);
        }
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> m;
        rec(root,0,0,m);
        vector<vector<int>> res;
        for(auto it:m){
            sort(it.second.begin(),it.second.end(),[&](pair<int, int> &a, pair<int, int> &b){
                return a.second == b.second ? a.first < b.first : a.second < b.second;
            });
            vector<int> item;
            for (auto it1:it.second){
                item.push_back(it1.first);
            }
            res.push_back(item);
        }
        return res;
    }
};