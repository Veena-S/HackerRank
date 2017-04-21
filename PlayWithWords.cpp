/**
PLAY WITH WORDS

Problem Statement
-----------------

Shaka and his brother have created a boring game which is played like this:

They take a word composed of lowercase English letters and try to get the maximum possible score by building 
exactly 2 palindromic subsequences. The score obtained is the product of these 2 subsequences.

Let's say A and B are two subsequences from the initial string. If Ai & Aj are the smallest and the largest
positions (from the initial word) respectively in A ; and Bi & Bj are the smallest and the largest positions 
(from the initial word) respectively in B, then the following statements hold true:

Ai=Aj, 
Bi=Bj, & 
Aj<Bi. 
i.e., the positions of the subsequences should not cross over each other.

Hence the score obtained is the product of lengths of subsequences A & B. Such subsequences can be numerous 
for a larger initial word, and hence it becomes harder to find out the maximum possible score. 
Can you help Shaka and his brother find this out?

Input Format 
Input contains a word S composed of lowercase English letters in a single line.

Output Format 
Output the maximum score the boys can get from S.

Constraints 
1<|S|=3000 
each character will be a lower case English alphabet.

Sample Input:
eeegeeksforskeeggeeks

Sample Output:
50

Explanation
A possible optimal solution is eee-g-ee-ksfor-skeeggeeks being eeeee the one subsequence and skeeggeeks the other one
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>
#include <string>
#include "Windows.h"

using namespace std;

const UINT MIN_PALIN_LENGTH = 2U;


class PalindromeExtractor
{
public:

    PalindromeExtractor() : m_strFullSequence( "" )
    {

    }

    PalindromeExtractor( const string strInputSequence_i ) : m_strFullSequence( strInputSequence_i )
    {

    }

    ~PalindromeExtractor()
    {

    }

    bool ExtractPalindromes()
    {
        try
        {
            FindPalindromeSubSequences();
        }
        catch( ... )
        {
            return false;
        }
        return true;
    }


private:

    bool FindPalindromeSubSequences()
    {
        size_t uFullLen = m_strFullSequence.length();

        vector<string> TestStringVector;

        // Starting from the first letter, combined with each and every letter followed, check 
        // for palindrome.
        // Combine each and every letter
        // At first the increment will be by one letter
        // Then by two letters and so on
        size_t uIncrementor = 1;
        size_t uTestIncrementor = 1;
        string strTestData = "";
        size_t uTestDataLen = 0;
        string strProcData = "";
        for( size_t uIndex = 0; uIndex < uFullLen; uIndex++ )
        {
            for( size_t uSubIndex = uIndex + 1; uSubIndex < uFullLen; )
            {
                strTestData = m_strFullSequence.substr( uIndex, ( uSubIndex - uIndex + 1 ));
                TestStringVector.push_back( strTestData );
                cout << strTestData << "\n";

                // From this test data, check for palindrome by removing characters,
                // except the first character
                uTestDataLen = strTestData.length();

                while( uTestIncrementor <= uTestDataLen )
                {
                    strProcData = strTestData;
                    for( size_t uTestIndex = 1; uTestIndex < uTestDataLen; ++uTestIndex )
                    {
                        strProcData.erase( uTestIndex, uTestIncrementor );

                        TestStringVector.push_back( strProcData );
                        cout << strProcData << "\n";

                        strProcData = strTestData;
                    }
                    ++uTestIncrementor;
                }


                ++uIncrementor;
                 uSubIndex = uIndex + uIncrementor;
            }
            uIncrementor = 1;
        }

        return true;
    }


    bool IsPalindrome( const string& strData_i )
    {
        bool bPalindrome = false;
        string strCopy( strData_i.rbegin(), strData_i.rend() );
        if( 0 == strData_i.compare( strCopy ))
        {
            bPalindrome = true;
        }
        return bPalindrome;
    }

    PalindromeExtractor( const PalindromeExtractor& );
    PalindromeExtractor& operator = ( const PalindromeExtractor& );

private:

    string m_strFullSequence;

};



int main()
{
    string strInput = "";
    getline( cin, strInput );
    /*
    Constraints 
    1<|S|=3000 
    each character will be a lower case English alphabet.
    */
    string strLowerInput = strInput;
    std::transform( strLowerInput.begin(), strLowerInput.end(), strLowerInput.begin(), ::tolower );
    // Compare them
    if( strInput != strLowerInput )
    {
        return 0;
    }
    size_t uLen = strInput.length();
    if(( uLen > 3000 ) || ( uLen < 1 ))
    {
        return 0;
    }

    PalindromeExtractor PalinExtract( strInput );
    PalinExtract.ExtractPalindromes();
}
