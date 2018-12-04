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
    string nextWord;
    string currentWord;
    if(fs.is_open())
    {
        while(true)
        {
            if (currentWord == "")
            {
                fs >> currentWord;
            }
            
            fs >> nextWord;
            if (!fs) 
            {
                if (fs.eof()) 
                {
                    string empty;
                    mp[currentWord].insert(empty);
                    break;
                }
            }
            
            mp[currentWord].insert(nextWord);
            
            currentWord = nextWord;
        }
    }
    else
    {
        std::cerr << "cannot open file." << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "Unique count: " << mp.size() << std::endl;

    for(map<string, set<string> >::iterator p = mp.begin(); p != mp.end(); p++)
    {
        std::cout << p -> first << ": ";
        set<string> myset = p -> second;
        for(set<string>::iterator it=myset.begin(); it!=myset.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}


