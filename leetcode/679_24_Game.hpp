#include "../base/icode.hpp"

class L679 : public icode {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> numbers{double(nums[0]), double(nums[1]), double(nums[2]), double(nums[3])};
        return helper(numbers, 4);
    }
    
    bool helper(vector<double>& numbers, int n) {
        if (n == 1 && fabs(numbers[0] - 24) < 0.00001) return true;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double a, b;
                a = numbers[i];
                b = numbers[j];
                numbers[j] = numbers[n - 1];
                
                numbers[i] = a + b;
                if (helper(numbers, n - 1)) return true;
                numbers[i] = a - b;
                if (helper(numbers, n - 1)) return true;
                numbers[i] = b - a;
                if (helper(numbers, n - 1)) return true;
                numbers[i] = a * b;
                if (helper(numbers, n - 1)) return true;
                numbers[i] = a / b;
                if (helper(numbers, n - 1)) return true;
                numbers[i] = b / a;
                if (helper(numbers, n - 1)) return true;
                
                numbers[i] = a;
                numbers[j] = b;
            }
        }
        
        return false;
    }

    void run() {

    }
};