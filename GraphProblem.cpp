// GraphProblem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <set>
#include <string>
#include <algorithm>


using namespace std;

int CalculateTrace( vector< vector<int>> Graph, int nVertices )
{
    int trace = 0;
    for( int i = 0; i < nVertices; i++ )
    {
        trace += Graph[i][i];
    }
    return trace;
}

void MatMultiply( int nVertices, vector< vector<int>>& G1, vector< vector<int>>& G2,
                  vector< vector<int>>& G3 )
{
    for( int i = 0; i < nVertices; i++ )
    {
        for( int j = 0; j < nVertices; j++ )
        {
            G3[i][j] = 0;
            for( int k = 0; k < nVertices; k++ )
            {
                 G3[i][j] += G1[i][k] * G2[k][j];
            }
        }
    }
}


int main()
{
    int n;
    cin >> n;
    if( n < 1 || n > 50 )
    {
        return 0;
    }
    vector< vector<int>> g(n, vector<int>(n));
    for(int g_i = 0;g_i < n;g_i++)
    {
        for(int g_j = 0;g_j < n;g_j++)
        {
            cin >> g[g_i][g_j];
        }
    }
// 
//     vector<vector<int>> A1(n, vector<int>(n));
//     vector<vector<int>> A2(n, vector<int>(n));
//     for (int i = 0; i < n; ++i)
//     {
//         for (int j = 0; j < n; ++j)
//         {
//             A1[i][j] = 0;
//             A2[i][j] = 0;
//         }
//     }
// 
//     MatMultiply(n, g, g, A1);
//     MatMultiply(n, g, A1, A2);
//     int nTrace = CalculateTrace( A2, n );
//     int nTotalTriangle = nTrace / 6;


    int nTriangleCount = 0;
//     set<string> vertexSet;
//     set<string>::iterator itrSet;
    vector<vector<int>> AllVertices;
    // Consider every possible triplets of edges in the given graph.
    for( int i = 0; i< n; i++ )
    {
        for( int j = 0; j < n; j++ )
        {
            for( int k = 0; k < n; k++ )
            {
                if( g[i][j] && g[j][k] && g[k][i] )
                {
                    nTriangleCount++;
                    vector<int> Vertices;
                    int nfirst = 0;
                    int nSecond = 0;
                    if( i < j ) 
                    {
                        nfirst = i;
                        nSecond = j;
                    }
                    else
                    {
                        nfirst = j;
                        nSecond = i;
                    }
                    if( k < nfirst )
                    {
                        Vertices.push_back( k );
                        Vertices.push_back( nfirst );
                        Vertices.push_back( nSecond );
                    }
                    else // k > nfirst
                    {
                        Vertices.push_back( nfirst );
                        if( k < nSecond )
                        {
                            Vertices.push_back( k );
                            Vertices.push_back( nSecond );
                        }
                        else
                        {
                            Vertices.push_back( nSecond );
                            Vertices.push_back( k );
                        }
                    }
                    AllVertices.push_back( Vertices );
                }
            }
        }
    }


    sort( AllVertices.begin(), AllVertices.end());
    unique( AllVertices.begin(), AllVertices.end());

    nTriangleCount /= 6;

    float maximalFraction = 0.0f;
    float prevmaxFraction = 0.0f;
    vector<int> MaxVertices;
    vector<int>::iterator itrTempIndi;
    // Consider each triangle
    int nTrgCnt = 1;
    while( nTrgCnt <= nTriangleCount )
    {
        vector<int> TempIndices;
        itrTempIndi = TempIndices.begin();
        for( int i = 0; i < nTrgCnt; i++ )
        {
            TempIndices.insert( itrTempIndi, AllVertices[i].begin(), AllVertices[i].end());
            itrTempIndi = TempIndices.begin() + ( TempIndices.size() );
        }
        sort( TempIndices.begin(), TempIndices.end());
        itrTempIndi = unique( TempIndices.begin(), TempIndices.end());
        TempIndices.resize( distance( TempIndices.begin(), itrTempIndi ));
        prevmaxFraction = maximalFraction;
        maximalFraction = float( nTrgCnt ) / TempIndices.size();
        if( maximalFraction > prevmaxFraction )
        {
            MaxVertices = TempIndices;
        }
        nTrgCnt++;
    }

    cout << MaxVertices.size() << endl;
    int nSize = MaxVertices.size();
    for( int i = 0; i < nSize; i++ )
    {
        cout << (MaxVertices[i] + 1) << " ";
    }

    return 0;
}
