// 2DMatrixRotation.cpp : Defines the entry point for the console application.
//
/*
You are given a 2D matrix of dimension  and a positive integer .
You have to rotate the matrix  times and print the resultant matrix. Rotation should be in anti-clockwise direction.

Rotation of a  matrix is represented by the following figure. 
Note that in one rotation, you have to shift elements by one step only.
It is guaranteed that the minimum of m and n will be even.
As an example rotate the Start matrix by 2:

Start         	First                Second
1 2 3 4        2  3   4  5          3  4  5   6
12 1 2 5  ->    1  2   3  6 	->   2  3  4   7
11 4 3 6        12 1   4  7          1  2  1   8
10 9 8 7        11 10  9  8          12 11 10  9

Function Description
Complete the matrixRotation function. It should print the resultant 2D integer array and return nothing.
matrixRotation has the following parameter(s):
matrix: a 2D array of integers
r: an integer that represents the rotation factor

Input Format:
The first line contains three space separated integers, , , and , the number of rows and columns in , and the required rotation. 
The next  lines contain  space-separated integers representing the elements of a row of .
Constraints
2 <= m, n <= 300
1 <= r <= 10^9
min(m.n)%2==0
1 <= a(i,j) <= 10^8 where i[1...m] and j[1...n]

Output Format
Print each row of the rotated matrix as space-separated integers on separate lines.

Sample Input
Sample Input #01
4  4  2 // m,n,r
1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16
Sample Output #01
3 4 8 12
2 11 10 16
1 7 6 15
5 9 13 14
Explanation #01
The matrix is rotated through two rotations.
1  2  3  4      2  3  4  8      3  4  8 12
5  6  7  8      1  7 11 12      2 11 10 16
9 10 11 12  ->  5  6 10 16  ->  1  7  6 15
13 14 15 16      9 13 14 15      5  9 13 14
Sample Input #02
5 4 7
1 2 3 4
7 8 9 10
13 14 15 16
19 20 21 22
25 26 27 28
Sample Output #02
28 27 26 25
22 9 15 19
16 8 21 13
10 14 20 7
4 3 2 1
Explanation 02
The various states through 7 rotations:
1  2  3  4           2  3  4 10    3  4 10 16    4 10 16 22
7  8  9 10         1  9 15 16    2 15 21 22    3 21 20 28
13 14 15 16 ->  7  8 21 22 -> 1  9 20 28 -> 2 15 14 27 ->
19 20 21 22    13 14 20 28    7  8 14 27    1  9  8 26
25 26 27 28    19 25 26 27    13 19 25 26   7 13 19 25

10 16 22 28    16 22 28 27    22 28 27 26    28 27 26 25
4 20 14 27    10 14  8 26    16  8  9 25    22  9 15 19
3 21  8 26 ->  4 20  9 25 -> 10 14 15 19 -> 16  8 21 13
2 15  9 25     3 21 15 19     4 20 21 13    10 14 20  7
1  7 13 19     2  1  7 13     3  2  1  7     4  3  2  1
Sample Input #03
2 2 3
1 1
1 1
Sample Output #03
1 1
1 1
Explanation #03
All of the elements are the same, so any rotation will repeat the same matrix.


*/

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <functional>


using namespace std;


string ltrim( const string & );
string rtrim( const string & );
vector<string> split( const string & );

void PrintVector( vector<int> vec )
{
    for( auto val : vec )
    {
        std::cout << val << " ";
    }
}

void PrintMatrix( vector<vector<int>> matrix )
{

    for( auto row : matrix )
    {
        for( auto col : row )
        {
            std::cout << col << " ";
        }
        std::cout << endl;
    }
}

void matrixRotation_p3( vector<vector<int>> matrix, int r )
{
    const unsigned int unInitialRow = matrix.size();
    const unsigned int unInitialCol = matrix.begin()->size();

    unsigned int unMinimum = /*std::*/min( unInitialRow, unInitialCol );
    if( 0 != ( unMinimum % 2 ) )
    {
        return;
    }
    bool bIsRow = ( unInitialRow == unMinimum ) ? true : false;
    unMinimum /= 2;

    unsigned int unFirstRowIdx = 0;
    unsigned int unFirstColIdx = 0;
    unsigned int unLastRowIdx = unInitialRow - 1;
    unsigned int unLastColIdx = unInitialCol - 1;

    unsigned int unIterCount = 0;
    while( unIterCount < unMinimum )
    {
        int nTempCount = 0;
        unsigned int unRowIdx = unFirstRowIdx;
        unsigned int unColIdx = unFirstColIdx;

        for( int nRot = r; nRot > 0; --nRot )
        {
        }
        ++unIterCount;
        ++unFirstRowIdx;
        ++unFirstColIdx;
        --unLastRowIdx;
        --unLastColIdx;
    }
}


void matrixRotation_p2( vector<vector<int>> matrix, int r )
{
    const unsigned int unInitialRow = matrix.size();
    const unsigned int unInitialCol = matrix.begin()->size();
    
    unsigned int unMinimum = /*std::*/min( unInitialRow, unInitialCol );
    if( 0 != ( unMinimum % 2 ) )
    {
        return;
    }
    bool bIsRow = ( unInitialRow == unMinimum ) ? true : false;
    unMinimum /= 2;

    unsigned int unFirstRowIdx = 0;
    unsigned int unFirstColIdx = 0;
    unsigned int unLastRowIdx = unInitialRow - 1;
    unsigned int unLastColIdx = unInitialCol - 1;

    unsigned int unIterCount = 0;
    while( unIterCount < unMinimum )
    {
        int nTempCount = 0;
        unsigned int unRowIdx = unFirstRowIdx;
        unsigned int unColIdx = unFirstColIdx;

        for( int nRot = r; nRot > 0; --nRot )
        {
            int nReplaceItem = matrix[ unFirstRowIdx ][ unFirstColIdx ];
            // upper row
            for( unColIdx = unFirstColIdx; unColIdx < unLastColIdx; ++unColIdx )
            {
                matrix[ unFirstRowIdx ][ unColIdx ] = matrix[ unFirstRowIdx ][ unColIdx + 1 ];
            }
            // right column
            for( unsigned int nRIdx = unFirstRowIdx; nRIdx < unLastRowIdx; ++nRIdx )
            {
                matrix[ nRIdx ][ unLastColIdx ] = matrix[ nRIdx + 1 ][ unLastColIdx ];
            }
            // bottom row
            for( unColIdx = unLastColIdx; unColIdx > unFirstColIdx; --unColIdx )
            {
                matrix[ unLastRowIdx ][ unColIdx ] = matrix[ unLastRowIdx ][ unColIdx - 1 ];
            }
            // Left Column
            for( unRowIdx = unLastRowIdx; unRowIdx > ( unFirstRowIdx + 1 ); --unRowIdx )
            {
                matrix[ unRowIdx ][ unFirstColIdx ] = matrix[ unRowIdx - 1 ][ unFirstColIdx ];
            }
            matrix[ unFirstRowIdx + 1 ][ unFirstColIdx ] = nReplaceItem;

            //nTempCount++;

            //std::cout << "Matrix: iteration = " << unIterCount << " Roation: " << nTempCount << std::endl;
            //PrintMatrix( matrix );
            //std::cout << std::endl;
        }
        ++unIterCount;
        ++unFirstRowIdx;
        ++unFirstColIdx;
        --unLastRowIdx;
        --unLastColIdx;
    }

}


void matrixRotation_Perf( vector<vector<int>> matrix, int r )
{
    vector<vector<int>> TempMatrix;

    const unsigned int unInitialRow = matrix.size();
    const unsigned int unInitialCol = matrix.begin()->size();

    TempMatrix.resize( unInitialRow );

    for( auto row : TempMatrix )
    {
        row.resize( unInitialCol );
    }
    TempMatrix = matrix;

    unsigned int unMinimum = /*std::*/min( unInitialRow, unInitialCol );
    if( 0 != ( unMinimum % 2 ) )
    {
        return;
    }
    bool bIsRow = ( unInitialRow == unMinimum ) ? true : false;
    unMinimum /= 2;

    int nRotationCnt = 0;

    //std::cout << "Original Matrix :" << std::endl;
    //PrintMatrix( matrix );

    while( nRotationCnt < r )
    {
        unsigned int unFirstRowIdx = 0;
        unsigned int unFirstColIdx = 0;
        unsigned int unLastRowIdx = unInitialRow - 1;
        unsigned int unLastColIdx = unInitialCol - 1;

        unsigned int unTempRowIdx = 0;
        unsigned int unTempColIdx = 0;

        //std::cout << "Rotation Number: " << nRotationCnt + 1 << std::endl;

        unsigned int unIterCount = 0;
        while( unIterCount < unMinimum )
        {
            // Identify TopRow
            unsigned int unRowIdx = unFirstRowIdx;
            unsigned int unColIdx = unFirstColIdx;

            unTempRowIdx = unFirstRowIdx;
            unTempColIdx = unFirstColIdx;
            
            if( unRowIdx <= unLastRowIdx )
            { // all the elements in the first row excluding the first col element
                for( unColIdx = unFirstColIdx + 1; unColIdx <= unLastColIdx; ++unColIdx )
                {
                    TempMatrix[unTempRowIdx][unTempColIdx++] = matrix[ unRowIdx ][ unColIdx ];
                }
            }
            // + get the last col element of the next row
            if( ( unRowIdx + 1 ) <= unLastRowIdx )
            {
                TempMatrix[ unTempRowIdx ][ unTempColIdx++ ] = matrix[ unRowIdx + 1 ][ unLastColIdx ] ;
            }

            // Identify the Left column ( excluding those elements that are present in the first and last rows)
            unColIdx = unFirstColIdx;
            unTempRowIdx++;
            unTempColIdx = unFirstColIdx;
            for( unRowIdx = unFirstRowIdx; unRowIdx </*=*/ unLastRowIdx - 1; ++unRowIdx )
            {
                TempMatrix[unTempRowIdx++][unTempColIdx] = matrix[ unRowIdx ][ unColIdx ];
            }
            // Identifying the bottom row
            // Add the remaining elements in the first colum to bottom row
            unTempRowIdx = unLastRowIdx;
            unTempColIdx = unFirstColIdx;
            for( ; unRowIdx <= unLastRowIdx; ++unRowIdx )
            {
                TempMatrix[unTempRowIdx][unTempColIdx++] = matrix[ unRowIdx ][ unColIdx ];
            }
            // Add the elements of the last row excluding the first col element (which is already added ) and
            // the element in the last column (which will be added with rightcolum)
            unRowIdx = unLastRowIdx;
            unColIdx++;
            if( unColIdx <= unLastColIdx )
            {
                for( ; unColIdx <= unLastColIdx - 1; ++unColIdx )
                {
                    TempMatrix[ unTempRowIdx ][ unTempColIdx++ ] = matrix[ unRowIdx ][ unColIdx ];
                }
            }

            // identify the elements in the Right Column
            // Last colum elements starting from the second row
            unColIdx = unLastColIdx;
            unRowIdx = unFirstRowIdx + 1;
            ++unRowIdx;
            unTempRowIdx = unFirstRowIdx + 1;
            unTempColIdx = unLastColIdx;
            for( ; unRowIdx <= unLastRowIdx; ++unRowIdx )
            {
                TempMatrix[unTempRowIdx++][unTempColIdx] = matrix[ unRowIdx ][ unColIdx ];
            }

            //std::cout << "Temp Matrix: " << std::endl;
            //PrintMatrix( TempMatrix );

            ++unIterCount;
            ++unFirstRowIdx;
            ++unFirstColIdx;
            --unLastRowIdx;
            --unLastColIdx;
        }

        matrix = TempMatrix;

        //std::cout << "Rotated Matrix: " << std::endl;
        //PrintMatrix( matrix );


        ++nRotationCnt;
    }

//    std::cout << "Final Rotated Matrix: " << std::endl;
    //PrintMatrix( matrix );
}


// Complete the matrixRotation function below.
// Working but performance fails
void matrixRotation( vector<vector<int>> matrix, int r )
{
    const unsigned int unInitialRow = matrix.size();
    const unsigned int unInitialCol = matrix.begin()->size();

    unsigned int unMinimum = /*std::*/min( unInitialRow, unInitialCol );
    if( 0 != ( unMinimum % 2 ) )
    {
        return;
    }
    bool bIsRow = ( unInitialRow == unMinimum ) ? true : false;
    unMinimum /= 2;

    int nRotationCnt = 0;
    

    //std::cout << "Original Matrix :" << std::endl;
    //PrintMatrix( matrix );
    
    while( nRotationCnt < r )
    {
        unsigned int unFirstRowIdx = 0;
        unsigned int unFirstColIdx = 0;
        unsigned int unLastRowIdx = unInitialRow - 1;
        unsigned int unLastColIdx = unInitialCol - 1;

        //std::cout << "Rotation Number: " << nRotationCnt + 1 << std::endl;

        unsigned int unIterCount = 0;
        while( unIterCount < unMinimum )
        {
            vector<int> TopRow, BottomRow, LeftCol, RightCol;

            // Identify TopRow
            unsigned int unRowIdx = unFirstRowIdx;
            unsigned int unColIdx = unFirstColIdx;
            if( unRowIdx <= unLastRowIdx )
            { // all the elements in the first row excluding the first col element
                for( unColIdx = unFirstColIdx + 1; unColIdx <= unLastColIdx; ++unColIdx )
                {
                    TopRow.push_back( matrix[ unRowIdx ][ unColIdx ] );
                }
            }
            // + get the last col element of the next row
            if( ( unRowIdx + 1 ) <= unLastRowIdx )
            {
                TopRow.push_back( matrix[ unRowIdx + 1 ][ unLastColIdx ] );
            }

            // Identify the Left column ( excluding those elements that are present in the first and last rows)
            unColIdx = unFirstColIdx;
            for( unRowIdx = unFirstRowIdx; unRowIdx </*=*/ unLastRowIdx - 1; ++unRowIdx )
            {
                LeftCol.push_back( matrix[ unRowIdx ][ unColIdx ] );
            }
            // Identifying the bottom row
            // Add the remaining elements in the first colum to bottom row
            for( ; unRowIdx <= unLastRowIdx; ++unRowIdx )
            {
                BottomRow.push_back( matrix[ unRowIdx ][ unColIdx ] );
            }
            // Add the elements of the last row excluding the first col element (which is already added ) and
            // the element in the last column (which will be added with rightcolum)
            unRowIdx = unLastRowIdx;
            unColIdx++;
            if( unColIdx <= unLastColIdx )
            {
                for( ; unColIdx <= unLastColIdx - 1; ++unColIdx )
                {
                    BottomRow.push_back( matrix[ unRowIdx ][ unColIdx ] );
                }
            }

            // identify the elements in the Right Column
            // Last colum elements starting from the second row
            unColIdx = unLastColIdx;
            unRowIdx = unFirstRowIdx + 1;
            ++unRowIdx;
            for( ;unRowIdx <= unLastRowIdx; ++unRowIdx )
            {
                RightCol.push_back( matrix[ unRowIdx ][ unColIdx ] );
            }
            //// Last rows second last element
            //unColIdx--;
            //if( unColIdx < unLastColIdx )
            //{
            //    RightCol.push_back( matrix[ unLastRowIdx ][ unColIdx ] );
            //}
/*
            std::cout << "Square Number: " << unIterCount + 1 << std::endl;
            std::cout << std::endl;
            std::cout << "TopRow: " << std::endl;
            PrintVector( TopRow );
            std::cout << std::endl;
            std::cout << "LeftCol: " << std::endl;
            PrintVector( LeftCol );
            std::cout << std::endl;
            std::cout << "BottomRow: " << std::endl;
            PrintVector( BottomRow );
            std::cout << std::endl;
            std::cout << "RightCol: " << std::endl;
            PrintVector( RightCol );
            std::cout << std::endl;*/


            // Update the original matrix
            // Update the top row
            unRowIdx = unFirstRowIdx;
            unsigned int unIndex = 0;
            for( unColIdx = unFirstColIdx; unColIdx <= unLastColIdx; ++unColIdx )
            {
                matrix[ unRowIdx ][ unColIdx ] = TopRow[ unIndex++ ];
            }
            // update the left column excluding first and last rows
            unRowIdx++;
            unColIdx = unFirstColIdx;
            unIndex = 0;
            for( ; unRowIdx <= unLastRowIdx - 1; ++unRowIdx )
            {
                matrix[ unRowIdx ][ unColIdx ] = LeftCol[ unIndex++ ];
            }
            // Update the bottom row
            unIndex = 0;
            unRowIdx = unLastRowIdx;
            for( unColIdx = unFirstColIdx; unColIdx <= unLastColIdx; ++unColIdx )
            {
                matrix[ unRowIdx ][ unColIdx ] = BottomRow[ unIndex++ ];
            }

            // Update the Right colum excluding first and last rows
            unRowIdx = unFirstRowIdx + 1;
            unColIdx = unLastColIdx;
            unIndex = 0;
            for( ; unRowIdx <= unLastRowIdx - 1; ++unRowIdx )
            {
                matrix[ unRowIdx ][ unColIdx ] = RightCol[ unIndex++ ];
            }

            //std::cout << "Matrix: " << std::endl;
            //PrintMatrix( matrix );

            ++unIterCount;
            ++unFirstRowIdx;
            ++unFirstColIdx;
            --unLastRowIdx;
            --unLastColIdx;
        }

        ++nRotationCnt;
    }

    PrintMatrix( matrix );
}

int main()
{
    string mnr_temp;
    getline( cin, mnr_temp );

    vector<string> mnr = split( rtrim( mnr_temp ) );

    int m = stoi( mnr[ 0 ] );

    int n = stoi( mnr[ 1 ] );

    int r = stoi( mnr[ 2 ] );


    //Constraints
    //    2 <= m, n <= 300
    //    1 <= r <= 10 ^ 9
    //    min( m.n ) % 2 == 0
    //    1 <= a( i, j ) <= 10 ^ 8 where i[ 1...m ] and j[ 1...n ]

    if( m < 2 || m > 300 || n < 2 || n > 300 || r < 1 || r > 1000000000 )
    {
        return 0;
    }


    vector<vector<int>> matrix( m );

    for( int i = 0; i < m; i++ )
    {
        matrix[ i ].resize( n );

        string matrix_row_temp_temp;
        getline( cin, matrix_row_temp_temp );

        vector<string> matrix_row_temp = split( rtrim( matrix_row_temp_temp ) );

        for( int j = 0; j < n; j++ )
        {
            int matrix_row_item = stoi( matrix_row_temp[ j ] );

            if( matrix_row_item < 1 || matrix_row_item > 100000000 )
            {
                return 0;
            }

            matrix[ i ][ j ] = matrix_row_item;
        }
    }

    matrixRotation_p2( matrix, r );

//    matrixRotation_Perf( matrix, r );
//    matrixRotation( matrix, r );
//
//
//matrixRotation_Perf( matrix, r );
//    matrixRotation( matrix, r );
//matrixRotation_Perf( matrix, r );
//    matrixRotation( matrix, r );

    return 0;
}

string ltrim( const string &str )
{
    string s( str );

    s.erase(
        s.begin(),
        find_if( s.begin(), s.end(), not1( ptr_fun<int, int>( isspace ) ) )
    );

    return s;
}

string rtrim( const string &str )
{
    string s( str );

    s.erase(
        find_if( s.rbegin(), s.rend(), not1( ptr_fun<int, int>( isspace ) ) ).base(),
        s.end()
    );

    return s;
}

vector<string> split( const string &str )
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while( ( end = str.find( " ", start ) ) != string::npos )
    {
        tokens.push_back( str.substr( start, end - start ) );

        start = end + 1;
    }

    tokens.push_back( str.substr( start ) );

    return tokens;
}
