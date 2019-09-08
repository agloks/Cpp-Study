#include <iostream>
#include <string>
#include "stack.h"
#include <algorithm>
#include <vector>
#include <regex>

std::string DNAStrand(const std::string& dna)
{
    int len = dna.length();
    char *send = (char*)calloc(len+1,sizeof(char));
    int x = 0;
    for(x; x < len; x++)
    {
        switch (dna[x])
        {
        case 'G':
            send[x] = 'C';
            break;
        case 'T':
            send[x] = 'A';
            break;
        case 'A':
            send[x] = 'T';
            break;
        case 'C':
            send[x] = 'G';
            break;
        }
    }
    send[x] = '\0';
    return send; 
}

int main(void)
{
    std::string word = "ATTGC";
    std::cout << DNAStrand(word) << std::endl;
    return 0;
}