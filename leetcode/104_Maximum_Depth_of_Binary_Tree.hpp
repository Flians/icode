#include "../base/icode.hpp"
class L104 : public icode
{
public:
	void run() {
        vector<int> nums = {2,-1,3,-1,4,-1,5,-1,6};
        cout << maxDepth(create_tree(nums)) << " 5" << endl;
        nums = {3,9,20,-1,-1,15,7};
        cout << maxDepth(create_tree(nums)) << " 3" << endl;
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
};