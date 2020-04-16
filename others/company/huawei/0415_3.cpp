/*
5 2 3 1 0 0
1 20 2 3
2 30 3 4 5
3 50 4
4 60
5 80
*/
#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int id;
    int cost;
    vector<node*> outs;
};

int maxC = 0;

bool dfs(vector<node*> nodes, int cur, vector<bool> vis)
{
    if (nodes.empty())
        maxC = max(maxC, cur);
    else
    {
        for (auto item : nodes)
        {
            if (vis[item->id-1]) {
                return false;
            }
            vis[item->id-1] = true;
            if(dfs(item->outs, cur + item->cost, vis)) {
                vis[item->id-1] = false;
            } else
            {
                return false;
            }
            
        }
    }
    return true;
}

int main()
{
    int N, i = 0, j = 0, temp;
    cin >> N;
    vector<node*> nodes;
    vector<int> out_size(N, 0);
    while (i < N)
    {
        cin >> out_size[i];
        node* tn = new node;
        tn->id = i++;
        nodes.push_back(tn);
    }
    i = 0;
    while (i < N)
    {
        cin >> nodes[i]->id;
        cin >> nodes[i]->cost;
        j = 0;
        while (j < out_size[i])
        {
            cin >> temp;
            if (temp > N)
            {
                cout << "NA" << endl;
                return 0;
            }
            nodes[i]->outs.push_back(nodes[temp - 1]);
            ++j;
        }
        ++i;
    }
    vector<bool> vis(N, false);
    if (dfs(nodes, 0, vis))
        cout << maxC << endl;
    else{
        cout << "Q" << endl;
    }
        
    return 0;
}