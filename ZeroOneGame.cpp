#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
	int g;
	cin >> g;
	if( g < 1 || g > 10000 )
	{
		return 0;
	}
	int nNSum = 0;
	for( int a0 = 0; a0 < g; a0++ )
	{
		int n;
		cin >> n;
		if( n < 1 || n > 100000 )
		{
			return 0;
		}
		nNSum += n;
		if( nNSum > 1000000 )
		{
			return 0;
		}
//		vector<int> sequence( n );
		int nTemp;
		stringstream stream;
		for( int sequence_i = 0; sequence_i < n; sequence_i++ )
		{
			cin >> nTemp;
//			sequence[sequence_i] = nTemp;
			stream << nTemp;
		}
		string str = stream.str();
		// If Alice wins, print 'Alice' on a new line; otherwise, print 'Bob'

		// Search for the patterns 000 or 010 in the string
		const string PATTERN_000 = "000";
		const string PATTERN_010 = "010";
		bool bIsAliceTurn = true;
		int nFind = 0;
		int nLastElementIndex = n - 1;
		bool bIs000 = false;
		bool bIs010 = false;
		while( true )
		{
			nFind = str.find( PATTERN_000 );
			bIs000 = ( string::npos == nFind ) ? false : true;
			if( !bIs000 )
			{
				nFind = str.find( PATTERN_010 );
				bIs010 = ( nFind == string::npos ) ? false : true;
			}
			if( !bIs000 && !bIs010 )
			{
				break;
			}
			// Remove the 0 or 1 from the second position in the string.
			str.erase( ( nFind + 1 ), 1 );
			bIsAliceTurn = !bIsAliceTurn;
		}
		if( bIsAliceTurn )
		{
			cout << "Bob" << endl;
		}
		else
		{
			cout << "Alice" << endl;
		}
	}
	return 0;
}
