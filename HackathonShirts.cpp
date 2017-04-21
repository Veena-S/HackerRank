// HackathonShirts.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int main(){
    int q;
    cin >> q;
    if( q < 1 || q > 20 )
    {
        return 0;
    }
    vector<int> result;
    for(int a0 = 0; a0 < q; a0++)
    {
        int n;
        cin >> n;
        if( n < 1 || n > 50000 )
        {
            return 0;
        }
        vector<int> sizes(n);
        for(int sizes_i = 0; sizes_i < n; sizes_i++)
        {
            cin >> sizes[sizes_i];
        }
        int v;
        cin >> v;
        if( v < 1 || v > 50000 )
        {
            return 0;
        }
        int nCount = 0;
        vector<int> tV = sizes;
        int nS = tV.size();

        for(int a1 = 0; a1 < v; a1++)
        {
            int smallest;
            int largest;
            cin >> smallest >> largest;
            if( smallest < 1 || largest < 1 || smallest > 1000000000 || largest > 1000000000 )
            {
                return 0;
            }

            int temp = 0;
            for( int i = 0; i < nS; i++ )
            {
                temp = tV[i];
                if( temp <= largest && temp >= smallest )
                {
                    nCount++;
                    tV[i] = 0;
                }
            }
        }
        result.push_back( nCount );
    }

    for( int i = 0; i < result.size(); i++ )
    {
        cout << result[i] << endl;
    }
    return 0;
}
