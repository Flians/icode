#include "../base/icode.hpp"

class L478 : public icode
{
public:
    void run()
    {
        L478 obj(1, 0, 0);
        print_res(obj.randPoint());
        print_res(obj.randPoint());
        print_res(obj.randPoint());
    }

    double r, x, y;
    L478() = default;
    L478(double radius, double x_center, double y_center)
    {
        this->r = radius;
        this->x = x_center;
        this->y = y_center;
    }

    vector<double> randPoint()
    {
        double alpha = 2.0 * M_PI * rand() / double(RAND_MAX);
        double _r = this->r * sqrt(rand() / double(RAND_MAX));
        return {_r * cos(alpha) + this->x, _r * sin(alpha) + this->y};
    }
};