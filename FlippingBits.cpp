#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;


int main()
{
    int nListCount = 0;
    // vector<unsigned int> UIntVectorInput; // 32 bit unsigned integer vector
    cin >> nListCount;
    unsigned int nInput = 0;
    for( int i = 0; i < nListCount; i++ )
    {
        cin >> nInput;
        bitset<32> bInp( nInput );
        bInp.flip();
        // UIntVectorInput.push_back( static_cast<unsigned int>( bInp.to_ulong()));
        cout << static_cast< unsigned int >( bInp.to_ulong() ) << endl;
    }
    return 0;
}

