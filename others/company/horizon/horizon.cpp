#include <vector>
using namespace std;

vector<int> cal_deg(vector<vector<int>> &vertex) {
    vector<int> deg_in(vertex.size(), 0);
    for (auto &item : vertex) {
        for (auto &it : item) {
            ++deg_in[it];
        }
    }
    return deg_in;
}

int find_index(vector<int> &deg_in) {
    int flag = 0;
    for (int i=0; i < deg_in.size(); ++i) {
        if (deg_in[i] == 0)
            return i;
        else if (deg_in[i] == -1) {
            flag++;
        }
    }
    return flag==deg_in.size() ? -2 : -1;
}

vector<int> sort(vector<vector<int>> &vertex) {
    vector<int> deg_in = cal_deg(vertex);
    
    vector<int> res;
    res.reserve(vertex.size());
    while(1) {
        int index = find_index(deg_in);
        if (index == -1)
        {
            vector<int>().swap(res);
            break;
        } else if (index == -2)
        {
            break;
        } else {
            res.push_back(index);
            deg_in[index] = -1;
            for (auto &it : vertex[index]) {
                --deg_in[it];
            }
        }
    }
    return res;
}


