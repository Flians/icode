#include "../base/icode.hpp"
class Random_pick : public icode {
public:
    vector<int> sum;
    
    Random_pick() {
        this->sum.reserve(10);
        srand((unsigned)time(NULL));
    }

    Random_pick(vector<int>& w) {
        srand((unsigned)time(NULL));
        if (!w.empty()) {
            this->sum.reserve(w.size());
            this->sum.emplace_back(w[0]);
            for (size_t i = 1; i < w.size(); ++i) {
                this->sum.emplace_back(this->sum[i-1] + w[i]);
            }
        }
    }
    
    int pickIndex() {
        int pro = rand() % sum.back();
        int index = 0;
        while(sum[index++] < pro);
        return index-1;
    }

    void run() {
        vector<int> w = {1, 3};
        Random_pick* obj = new Random_pick(w);
        cout << obj->pickIndex() << endl;
        cout << obj->pickIndex() << endl;
        cout << obj->pickIndex() << endl;
        cout << obj->pickIndex() << endl;
        cout << obj->pickIndex() << endl;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Random_pick* obj = new Random_pick(w);
 * int param_1 = obj->pickIndex();
 */