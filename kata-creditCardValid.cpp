#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
// #include <iterator>

bool creditCardValid(long int n){
    int position = 0, soma = 0;
    std::vector<int> vector;
    std::string used = std::to_string(n);
    position = (used.length()%2 == 0) ? 1:0;
    for(char z:used)
    {
        vector.push_back(z-'0');
    }
    // for_each(vector.begin(),vector.end(),[](int n){std::cout << n << std::endl;});
    for(int x=0 ; x < vector.size(); x ++)
    {
        position += 1;
        if (position == 2)
        {
            vector[x] = vector[x]*2 ;
            while(vector[x] > 9)
            {
                std::string temp = std::to_string(vector[x]);
                int storage = 0;
                for(char c:temp)
                {
                    storage += c-'0';
                    std::cout << "storage = " << storage << std::endl;
                }
                vector[x] = storage;
            }
            position = 0;
        }
    }
    for(int d:vector)
    {
        soma += d;
    }
    std::cout << soma << std::endl;
    return (abs(soma)%10 == 0) ? true:false;
}

int main()
{
    // std::vector<int> a {2,1,1}; 
    // int cartao[3] = {8 , 9 , 1};
    std::cout << creditCardValid(212) << std::endl;
    // a.push_back(4);
    // for_each(a.begin(),a.end(),[](int s){std::cout << s << std::endl;});
    return 0;
}