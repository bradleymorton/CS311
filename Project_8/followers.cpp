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

int main()
{
    std::cout << "Richard." << std::endl;
    fstream fs ("followers_text.txt");
    
    map<string, int> mp;
    
    string words;
    while(fs >> words)
    {
        if(!mp.count(words))
        {
            mp.insert(make_pair(words, 1));
        }
        else
        {
            mp[words]++;
        }
    }
    fs.close();
    
    for(map<string, int> :: iterator p = mp.begin(); p != mp.end(); p++)
        {
        if (p -> second ==1)
        {
            std::cout << p-> first << std::endl;
        }
        }
    return 0;

}


