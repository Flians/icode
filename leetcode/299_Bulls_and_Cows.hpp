#include "../base/icode.hpp"
class L299 : public icode
{
public:
	void run() {}

    string getHint(string secret, string guess) {
        int A = 0, B = 0;
        vector<int> ds(10, 0);
        vector<int> gs(10, 0);
        for (size_t i = 0; i < secret.length(); ++i) {
            if (secret[i] == guess[i]) {
                ++A;
            } else {
                ++ds[secret[i]-'0'];
                ++gs[guess[i]-'0'];
            }
        }
        for (int i = 0; i < 10; ++i) {
            B += min(ds[i], gs[i]);
        }
        return to_string(A) + "A" + to_string(B) + "B";
    }
};