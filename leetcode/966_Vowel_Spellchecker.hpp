#include "../base/icode.hpp"
class L966 : public icode
{
public:
    void run()
    {
        // ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
        print_res(spellchecker({"KiTe", "kite", "hare", "Hare"}, {"kite", "Kite", "KiTe", "Hare", "HARE", "Hear", "hear", "keti", "keet", "keto"}));
    }

    vector<string> spellchecker(vector<string> &&wordlist, vector<string> &&queries)
    {
        unordered_set<std::string> words;
        unordered_map<std::string, std::string> words_low;
        unordered_map<std::string, std::string> words_vow;
        for (std::string &item : wordlist)
        {
            words.insert(item);
            std::string low_str;
            low_str.resize(item.size());
            std::transform(item.begin(), item.end(), low_str.begin(), ::tolower);
            if (words_low.find(low_str) == words_low.end())
                words_low[low_str] = item;
            std::string vow_str;
            for (char c : low_str)
            {
                vow_str.append(1, c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ? '*' : c);
            }
            if (words_vow.find(vow_str) == words_vow.end())
                words_vow[vow_str] = item;
        }
        auto _end = words.end();
        auto low_end = words_low.end(), vow_end = words_vow.end();
        std::vector<string> res(queries.size());
        int i = 0;
        for (std::string &query : queries)
        {
            auto _find_set = words.find(query);
            if (_find_set != _end)
            {
                res[i++] = query;
                continue;
            }
            std::string _query;
            _query.resize(query.size());
            std::transform(query.begin(), query.end(), _query.begin(), ::tolower);
            auto _find = words_low.find(_query);
            if (_find != low_end)
            {
                res[i++] = _find->second;
                continue;
            }
            std::string _query_vow;
            for (char c : _query)
            {
                _query_vow.append(1, c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ? '*' : c);
            }
            _find = words_vow.find(_query_vow);
            if (_find != vow_end)
            {
                res[i++] = _find->second;
                continue;
            }
            ++i;
        }
        return res;
    }
};