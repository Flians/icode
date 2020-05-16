#include "base/icode.hpp"
#include "base/Factory.hpp"

int main()
{
    int id = 1;
    Factory *factory = new Factory();
    while (id > 0)
    {
        cout << "please input the id of the problem: " << endl;
        cin >> id;
        factory->problem(id)->run();
        system("pause");
    }
    return 0;
}
