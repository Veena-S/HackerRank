// BirthdayChocolate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>


using namespace std;

int main(){
    int n;
    cin >> n;

    if( n < 1 || n > 100 )
    {
        return 0;
    }

    vector<int> squares(n);
    int s = 0;
    for(int squares_i = 0; squares_i < n; squares_i++)
    {
        cin >> s;
        if( s < 1 || s > 5 )
        {
            return 0;
        }
        squares[squares_i] = s;
    }
    int d;
    int m;
    cin >> d >> m;
    if( d < 1 || d > 31 || m < 1 || m > 12 )
    {
        return 0;
    }
    
    int nTotalCount = 0;

    for( int i = 0; i < n; i++ )
    {
        int nSum = 0;
        int j = i;
        int nCount = 0;
        while(( nCount < m ) && ( j < n ))
        {
            nSum += squares[ j ];
            j++;
            nCount++;
        }
        if( nSum == d )
        {
            nTotalCount++;
        }
    }

    cout << nTotalCount;
    return 0;
}

