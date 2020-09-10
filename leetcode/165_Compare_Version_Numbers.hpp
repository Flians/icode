#include "../base/icode.hpp"
class L165 : public icode
{
public:
	void run() {
        cout << compareVersion("0.1", "1.1") << " -1" << endl;
        cout << compareVersion("1.0.1", "1") << " 1" << endl;
        cout << compareVersion("7.5.2.4", "7.5.3") << " -1" << endl;
        cout << compareVersion("1.01", "1.001") << " 0" << endl;
        cout << compareVersion("1.0", "1.0.0") << " 0" << endl;
    }

    int compareVersion(string version1, string version2) {
        string v1 = "0", v2 = "0";
        size_t i = 0, j = 0;
        version1 += ".";
        version2 += ".";
        while (i < version1.length() || j < version2.length()) {
            if (version1[i] != '.') {
                v1 += version1[i++];
            }
            if (version2[j] != '.') {
                v2 += version2[j++];
            }
            if (version1[i] == '.' && version1[i] == version2[j]) {
                if (atoi(v1.c_str()) < atoi(v2.c_str())) {
                    return -1;
                }
                if (atoi(v1.c_str()) > atoi(v2.c_str())) {
                    return 1;
                }
                v1 = "0", v2 = "0";
                if (i+1 < version1.length()) i++;
                if (j+1 < version2.length()) j++;
                if (i+1 == version1.length() && j+1 == version2.length()) break;
            }
        }
        return 0;
    }
};