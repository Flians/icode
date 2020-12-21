#include "../base/icode.hpp"
class L880 : public icode
{
public:
	void run() {
        cout << decodeAtIndex("czjkk9elaqwiz7s6kgvl4gjixan3ky7jfdg3kyop3husw3fm289thisef8blt7a7zr5v5lhxqpntenvxnmlq7l34ay3jaayikjps",768077956) << " c" << endl;
    }

    string decodeAtIndex(string S, int K) {
        long i = 0, N = 0;
        for (i = 0; N < K; i++) {
            N = S[i] >= '0' && S[i] <= '9' ? N * (S[i] - '0') : N + 1; 
        }
        while (i--) {
            if (S[i] >= '0' && S[i] <= '9') {
                N /= S[i] - '0';
                K %= N;
            } else if (K % N-- == 0) {
                return string(1, S[i]);
            }
        }
        return "";
    }
};