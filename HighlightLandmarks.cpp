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

int main()
{
	string description;
	getline( cin, description );
	int d = description.size();
	if( d > 2500 )
	{
		return 0;
	}
	int nLandmarks;
	cin >> nLandmarks;
	if( nLandmarks < 1 || nLandmarks > 100 )
	{
		return 0;
	}
	cin.ignore( std::numeric_limits<streamsize>::max(), '\n' );
	string strLM;
	string landmarkstrings;
	getline( cin, landmarkstrings );
	if( 0 == landmarkstrings.length() )
	{
		return 0;
	}
	char space = ' ';
	int nCount = std::count( landmarkstrings.begin(), landmarkstrings.end(), space );
	nCount++;
	if( nCount < 1 || nCount > 100 )
	{
		return 0;
	}
	size_t nFind;
	string start = "<b>";
	string end = "</b>";
	int nEnd = end.length();
	int nOffset = 0;

	string strDesc;
	vector<string> DescVctr;

	for( stringstream desc( description ); desc >> strDesc; )
	{
		bool bFind = false;
		for( stringstream ss( landmarkstrings ); ss >> strLM; )
		{
			if( strDesc == strLM )
			{
				bFind = true;
				break;
			}
		}
		if( bFind )
		{
			DescVctr.push_back( start + strDesc + end );
		}
		else
		{
			DescVctr.push_back( strDesc );
		}
	}

	int size = DescVctr.size();
	description.clear();
	for( int i = 0; i < size; i++ )
	{
		description += DescVctr[i] + " ";
	}
	description.erase( description.end() - 1 );
	


	//for( stringstream ss( landmarkstrings ); ss >> strLM; )
	//{
	//	int nLen = strLM.size();
	//	nFind = description.find( strLM );
	//	while( string::npos != nFind )
	//	{
	//		// Insert the start and end
	//		description.insert( nFind + nLen, end );
	//		description.insert( nFind, start );
	//		nFind = description.find( strLM, nFind + nLen + nEnd );
	//	}
	//	nCount++;
	//	if( nCount > 100 )
	//	{
	//		return 0;
	//	}
	//}


	//size_t nSpaceLoc = landmarkstrings.find( " " );
	
	//while( nSpaceLoc != string::npos )
	//{
	//	strLM = landmarkstrings.substr( nOffset, nSpaceLoc - nOffset );
	//	int nLen = strLM.size();
	//	nFind = description.find( strLM );
	//	while( string::npos != nFind )
	//	{
	//		// Insert the start and end
	//		description.insert( nFind + nLen, end );
	//		description.insert( nFind, start );
	//		nFind = description.find( strLM, nFind + nLen + nEnd );
	//	}
	//	nCount++;
	//	if( nCount > 100 )
	//	{
	//		return 0;
	//	}
	//	nOffset += nSpaceLoc + 1;
	//	nSpaceLoc = landmarkstrings.find( " ", nOffset );
	//}


	//while( cin >> strLM )
	//{
	//	// cin >> strLM;
		//int nLen = strLM.size();
		//nFind = description.find( strLM );
		//while( string::npos != nFind )
		//{
		//	// Insert the start and end
		//	description.insert( nFind + nLen, end );
		//	description.insert( nFind, start );
		//	nFind = description.find( strLM, nFind + nLen + nEnd );
		//}
		//nCount++;
		//if( nCount > 100 )
		//{
		//	return 0;
		//}
	//}


	/*if( nCount < 1 )
	{
		return 0;
	}*/
	
	cout << description;

	return 0;
}
