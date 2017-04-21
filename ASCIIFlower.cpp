#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int r;
    int c;
    cin >> r >> c;
    if( r < 1 || c < 1 || r > 20 || c > 20 )
    {
        return 0;
    }
    // Single flower pattern
    string F = "..O..";
    string SE = "O.o.O";
    string s1;
    string s2;

    for( int j = 0; j < c; j++ )
    {
        s1 += F;
        s2 += SE;
    }
    vector<string> flower;
    flower.push_back( s1 );
    flower.push_back( s2 );
    flower.push_back( s1 );

    for( int i = 0; i < r; i++ )
    {
        cout << flower[0] << endl;
        cout << flower[1] << endl;
        cout << flower[2] << endl;
    }

    return 0;
}

