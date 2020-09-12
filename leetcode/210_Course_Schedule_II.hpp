#include "../base/icode.hpp"
class L210 : public icode
{
public:
	void run() {}

    int find_index(vector<int> &in_degree) {
        int flag = 0;
        for (int i = 0; i < in_degree.size(); ++i) {
            if (in_degree[i] == 0) {
                return i;
            } else if (in_degree[i] == -1) {
                ++flag;
            }
        }
        return flag == in_degree.size() ? -2 : -1;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> in_degree(numCourses, 0);
        for (auto &item : prerequisites) {
            ++in_degree[item[0]];
            graph[item[1]].push_back(item[0]);
        }
        vector<int> res;
        res.reserve(numCourses);
        while(1) {
            int index = find_index(in_degree);
            if (index == -1) {
                vector<int>().swap(res);
                break;
            } else if (index == -2) {
                break;
            } else {
                res.push_back(index);
                in_degree[index] = -1;
                for (auto &it : graph[index]) {
                    --in_degree[it];
                }
            }
        }
        return res;
    }
};