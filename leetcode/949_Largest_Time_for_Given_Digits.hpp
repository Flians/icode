#include "../base/icode.hpp"
class L949 : public icode
{
public:
	void run() {
        vector<int> A = {1,2,3,4};
        cout << largestTimeFromDigits(A) << " 23:41" << endl;
    }

    string largestTimeFromDigits(vector<int>& A) {
        int max_time = -1;
        std::sort(A.begin(), A.end());
        do {
            int hour = A[0] * 10 + A[1];
            int minute = A[2] * 10 + A[3];

            if (hour < 24 && minute < 60) {
                int new_time = hour * 60 + minute;
                max_time = new_time > max_time ? new_time : max_time;
            }
        } while(next_permutation(A.begin(), A.end()));

        if (max_time == -1) {
            return "";
        } else {
            std::ostringstream strstream;
            strstream << std::setw(2) << std::setfill('0') << max_time / 60
               << ":" << std::setw(2) << std::setfill('0') << max_time % 60;
            return strstream.str();
        }
    }
};