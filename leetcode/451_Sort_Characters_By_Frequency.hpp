#include "../base/icode.hpp"
class L451 : public icode
{
public:
	void run() {
        cout << frequencySort("tree") << " eert" << endl;
        cout << frequencySort("cccaaa") << " cccaaa" << endl;
        cout << frequencySort("Aabb") << " bbAa" << endl;
    }

    string frequencySort(string s) {
        vector<int> record(128, 0);
        for (int i = 0; i < s.length(); ++i) {
            ++record[s[i]];
        }
        sort(s.begin(), s.end(),
            [&](char &l, char &r) {
                return ((record[l] > record[r]) || (record[l] == record[r] && l < r));
            }    
        );
        return s;
    }
};