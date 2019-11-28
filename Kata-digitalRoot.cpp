#include <iostream>
#include <vector>
#include <algorithm>
/*
    1 - diminui os preços do carro a cada turno por percentLossByMonth
    2 - fazer isso enquano savingperMonth + startPriceOld < startPriceNew
    3 - retorna um vector com o total de turno + a sobra do processo 2
*/

int digital_root(int n)
{
    std::string number = std::to_string(n);
    int temp = 0;
    while(number.length() != 1)
    {
        temp = 0;
        for(int x = 0; x < number.length(); x++)
        {
            temp += number[x]-48;
            std::cout << "temp = " << temp << std::endl;
        }
        number = std::to_string(temp);
        std::cout << "number = " << number << std::endl;
    }
    return temp;
}


int main()
{
    int a = digital_root(132189);
    std::cout << a << std::endl;
    return 0;
}
