#include "../base/icode.hpp"
class L841 : public icode
{
public:
    void run()
    {
        cout << canVisitAllRooms({{1}, {2}, {3}, {}}) << " true" << endl;
        cout << canVisitAllRooms({{1, 3}, {3, 0, 1}, {2}, {0}}) << " false" << endl;
    }

    bool canVisitAllRooms(vector<vector<int>> &&rooms)
    {
        std::size_t n = rooms.size();
        std::vector<bool> visited(n, 0);
        visited[0] = 1;
        std::queue<int> keys;
        for (auto next : rooms[0])
            keys.push(next);
        while (!keys.empty())
        {
            if (n == 0)
                break;
            int cur = keys.front();
            keys.pop();
            if (!visited[cur])
            {
                --n;
                visited[cur] = 1;
                for (auto next : rooms[cur])
                {
                    if (!visited[next])
                        keys.push(next);
                }
            }
        }
        return n == 1;
    }
};