#include "../base/icode.hpp"
class L1632 : public icode
{
public:
    class UnionFind
    {
    public:
        unordered_map<int, int> parent;
        int Find(int u)
        {
            if (u == parent[u])
                return u;
            return parent[u] = Find(parent[u]);
        }
        void Union(int u, int v)
        {
            if (parent.count(u) == 0)
                parent[u] = u;
            if (parent.count(v) == 0)
                parent[v] = v;
            int pu = Find(u), pv = Find(v);
            if (pu != pv)
                parent[pu] = pv;
        }
        unordered_map<int, vector<int>> getGroups()
        {
            unordered_map<int, vector<int>> groups;
            for (auto const &[u, _] : parent)
            {
                std::cout << (int)_ << " " << Find(u) << std::endl;
                groups[Find(u)].push_back(u);
            }
            return groups;
        }
    };

    void run()
    {
        // [[10,3,4,9,5,15,8],[12,4,2,10,1,13,14],[11,13,9,8,6,7,12],[2,10,15,4,9,3,15],[1,2,17,16,7,15,3],[5,14,18,11,10,8,4],[3,15,5,6,8,14,7]]
        print_res(matrixRankTransform({{-2, -35, -32, -5, -30, 33, -12}, {7, 2, -43, 4, -49, 14, 17}, {4, 23, -6, -15, -24, -17, 6}, {-47, 20, 39, -26, 9, -44, 39}, {-50, -47, 44, 43, -22, 33, -36}, {-13, 34, 49, 24, 23, -2, -35}, {-40, 43, -22, -19, -4, 23, -18}}));
    }

    vector<vector<int>> matrixRankTransform(vector<vector<int>> &&matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        map<int, vector<pair<int, int>>> groupByValue;
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                groupByValue[matrix[r][c]].push_back({r, c});

        vector<int> rank(m + n, 0); // rank[i] is the largest rank of the row or column so far
        for (auto const &[_, cells] : groupByValue)
        {
            UnionFind uf;
            for (auto const &[r, c] : cells)
                uf.Union(r, c + m); // Union row `r` with column `c` (column +m to separate with r)

            for (auto const &[_, group] : uf.getGroups())
            {
                int maxRank = 0;
                for (int i : group)
                    maxRank = max(maxRank, rank[i]); // Get max rank of all included rows and columns
                for (int i : group)
                    rank[i] = maxRank + 1; // Update all rows or columns in the same groups to new rank
            }
            for (auto const &[r, c] : cells)
                matrix[r][c] = rank[r]; // or matrix[r][c] = rank[c], both are correct.
        }
        return matrix;
    }
};