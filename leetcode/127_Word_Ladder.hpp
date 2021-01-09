#include "../base/icode.hpp"
class L127 : public icode
{
public:
	void run() {
        cout << ladderLength("hit", "cog", {"hot","dot","dog","lot","log","cog"}) << " 5" << endl;
        cout << ladderLength("hit", "cog", {"hot","dot","dog","lot","log"}) << " 0" << endl;
    }

    int ladderLength(string beginWord, string endWord, vector<string>&& wordList) {
        size_t len = beginWord.size();
        map<string, vector<string>> trans;
        for (auto &item : wordList) {
            for (size_t i = 0; i < len; ++i) {
                string new_(item);
                new_[i] = '*';
                if (trans.find(new_) == trans.end()) {
                    trans.insert({new_, vector<string>()});
                }
                trans[new_].emplace_back(item);
            }
        }
        queue<pair<string, int>> bfs;
        bfs.push({beginWord, 1});
        map<string, bool> vis;
        vis[beginWord] = 1;
        while(!bfs.empty()) {
            string cur = bfs.front().first;
            int time = bfs.front().second;
            bfs.pop();
            for (size_t i = 0; i < len; ++i) {
                string new_(cur);
                new_[i] = '*';
                for (auto item : trans[new_]) {
                    if (item == endWord) {
                        return time + 1;
                    }
                    if (vis.find(item) == vis.end()) {
                        vis[item] = 1;
                        bfs.push({item, time + 1});
                    }
                }
            }
        }
        return 0;
    }
};