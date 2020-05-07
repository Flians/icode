#include "../base/icode.h"
class L476:public icode {
public:
    int findComplement(int num) {
        int res=0, i=0;
        while(num) {
            res += (!(num%2)) << i++;
            num /= 2;
        }
        return i?res:1;
    }

    void run() {
        cout << "5 -> " << findComplement(5) << endl;
        cout << "2 -> " << findComplement(2) << endl;
        cout << "0 -> " << findComplement(0) << endl;
    }
};