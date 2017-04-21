#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int nTotalCandies;
    int time;
    int nCandyTaken = 0;
    int nCandyAdded = 0;
    cin >> nTotalCandies >> time;
    if( nTotalCandies < 5 || nTotalCandies > 100 || time < 1 || time > 100 )
    {
        return 0;
    }
    int nCandiesInBowl = nTotalCandies;
//    vector<int> candies(time);
    for(int c_i = 0; c_i < time; c_i++)
    {
        cin >> nCandyTaken;
        if( nCandyTaken > nTotalCandies || nCandyTaken < 1 )
        {
            return 0;
        }
//        candies[c_i] = nCandyTaken;
        if( c_i == ( time - 1 )) // last minute. no need to refill.
        {
            break;
        }

        // Take those candies from the bowl.
        nCandiesInBowl -= nCandyTaken;
        // Check the remaining number of candies. If less than 5, refill.
        int nTemp = 0;
        nTemp = ( nCandiesInBowl < 5 ) ? ( nTotalCandies - nCandiesInBowl ) : 0;
        nCandyAdded += nTemp;
        nCandiesInBowl += nTemp;
    }
    cout << nCandyAdded;


    return 0;
}
