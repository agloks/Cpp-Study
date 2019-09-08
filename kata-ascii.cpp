#include <iostream>
#include <string>

std::string highestScoringWord(const std::string &str)
{
    int len = str.length(), count = 0, win = 0, index = 0, where = 0, champion = 0;
    bool found = false;

    for(int i = 0; i < len; i++)
    {
        if(str[i] != ' ')
        {
            count += str[i]-96;
            if(count > win)
            {
                found = true;
                index = i-where;
                champion = count;
            }
            where += 1;
        }
        else
        {
            if(found = true)
            {
                found = false;
            }
            where = 0;
            win = champion;
            count = 0;
        }
    }

    std::string nova = str.substr(index);
    count = 0;
    while (nova[count] != ' ')
    {
        ++count;
    }
    std::cout << champion << '\t' << index << '\t' << count << std::endl; 
    nova = str.substr(index,count);  
    return nova;
}

int main (void) 
{
    std::string test = "take two bintang and a dance please";
    std::cout << highestScoringWord(test) << std::endl;
    return 0;
}