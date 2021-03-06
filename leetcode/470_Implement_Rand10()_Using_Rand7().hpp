#include "../base/icode.hpp"
class L470 : public icode
{
public:
	void run() {}

    int rand7() {
        return rand() % 7 + 1; 
    }

    int rand10() {
        int row, col, idx;
        do {
            row = rand7();
            col = rand7();
            idx = col + (row - 1) * 7;
        } while (idx > 40);
        return 1 + (idx - 1) % 10;
    }
};