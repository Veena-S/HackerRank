#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    if( n < 2 || n > 50 )
    {
        return 0;
    }

    string output = "";
    string closingBrace = "";
    for( int i = 1; i < n; i++ )
    {
        output += "min(int, ";
        closingBrace += ")";
    }
    output += "int" + closingBrace;

    cout << output;


    return 0;
}