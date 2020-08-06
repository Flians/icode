#include "../base/icode.hpp"
class L207 : public icode
{
public:
	void run() {
        vector<vector<int>> prerequisites = {{1,0}, {0,1}};
        cout << canFinish(2, prerequisites) << " false" << endl;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto &item : prerequisites) {
            graph[item[0]].push_back(item[1]);
            ++indegree[item[1]];
        }
        int no_num = 0;
        queue<int> no_in;
        for (int i = 0; i < numCourses; ++i)
        {
            if (indegree[i] == 0) {
                ++no_num;
                no_in.push(i);
                indegree[i] = -1;
            }
        }
        while(!no_in.empty()) {
            for (auto &out : graph[no_in.front()]) {
                --indegree[out];
            }
            for (int i = 0; i < numCourses; ++i)
            {
                if (indegree[i] == 0) {
                    ++no_num;
                    no_in.push(i);
                    indegree[i] = -1;
                }
            }
            no_in.pop();
        }
        return no_num == numCourses;
    }
};