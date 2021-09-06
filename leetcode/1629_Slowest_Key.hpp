#include "../base/icode.hpp"
class L1629 : public icode
{
public:
    void run()
    {
        cout << slowestKey({12, 23, 36, 46, 62}, "spuda") << " a" << endl;
    }

    char slowestKey(vector<int> &&releaseTimes, string keysPressed)
    {
        int maps[26] = {0};
        int last = 0, maxv = 0, res = 'a';
        for (int i = 0, n = releaseTimes.size(); i < n; ++i)
        {
            int tmp = releaseTimes[i] - last;
            if (maps[keysPressed[i] - 'a'] < tmp)
            {
                maps[keysPressed[i] - 'a'] = tmp;
                if (maxv < tmp)
                {
                    maxv = tmp;
                    res = keysPressed[i];
                }
                else if (maxv == tmp)
                {
                    res = max(res, (int)keysPressed[i]);
                }
            }
            last = releaseTimes[i];
        }
        return res;
    }
};