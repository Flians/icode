#include "../base/icode.hpp"
class L1401 : public icode
{
public:
	void run() {}

    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int x = (x_center <= x2 && x_center >= x1) ? 0 : min(abs(x1 - x_center), abs(x2 - x_center));
        int y = (y_center <= y2 && y_center >= y1) ? 0 : min(abs(y1 - y_center), abs(y2 - y_center));
        return x*x + y*y <= radius*radius;
    }
};