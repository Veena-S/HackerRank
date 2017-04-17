// Day9_Recursion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int factorial( int N )
{
    if( N > 1 )
    {
        return N * factorial( N - 1 );
    }
    else
    {
        return 1;
    }
}

int main()
{
    int N;
    cin >> N;
    // 2 <= N <= 12
    if( N < 2 || N > 12 )
    {
        return 0;
    }
    cout << factorial( N );
    return 0;
}

