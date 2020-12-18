#include "../base/icode.hpp"
class L117 : public icode
{
public:
	void run() {
        print_res(connect_DFS(create_tree<int, Node>({1,2,3,4,5,-1,7})));
    }

    Node* connect_DFS(Node* root) {
        if (!root) return NULL;
        Node* p = root->next;
        while (p) {
            if (p->left) {
                p = p->left;
                break;
            }
            if (p->right) {
                p = p->right;
                break;
            }
            p = p->next;
        }
        if (root->right) root->right->next = p;
        if (root->left) root->left->next = root->right ? root->right : p;
        connect_DFS(root->right);
        connect_DFS(root->left);
        return root;
    }

    Node* connect_iter(Node* root) {
        Node *dummy = new Node(0, NULL, NULL, NULL), *cur = dummy, *head = root;
        while (root) {
            for (auto i: {root->left, root->right}) 
                if(i){
                    cur->next = i;
                    cur = cur->next;
                }
            
            root = root->next;
            if (!root) {
                cur = dummy;
                root = dummy->next;
                dummy->next = NULL;
            }
        }
        return head;
    }
};