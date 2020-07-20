#include "../base/icode.hpp"
class L223 : public icode
{
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        long area = abs(A - C) * abs(B - D);
        area += abs(E - G) * abs(F - H);
        if (C <= E || G <= A || H <= B || D <= F)
            return area;
        int w = min(C, G) - max(A, E);
        int h = min(D, H) - max(B, F);
        area -= w * h;
        return area;
    }
    void run()
    {
        cout << computeArea(0, 0, 50000, 40000, 0, 0, 50000, 40000) << endl;
    }
};