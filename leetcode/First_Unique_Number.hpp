#include "../base/icode.hpp"

class FirstUnique : public icode
{
public:
    list<int> uns;
    map<int, list<int>::iterator> record;
    FirstUnique(vector<int> &nums)
    {
        for (auto num : nums)
        {
            add(num);
        }
    }

    int showFirstUnique()
    {
        if (uns.empty())
        {
            return -1;
        }
        else
        {
            return uns.front();
        }
    }

    void add(int value)
    {
        if (record.count(value) == 0)
        {
            uns.push_back(value);
            record[value] = --uns.end();
        }
        else if (record[value] != uns.end())
        {
            uns.erase(record[value]);
            record[value] = uns.end();
        }
    }

    void run()
    {
        vector<int> nums = {2, 3, 5};
        FirstUnique *obj = new FirstUnique(nums);
        cout << obj->showFirstUnique() << endl;
        obj->add(5);
        cout << obj->showFirstUnique() << endl;
        obj->add(2);
        cout << obj->showFirstUnique() << endl;
        obj->add(3);
        cout << obj->showFirstUnique() << endl;
    }
};