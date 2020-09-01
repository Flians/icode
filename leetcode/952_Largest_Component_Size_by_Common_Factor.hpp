#include "../base/icode.hpp"
class L952 : public icode
{
public: 
	void run() {
        vector<int> A = {4,6,15,35};
        cout << largestComponentSize(A) << " 4" << endl;
        A = {20,50,9,63};
        cout << largestComponentSize(A) << " 2" << endl;
        A = {2,3,6,7,4,12,21,39};
        cout << largestComponentSize(A) << " 8" << endl;
    }

    unordered_map<int, int> p;
    
    int find(int a) {
        if (!p.count(a)) return p[a] = a;
        if (p[a] == a) return a;
        return p[a] = find(p[a]);
    }
    
    int largestComponentSize(vector<int>& A) {
        for (int a : A)
            p[a] = a;
        for (int a : A) 
            for (int i = 2; i <= sqrt(a); ++i)
                if (a % i == 0) {
                    p[find(a)] = p[find(i)];
                    p[find(a)] = p[find(a / i)];
                }
        unordered_map<int, int> cnt;
        int res = 1;
        for (int a : A)
            res = max(res, ++cnt[find(a)]);
        return res;
    }
};