// Day8_DictonariesAndMaps.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;


int main()
{
    typedef map<string, string> PHONE_BOOK;
    int n = 0; // Number of entries in the map.
    cin >> n;
    if( n < 1 || n > 100000 )
    {
        return 0;
    }
    string name, phone;
    PHONE_BOOK pBook;
    for( int i = 0; i < n; i++ )
    {
        cin >> name >> phone;
        pBook[name] = phone;
    }
    int q = 0;
    vector<string> Out;
    PHONE_BOOK::iterator itr;
    while( cin >> name && q <= 100000 )
    {
//        cin >> name;
        itr = pBook.find( name );
        if( itr != pBook.end())
        {
            Out.push_back( name + "=" + itr->second );
        }
        else
        {
            Out.push_back( "Not found" );
        }
        q++;
    }
    if( q > 100000 )
    {
        return 0;
    }
    int s = Out.size();
    for( int i = 0; i < s; i++ )
    {
        cout << Out[i] << endl;
    }
    return 0;
}

