#include <iostream>
#include <vector>
#include <algorithm>

// int sum(std::vector<int> a)
// {
//     if(a.size() == 1) {return a[0];}
//     int min = a[0], max = a[0], sum = 0;
//     std::vector<int> j;
//     for(int x:a)
//     {
//         if(x>max){ max = x; }
//         if(x<min){ min = x; }
//     }
//     for(int x:a)
//     {
//         if(!(x == max || x == min)){j.push_back(x);}
//     }
//     // std::vector<int>::iterator itMax = std::find(a.begin(),a.end(),max);
//     // std::vector<int>::iterator itMin = std::find(a.begin(),a.end(),min);
//     // unsigned short indexMin = std::distance(a.begin(), itMin);
//     // a.erase(a.begin()+indexMin);
//     // unsigned short indexMax = std::distance(a.begin(), itMax);
//     // a.erase(a.begin()+indexMax);
//     for(int x:j){ sum += x; }
//     return sum;
// }

int sum(std::vector<int> a)
{
    // short int max = *std::max_element(a.begin(),a.end());
    // short int min = *std::min_element(a.begin(),a.end());
    if(a.size() == 0 || a.size() == 1 || a.size() == 2){return 0;}
    short int max = 0;
    short int min = 0;
    for(int x:a)
    {
        if(x>max){ max = x; }
        if(x<min){ min = x; }
    }
    short int count = 0;
    for(int x = 0; x < a.size(); x ++)
    {
        if((a[x] == min) && (count == 0) && (a.size() != 1))
        {
            a.erase(a.begin()+x);
            count = 1;
        }
    }
    count = 0;
    for(int x = 0; x < a.size(); x ++)
    {
        if((a[x] == max) && (count == 0) && (a.size() != 1))
        {
            a.erase(a.begin()+x);
            count = 1;
        }
    }
    count = 0;
    for(int x:a)
    {
        count += x;
    }
    return count;
}

int main()
{
    // std::vector <int> test = { -6, 20, -1, 10, -12 };
    std::vector <int> test_two = {7,5,6};
    int v = sum(test_two);
    std::cout << v << std::endl;
    return 0;
}
