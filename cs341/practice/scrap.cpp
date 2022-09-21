#include <iostream>
using namespace std;

int main()
{
    
    int i[2];
    std::cout << "i[0] = " << i[0] << std::endl;
    std::cout << "i[1] = " << i[1] << std::endl;
    int *k;
    std::cout << "i[0] = " << i[0] << std::endl;
    std::cout << "i[1] = " << i[1] << std::endl;
    int &l = i[0];
    std::cout << "i[0] = " << i[0] << std::endl;
    std::cout << "i[1] = " << i[1] << std::endl;
    int &j = i[1];
    std::cout << "i[0] = " << i[0] << std::endl;
    std::cout << "i[1] = " << i[1] << std::endl;
    k = &(i[0]);
    std::cout << "i[0] = " << i[0] << std::endl;
    std::cout << "i[1] = " << i[1] << std::endl;
    i[0] = 0;
    std::cout << "i[0] = " << i[0] << std::endl;
    std::cout << "i[1] = " << i[1] << std::endl;
    i[1] = 1;
    std::cout << "i[0] = " << i[0] << std::endl;
    std::cout << "i[1] = " << i[1] << std::endl;
    *(k + 1) = 5;
    std::cout << "i[0] = " << i[0] << std::endl;
    std::cout << "i[1] = " << i[1] << std::endl;
    l = 6;
    std::cout << "i[0] = " << i[0] << std::endl;
    std::cout << "i[1] = " << i[1] << std::endl;
    return 0;
}
