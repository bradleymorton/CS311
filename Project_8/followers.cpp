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
#include <set>
using std::fstream;
using std::string;
using std::map;
using std::set;
using std::iterator;

/*
void UniqueCount(map<string, set<string>> mp)
{
    for(map<string, set<string>> :: iterator p = mp.begin(); p != mp.end(); p++)
    {
        if (p -> second ==1)
        {
            std::cout << p-> first << std::endl;
        }
    }
    
}
*/

int main()
{
    std::ifstream fs;
    fs.open("followers_test.txt");
    map<string, set<string> > mp;
    if(fs.is_open())
    {
        while(fs.good())
        {
            string words;
            fs >> words;
            std::cout << words << std::endl;
            
            if(mp.find(words) == mp.end())
            {
                //mp[words] = 1;
            }
        }
    }
    else
    {
        std::cerr << "cannot open file." << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;

}


