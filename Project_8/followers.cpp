//
//  followers.cpp
//  project 8
//
//  Created by Ian Ferguson on 12/3/18. Co-authored by Andrew Adler and Bradley Morton
//  Copyright © 2018 Ian Ferguson, Andrew Adler, Bradley Morton. All rights reserved.
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

//Old code from before we decided to do everything in main
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
    std::string filename;
    std::ifstream fs;
    //While loop
    //Tests for strange cases. Will not proceed unless an actual, valid file name is given and read.
    while (true) 
    {
        std::cout << "Enter the name of the file to search through: "<<std::endl;
        std::getline(std::cin, filename);
        fs.open(filename);
        if(fs.is_open()) break;
        std::cout<<"Invalid file name. Try again"<<std::endl;
    }
    //Map that contains
    map<string, set<string> > mp;
    string nextWord;
    string currentWord;
    if(fs.is_open())
    {
        //While file is being read
        while(true)
        {
            if (currentWord == "")
            {
                fs >> currentWord;
            }
            //Read each string in the file
            fs >> nextWord;
            //If there's nothing else to read, insert white space and continue onto a new line
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
    //Iterate over each entry in the map until we reach the end
    for(map<string, set<string> >::iterator p = mp.begin(); p != mp.end(); p++)
    {
        //First string is our starting point
        std::cout << p -> first << ": ";
        set<string> myset = p -> second;
        //Iterate over each set of strings
        for(set<string>::iterator it=myset.begin(); it!=myset.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}


