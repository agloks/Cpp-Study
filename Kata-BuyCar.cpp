#include <iostream>
#include <vector>
#include <algorithm>
/*
    1 - diminui os preços do carro a cada turno por percentLossByMonth
    2 - fazer isso enquano savingperMonth + startPriceOld < startPriceNew
    3 - retorna um vector com o total de turno + a sobra do processo 2
*/

class BuyCar
{

  public:
  static std::vector<int> nbMonths(int startPriceOld, int startPriceNew, int savingperMonth, double percentLossByMonth);
};

std::vector<int> BuyCar::nbMonths (int startPriceOld, int startPriceNew, int savingperMonth, double percentLossByMonth)
{
    int month = 0, newMoney = 0;
    double old = startPriceOld , novo = startPriceNew;
    while(old + newMoney < novo )
    {
        ++month;
        if(month % 2 == 0) {percentLossByMonth += 0.5;}
        old -= ((old/100) * percentLossByMonth);
        novo -= ((novo/100) * percentLossByMonth);
        newMoney += savingperMonth;
    }
    std::vector<int> a = { month, ((old + newMoney) - novo - 0.49) + 1 };
    return a;
}

int main()
{
    std::vector<int> b  = BuyCar::nbMonths(2000, 8000, 1000, 1.5);
    for(int x : b)
    {
        std::cout << x << std::endl;
    }
    return 0;
}
