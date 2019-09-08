#include <iostream>
#include <string>
#include "stack.h"
#include <algorithm>
#include <vector>

void print(int interador)
{
    std::cout << interador + 10 << "\n";
}

int main(void)
{
    // stack pilha(2 , "let's go");
    // std::cout << pilha.getValues("name") << std::endl;
    
    // std::vector<int> vector;
    // vector.push_back(10);
    // vector.push_back(20);
    // vector.push_back(30);

    // std::for_each(vector.begin(),vector.end(),print);

    int set [9] = {1,2,3,4,5,6,7,8,9};
    std::for_each(std::begin(set),std::end(set),print);

    return 0;
}