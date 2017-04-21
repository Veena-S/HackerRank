// ChoosingRecipes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(){
    int q;
    cin >> q;
    if( q < 1 || q > 20 )
    {
        return 0;
    }

    int* QueryOut = new int[q];

    for(int a0 = 0; a0 < q; a0++)
    {
        int r;
        int p;
        int n;
        int m;
        cin >> r >> p >> n >> m;

        int minOfN = ( r < 10 ) ? r : 10;

        if( r < 1 || r > 30 || p < 1 || p > 13 || m < 1 || m > p || n < 1 || n > minOfN )
        {
            return 0;
        }

        vector<int> pantry(m);
        for(int pantry_i = 0; pantry_i < m; pantry_i++)
        {
            cin >> pantry[pantry_i];
        }
        vector<int> cost(p);
        int c = 0;
        for(int cost_i = 0; cost_i < p; cost_i++)
        {
            cin >> c;
            if( c < 1 || c > 10000 )
            {
                return 0;
            }
            cost[cost_i] = c;
        }

        // Change the cost values to 0 at the m indices.
        for( int iM = 0; iM < m; iM++ )
        {
            cost[pantry[iM]] = 0;
        }

        // vector<int> RecipeCosts;
        // Cost and respective row index < cost, rowindex>
        vector<pair<int, int>> RecipeCosts;

        vector< vector<int> > recipe(r,vector<int>(p));
        for(int recipe_i = 0;recipe_i < r;recipe_i++)
        {
            int nRecipeCost = 0;
            int nBinary = 0;
            for(int recipe_j = 0;recipe_j < p;recipe_j++)
            {
                cin >> nBinary;

                // Multiply with the cost value also.
                recipe[recipe_i][recipe_j] = nBinary * cost[recipe_j];
                nRecipeCost += recipe[recipe_i][recipe_j];
            }
            // RecipeCosts.push_back( nRecipeCost );
            RecipeCosts.push_back( make_pair(nRecipeCost, recipe_i) );
        }

        // Sort recipe costs
        sort( RecipeCosts.begin(), RecipeCosts.end());
// 
//         //////////////////////////////////////////////////////////////////////////
//         cout << "Sorted list: " << endl;
//         for( int i = 0; i < RecipeCosts.size(); i++ )
//         {
//             cout << RecipeCosts[i].first << "   " << RecipeCosts[i].second << endl;
//         }
//         cout << endl;
//         //////////////////////////////////////////////////////////////////////////


        // Find the column sum also ( as per the selected recipes only.)
        // So as to reduce this total value from the total sum
        int nToSub = 0;
        int nTempCost = 0;
        for( int j = 0; j < p; j++ )
        {
            int nCount = 0;
//            cout << "NCOUNT: " << nCount << "  Initilaized" << endl;
            for( int i = 0; i < n; i++ )
            {
                nCount += recipe[RecipeCosts[i].second][j];
//                cout << "NCOUNT: " << nCount << "  Index: " << RecipeCosts[i].second << "," << j << endl;
            }
            nTempCost = cost[j];
            nToSub += ( nCount > nTempCost ) ? ( nCount - nTempCost ) : 0;

//            cout << "Value to sub: " << nToSub << endl;

        }

//        cout << " TOTAL Value to sub: " << nToSub << endl;



        int nTotal = 0;
        for( int i = 0; i < n; i++ )
        {
            // nTotal += RecipeCosts[i];
            nTotal += RecipeCosts[i].first;
        }

         nTotal -= nToSub;

        QueryOut[a0] = nTotal;
    }

    for( int i = 0; i < q; i++ )
    {
        cout << QueryOut[i] << endl;
    }
    delete[] QueryOut;
    return 0;
}


