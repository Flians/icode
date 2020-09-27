#include "../base/icode.hpp"
class L1041 : public icode
{
public:
	void run() {
        cout << isRobotBounded("GGLLGG") << " true" << endl;
        cout << isRobotBounded("GG") << " false" << endl;
        cout << isRobotBounded("GL") << " true" << endl;
    }

    bool isRobotBounded(string instructions) {
        int x =0 ,y = 0;
        int dir = 0;
        for (char item : instructions) {
            switch (item) {
                case 'G':
                    switch(dir) {
                        // N
                        case 0:
                            ++y;
                            break;
                        // E
                        case 1:
                            ++x;
                            break;
                        // S
                        case 2:
                            --y;
                            break;
                        // W
                        case 3:
                            --x;
                            break;
                    }
                    break;
                case 'L':
                    if (dir == 0) {
                        dir = 3;
                    } else {
                        --dir;
                    }
                    break;
                case 'R':
                    if (dir == 3) {
                        dir = 0;
                    } else {
                        ++dir;
                    }
                    break;
            }
        }
        if (x+y == 0) {
            return true;
        } else {
            return dir;
        }
    }
};