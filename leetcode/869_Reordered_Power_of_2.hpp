#include "../base/icode.hpp"
class L869 : public icode
{
public:
    void run()
    {
        cout << reorderedPowerOf2(344353235) << " false" << endl;
        cout << reorderedPowerOf2(10) << " false" << endl;
        cout << reorderedPowerOf2(46) << " true" << endl;
    }

    bool perm(std::vector<int> digits, int n, int index)
    {
        if (index == n)
        {
            int cur = 0;
            for (int i : digits)
                cur = cur * 10 + i;
            return (cur & (cur - 1)) == 0;
        }
        if (index > 0 && digits[0] == 0)
            return false;
        for (int i = index; i < n; ++i)
        {
            swap(digits[i], digits[index]);
            if (perm(digits, n, index + 1))
            {
                return true;
            }
            swap(digits[i], digits[index]);
        }
        return false;
    }

    bool reorderedPowerOf2(int N)
    {
        std::vector<int> digits;
        while (N)
        {
            digits.push_back(N % 10);
            N /= 10;
        }
        return perm(digits, digits.size(), 0);
    }

    int *count(int N)
    {
        int *ans = new int[10]{0};
        while (N > 0)
        {
            ans[N % 10]++;
            N /= 10;
        }
        return ans;
    }

    bool reorderedPowerOf2_new(int N)
    {
        int *digits = count(N);
        for (int i = 0; i < 31; ++i)
        {
            int *cur = count(1 << i);
            bool flag = true;
            for (int j = 0; j < 10; ++j)
            {
                if (digits[j] != cur[j])
                {
                    flag = false;
                    break;
                }
            }
            delete[] cur;
            if (flag)
            {
                delete[] digits;
                return true;
            }
        }
        delete[] digits;
        return false;
    }
};