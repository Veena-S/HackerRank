#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	int t;
	cin >> t; // Number of teachers or classes
	if( t < 1 || t > 5 )
	{
		return 0;
	}
	int N = 0, G = 0;
	for( int a0 = 0; a0 < t; a0++ )
	{
		int n;
		cin >> n; // total number of students
		if( n < 1 || n > 100000 )
		{
			return 0;
		}
		N += n;
		if( N > 300000 )
		{
			return 0;
		}
		// Vector to store the votes done by each student
		vector<int> v( n );
		int nVotes = 0;
		int nMinus = n - 1;
		for( int v_i = 0; v_i < n; v_i++ )
		{
			cin >> nVotes;
			if( nVotes < 0 || nVotes > nMinus )
			{
				return 0;
			}
			v[v_i] = nVotes; // Vote done by each student
		}
		int g;
		cin >> g; // Number of groups
		if( g < 1 || g > 100000 )
		{
			return 0;
		}
		G += g;
		if( G > 300000 )
		{
			return 0;
		}
		int* VoteCount = new int[n];
		for( int a1 = 0; a1 < g; a1++ )
		{
			int l; // left index
			int r; // right index
			int x; // votes needed
			cin >> l >> r >> x;
			if( l < 0 || r < 0 || l > nMinus || r > nMinus || l > r )
			{
				return 0;
			}
			if( x < 1 || x > n )
			{
				return 0;
			}
			// Vector to store the number of votes received by each.
			memset( VoteCount, 0, n * sizeof( int ) );
			int nLeaderIndex = -1;
			for( int i = l; i <= r; i++ )
			{
				VoteCount[v[i]] += 1;
			}
			for( int i = l; i <= r; i++ )
			{
				int nNominee = v[i];
				int nVoteCount = VoteCount[nNominee];
				if( x == nVoteCount )
				{
					if( nLeaderIndex != -1 )
					{
						// There is already a member
						// Get the lowest index
						if( nLeaderIndex > nNominee )
						{
							nLeaderIndex = nNominee;
						}
					}
					else
					{
						nLeaderIndex = nNominee;
					}
				}
			}
			cout << nLeaderIndex << endl;
		}
		delete[] VoteCount;
		VoteCount = 0;
	}
	return 0;
}
