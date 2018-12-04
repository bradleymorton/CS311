//
//  followers.cpp
//  project 8
//
//  Created by Ian Ferguson on 12/3/18.
//  Copyright © 2018 Ian Ferguson. All rights reserved.
//

#include <iostream>
#include <map>
#include <fstream>
#include <iterator>

using std::fstream;
using std::string;
using std::map;
using std::iterator;

void UniqueCount(map<string, int> mp)
{
    for(map<string, int> :: iterator p = mp.begin(); p != mp.end(); p++)
    {
        if (p -> second ==1)
        {
            std::cout << p-> first << std::endl;
        }
    }
    
}

int main()
{
    std::ifstream fs ("followers_text.txt");
    map<string, int> mp;
    if(fs.is_open())
    {
        while(fs.good())
        {
            string words;
            fs >> words;
            
            if(mp.find(words) == mp.end())
            {
                mp[words] = 1;
            }
            else
            {
                mp[words]++;
            }
        }
    }
    else
    {
        std::cerr << "cannot open file." << std::endl;
        return EXIT_FAILURE;
    }
    UniqueCount(mp);
    
    return EXIT_SUCCESS;

}


