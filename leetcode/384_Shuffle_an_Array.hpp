#include "../base/icode.hpp"
class ShuffleArray : public icode
{
private:
    vector<int> original;
    vector<int> current;

public:
    void run()
    {
        ShuffleArray *obj = new ShuffleArray({1, 2, 3});
        print_res(obj->reset());
        print_res(obj->shuffle());
    }

    ShuffleArray() {}

    ShuffleArray(vector<int> &&nums)
    {
        original.assign(nums.begin(), nums.end());
        current.assign(nums.begin(), nums.end());
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset()
    {
        return original;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle()
    {
        for (int i = current.size() - 1; i > 0; --i)
        {
            swap(current[i], current[rand() % (i + 1)]);
        }
        return current;
    }
};