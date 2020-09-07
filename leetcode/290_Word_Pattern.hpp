#include "../base/icode.hpp"
class L290 : public icode
{
public:
	void run() {}

    bool wordPattern(string pattern, string str) {
        vector<string> words;
        str += " ";
        string item = "";
        unordered_map<string, char> record_s;
        unordered_map<char, string> record_c;
        for (int i = 0 ; i < str.length(); ++i) {
            if (str[i] != ' ') {
                item += str[i];
            } else {
                if (record_s.count(item) && record_s[item] != pattern[words.size()] || record_c.count(pattern[words.size()]) && record_c[pattern[words.size()]] != item) {
                    return false;
                } else {
                    record_s[item] = pattern[words.size()];
                    record_c[pattern[words.size()]] = item;
                }
                words.push_back(item);
                item.clear();
            }
        }
        return words.size() == pattern.length();
    }
};