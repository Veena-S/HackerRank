/*
< 10
multiples of 3 or 5
3 5 6 9
Sum = 3+5+6+9 = 23

Find the sum of all the multiples of 3 or 5 under N

T testcases
T lines with integer N

1 <= T <= 10^5
1 <= N <= 10^9


< 1000 = S=2318


*/

#include <iostream>

int main()
{
	unsigned long N, T = 0;
	std::cin >> T;
	if( T < 1 || T > 10^5)
	{
		return 0;
	}
	for( unsigned long i : T )
	{
		std::cin >> N;
		if( N < 1 || N > 10^9)
		{
			return 0;
		}
		unsigned long ulMaxRValue_3 = N / 3;
		ulMaxRValue_3 = ( 0 == (N % 3 )) ? (ulMaxRValue_3 - 1 ) : ulMaxRValue_3;
		unsigned long ulMaxRValue_5 = N / 5;
		ulMaxRValue_5 = ( 0 == (N % 5 )) ? (ulMaxRValue_5 - 1 ) : ulMaxRValue_5;
		
		unsigned long long ullSum = 0;
		for( auto i_3 : ulMaxRValue_3 )
		{
			ullSum += ( 3 * i_3 );
		}
		for( auto i_5 : ulMaxRValue_5 )
		{
			ullSum += ( 5 * i_5 );
		}
		std::cout << ullSum << std::endl;		
	}	
	return 0;
}

/*
< 10 = by 3: 3, 6, 9 (3x1, 3x2, 3x3)
       by 5: 5
	10/3 = 3; 10%3=1
	10/5 = 2; 10%2=0
	  
if there is remainder it means, the quotient can be included i.e. till 3 or 5 x quotient
if there is no remainder, minus 1 from the quotient. i.e. till 3 or 5 x (quotient - 1)	  
	   
	   
< 20 = by 3: 3, 6, 9, 12, 15, 18 (3x1, 3x2, 3x3, 3x4, 3x5, 3x6)
       by 5: 5, 10, 15 (5x1, 5x2, 5x3)
	   
< 22 = by 3: 3, 6, 9, 12, 15, 18, 21 (3x1, 3x2, 3x3, 3x4, 3x5, 3x6, 3x7)
       by 5: 5, 10, 15, 20 (5x1, 5x2, 5x3, 5x4)

	 22/3=7,1
22/5=4,2	 

*/
