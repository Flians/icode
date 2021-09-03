#include "base/icode.hpp"
#include "base/Factory.hpp"

int main()
{
    int id = 1;
    Factory *factory = new Factory();
    while (id > 0)
    {
        std::cout << "please input the id of the problem: " << std::endl;
        std::cin >> id;
        factory->problem(id)->run();
        std::system("pause");
    }
    return 0;
}
