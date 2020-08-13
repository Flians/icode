#include "../base/icode.hpp"
class L119 : public icode
{
public:
	void run() {
        print_res(getRow(3));
    }

    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex+1, 1);
        int line = 1;
        while (line <= rowIndex) {
            int last = row[0];
            for (int i = 1; i < line; ++i) {
                row[i] += last;
                last = row[i] - last;
            }
            ++line;
        }
        return row;
    }
};