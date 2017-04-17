// BeautifulWord.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string w;
    cin >> w;
	int nLen = w.length();
	if( nLen < 1 || nLen > 100 )
	{
		return 0;
	}
	string strVowels = "aeiouy";
	char cCurrent;
	char cNext;
	int nNewLen = nLen - 1;
	for( int i = 0; i < nNewLen; i++ )
	{
		cCurrent = w[i];
		cNext = w[i + 1];
		// Check two consecutive are same or not
		if( cCurrent == cNext )
		{
			cout << "No";
			return 0;
		}
		// Check two consecutive characters are vowels or not
		else
		{
			if( string::npos != strVowels.find( cCurrent ))
			{
				if( string::npos != strVowels.find( cNext ) )
				{
					cout << "No";
					return 0;
				}
			}
		}
	}

	cout << "Yes";

    // Print 'Yes' if the word is beautiful or 'No' if it is not.
    return 0;
}


