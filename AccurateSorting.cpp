#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int q;
	cin >> q;
	if( q < 1 || q > 10 )
	{
		return 0;
	}
	int nNSum = 0;
	for( int a0 = 0; a0 < q; a0++ )
	{
		int n;
		cin >> n;
		if( n < 1 || n > 100000 )
		{
			return 0;
		}
		nNSum += n;
		if( nNSum > 100000 )
		{
			return 0;
		}
		vector<int> a( n );
		int nPrev = -1;
		int nCurr = -1;
		//for( int a_i = 0; a_i < n; a_i++ )
		//{
		//	cin >> a[a_i];
		//}
		int nEle = 0;
		bool bIsSorted = false;
		int nDiff = 0;
		cin >> nCurr;
		nPrev = nCurr;
		for( int i = 1; i < n; i++ )
		{
			cin >> nCurr;
			nDiff = nPrev - nCurr;
			if( 1 == nDiff )
			{
				// Swapping is possible
				a[i - 1] = nCurr;
				nEle = nPrev;
			}
			else
			{
				a[i - 1] = nPrev;
				nPrev = nCurr;
				nEle = nCurr;
			}

		}
		a[n - 1] = nEle;

		if( is_sorted( a.begin(), a.end() ) )
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}

		// TO DELETE
		cout << "Final Sequence: ";
		for( int i = 0; i < a.size(); i++ )
		{
			cout << a[i] << "  ";
		}
		cout << endl;
	}
	return 0;
}
