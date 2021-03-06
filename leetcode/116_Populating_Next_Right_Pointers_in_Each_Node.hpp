#include "../base/icode.hpp"
class L116 : public icode
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return root;
        queue<Node *> record;
        record.push(root);
        while (!record.empty())
        {
            Node *temp = record.front();
            int len = record.size();
            while (len--)
            {
                record.pop();
                if (len == 0)
                {
                    temp->next = NULL;
                }
                else
                {
                    temp->next = record.front();
                }
                if (temp->left)
                    record.push(temp->left);
                if (temp->right)
                    record.push(temp->right);
                temp = record.front();
            }
        }
        return root;
    }

    void run()
    {
       // [1,#,2,3,#,4,5,6,7,#]
       print_res(connect(create_tree<Node>({1,2,3,4,5,6,7})));
    }
};