#include "../base/icode.hpp"
class L1461 : public icode
{
public:
    void run()
    {
        std::cout << hasAllCodes("0000000001011100", 4) << " false" << std::endl;
        std::cout << hasAllCodes("00110110", 2) << " true" << std::endl;
    }

    bool hasAllCodes(string s, int k)
    {
        int len = s.size() - k;
        std::set<std::string> subs;
        for (int i = 0; i <= len; ++i)
        {
            subs.insert(s.substr(i, k));
        }
        return subs.size() == pow(2, k);
    }
};