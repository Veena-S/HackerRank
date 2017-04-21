#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int t;
    cin >> t;
    if( t < 1 || t > 100000 )
    {
        return 0;
    }
    vector<int> Result;
    for(int a0 = 0; a0 < t; a0++)
    {
        int n;
        cin >> n;
        if( n < 1 || n > 1000000000 )
        {
            return 0;
        }

        // Count the numbers that are multiples of 3 under the given number n.
        int nCountThree = (( n / 10 ) * 3 ) + ( ( n % 10 ) / 3 ) + ( n / 30 );
        // Check whether n itself is divisible by 3. If so, subtract 1.
        nCountThree -= ( 0 == (n % 3 )) ? 1 : 0;

        // Count the numbers that are multiples of 5.
        int nCountFive = n / 5;
        nCountFive -= ( 0 == (n % 5 )) ? 1 : 0;

        int nCountFifteen = n / 15;
        nCountFifteen -= ( 0 == ( n % 15 )) ? 1 : 0;

        int Sum = 0;
        for( int i = 1; i <= nCountThree; i++ )
        {
            Sum += (i * 3);
        }
        for( int i = 1; i <= nCountFive; i++ )
        {
            Sum += (i * 5);
        }
        for( int i = 1; i <= nCountFifteen; i++ )
        {
            Sum -= (i * 15);
        }
        Result.push_back( Sum);
    }

    for ( int i = 0; i < t; i++ )
    {
        cout << Result[i] << endl;
    }
    return 0;
}