#include <iostream>
#include <string>

int sumInterator(int begin, int end, int step)
{
    int storage = 0;
    for(begin ; begin <= end; begin += step)
    {
        storage += begin;
        std::cout << storage << std::endl; 
    }
    return storage;
}

int main(void)
{
    std::cout << sumInterator(1,5,3) << std::endl;
    return 0;
}