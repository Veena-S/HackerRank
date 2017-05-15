#include <iostream>
#include <string>
#include <bitset>

using namespace std;

string duplication(int index_i, string& strBinary_io, int nLength_i, bool bExpand_i )
{
    if( !bExpand_i )
    {
        return strBinary_io[index_i];
    }
    int nRequiredLength = index_i + 1;
    int nStartingIndex = nLength_i - 1;


}

int main()
{
    string test = "1001";
    bitset myBits = stoi




    int q;
    cin >> q;
    if( q < 0 || q > 1000 )
    {
        return 0;
    }
    string strBinary = "0";
    int nLength = 0;
    bool bExpand = false;
    for(int a0 = 0; a0 < q; a0++)
    {
        int x;
        cin >> x;
        if( x < 0 || x > 1000 )
        {
            return 0;
        }
        nLength = strBinary.length();
        bExpand = ( nLength >= ( x + 1 )) ? false : true;
        cout << duplication( x, strBinary, nLength, bExpand ) << endl;
    }
    return 0;
}
