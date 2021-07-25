#include "../base/icode.hpp"
class L126 : public icode
{
public:
    void run()
    {
        // [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
        print_res(findLadders("hit", "cog", {"hot", "dot", "dog", "lot", "log", "cog"}));
    }

    vector<string> findNeighbors(const string &word, const unordered_set<string> &wordList)
    {
        vector<string> neighbors;
        for (int i = 0, n = word.size(); i < n; i++)
        {
            char oldChar = word[i];
            string tmp(word);
            for (char c = 'a'; c <= 'z'; c++)
            {
                tmp[i] = c;
                if (c == oldChar || !wordList.count(tmp))
                {
                    continue;
                }
                neighbors.push_back(tmp);
            }
        }
        return neighbors;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &&wordList)
    {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        unordered_map<string, vector<vector<string>>> layer;
        layer[beginWord] = {{beginWord}};
        wordSet.erase(beginWord);
        while (!layer.empty())
        {
            unordered_map<string, vector<vector<string>>> newLayer;
            for (const auto &[word, paths] : layer)
            {
                if (word == endWord)
                    return layer[word];
                for (const string &nei : findNeighbors(word, wordSet))
                {
                    for (auto path : paths)
                    {
                        path.push_back(nei);
                        newLayer[nei].push_back(path);
                    }
                }
            }
            for (const auto &[word, _] : newLayer)
                wordSet.erase(word);
            layer.swap(newLayer);
        }
        return {};
    }
};