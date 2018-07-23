/*

*/



#include <iostream>
#include <string>
#include <vector>
#include <cmath>


/*

1000000000000           5
7326487324              570421
43584738497             449327201
8888888888              9091
99999999                137
9089876503              5987
93987923                93987923
12939879233             219319987


*/




enum PRIME_STATUS
{
    INVALID_NUMBER = -1,
    PRIME_NUMBER_ODD,
    PRIME_NUMBER_EVEN,
    COMPOSITE_ODD_NUMBER,
    COMPOSITE_EVEN_NUMBER    
};


PRIME_STATUS IsPrime(const unsigned long long ullNumber_i)
{
    if (ullNumber_i < 2)
    {
        return INVALID_NUMBER;
    }
    else if (ullNumber_i == 2)
    {
        // 2 is a prime number
        return PRIME_NUMBER_EVEN;
    }
    else if (0 == (ullNumber_i % 2))
    {
        // Because all even numbers other than 2 are not prime
        return COMPOSITE_EVEN_NUMBER;
    }
    else // all the odd numbers other than 1
    {
        unsigned long long ullIdx = 3;
        unsigned long long ullIncrement = 2;
        unsigned long long ulMaxLimit = std::sqrt(ullNumber_i);

        for (; ullIdx <= ulMaxLimit; )
        {
            // If the number is divisible by idx, it is not prime
            if (0 == (ullNumber_i % ullIdx))
            {
                return COMPOSITE_ODD_NUMBER;
            }
            ullIdx += ullIncrement;
        }
        // if the loop finishes, it is prime
        return PRIME_NUMBER_ODD;
    }
}



int main()
{
    signed long long T = 0;
    unsigned long long N = 0;
    std::cin >> T;
    if ((T < 1) || (T > 10))
    {
        return 0;
    }

    for (unsigned long long ullIdx = 0; ullIdx < T; ullIdx++)
    {
        std::cin >> N;

        if ((N < 10) || (N > 1000000000000))
        {
            break;
        }

        // Find the prime factors (factor that is a prime number) below N
        // Fundamental Arithmetic theorem: Any number can be represented as a product of prime numbers.

        //std::cout << "Before division by 2: " << N << std::endl;

        // Check whether the given number is divisble by 2
        unsigned nTwoCount = 0;
        while (true)
        {
            if (0 == (N % 2))
            {
                N /= 2;
                nTwoCount++;
            }
            else
            {
                break;
            }
        }


        //std::cout << "After all the divisions by 2: " << N << std::endl;

        // Check whether the given number is a prime.
        PRIME_STATUS ePrimeStatus = IsPrime(N);

        //std::cout << "Prime status returned for " << N << ": " << ePrimeStatus << std::endl;

        if ((PRIME_NUMBER_EVEN == ePrimeStatus) || (PRIME_NUMBER_ODD == ePrimeStatus))
        {
            std::cout << N << std::endl;
            continue;
        }

        // If the given number is not prime, get the factors of the number and check whether they are prime or not.
        // As we have to find the maximum prime factor, start from 3 (as 2 is already taken care of ),
        // and then proceed by odd numbers till the square root ceiling number
        // Logic: If any of the smallest number divides the given number and the quotient is a prime number, the quotient will
        // be the largest prime factor of the given number.

        long double ulSquareRoot = N;
        unsigned long long ulLastPerfectSqRt = ulSquareRoot;
        bool bIsPerfectSquare = true;
        while (bIsPerfectSquare)
        {
            ulLastPerfectSqRt = ulSquareRoot;
            ulSquareRoot = std::sqrt(ulSquareRoot);
            bIsPerfectSquare = (0 == (ulSquareRoot - (std::floor(ulSquareRoot)))) ? true : false;
        }

        //std::cout << "Last perfect square root: " << ulLastPerfectSqRt << std::endl;
        ePrimeStatus = IsPrime(ulLastPerfectSqRt);
        //std::cout << "Prime status returned for " << ulLastPerfectSqRt << ": " << ePrimeStatus << std::endl;
        if ((PRIME_NUMBER_EVEN == ePrimeStatus) || (PRIME_NUMBER_ODD == ePrimeStatus))
        {
            std::cout << ulLastPerfectSqRt << std::endl;
            continue;
        }


        unsigned long long ulRem = 0;
        unsigned long long ulQuotient = 0;
        unsigned long long ullMax =/* ulLastPerfectSqRt;*/ std::ceil(ulSquareRoot);

        // std::cout << "Maximum limit of the divisor: " << ullMax << std::endl;

        bool bPrimeFound = false;
        unsigned long long ulMaxPrimeFactor = 1;
        for (unsigned long long ulDivisor = 3; ulDivisor <= ullMax; )
        {
           // std::cout << "In loop. Current divisor: " << ulDivisor << std::endl;

            ulRem = N % ulDivisor;
            if (0 != ulRem)	// Not a factor
            {
                ulDivisor += 2;
                continue;
            }

            //std::cout << "Completely divisible by: " << ulDivisor << std::endl;

            // If the given number is divisible by the current number, 
            // check whether the quotient it is prime or not
            ulQuotient = N / ulDivisor;
            ePrimeStatus = IsPrime(ulQuotient);
            if ((PRIME_NUMBER_EVEN == ePrimeStatus) || (PRIME_NUMBER_ODD == ePrimeStatus))
            {
                ulMaxPrimeFactor = (ulQuotient > ulMaxPrimeFactor) ? ulQuotient : ulMaxPrimeFactor;
                bPrimeFound = true;
                break;
            }
            ePrimeStatus = IsPrime(ulDivisor);
            if ((PRIME_NUMBER_EVEN == ePrimeStatus) || (PRIME_NUMBER_ODD == ePrimeStatus))
            {
                ulMaxPrimeFactor = (ulDivisor > ulMaxPrimeFactor) ? ulDivisor : ulMaxPrimeFactor;
                bPrimeFound = true;
                ulDivisor = 3;
                N = ulQuotient;
                ullMax = std::ceil(std::sqrt(N));
            }            
            else
            {
                ulDivisor += 2;
            }

        }
        if (bPrimeFound)
        {
            std::cout << ulMaxPrimeFactor << std::endl;
        }
        if (!bPrimeFound && (nTwoCount != 0))
        {
            std::cout << 2 << std::endl;
        }
    }



    //for (unsigned long long ullIdx = 0; ullIdx < T; ullIdx++)
    //{
    //    std::cin >> N;

    //    if ((N < 10) || (N > 1000000000000))
    //    {
    //        break;
    //    }

    //    // Find the prime factors (factor that is a prime number) below N
    //    // Fundamental Arithmetic theorem: Any number can be represented as a product of prime numbers.

    //    // Check whether the given number is a prime.
    //    bool bIsPrime = IsPrime(N);
    //    if (bIsPrime)
    //    {
    //        std::cout << N;
    //        continue;
    //    }

    //    // If the given number is not prime, get the factors of the number and check whether they are prime or not.
    //    // As we have to find the maximum prime factor, start from the biggest factor.
    //    // Start from the square root of the number.
    //    // unsigned long long ullMax = N / 2;
    //    unsigned long long ullMax = N;
    //    if (0 != (ullMax % 2))
    //    {
    //        ullMax /= 2;
    //    }
    //    else
    //    {
    //        while (true)
    //        {
    //            ullMax /= 2;
    //            if (0 != (ullMax % 2))
    //            {
    //                break;
    //            }                
    //        };
    //    }
    //    unsigned long long ullMin = 0;
    //    unsigned long long ulRem = 0;
    //    unsigned long long ulQuotient = 0;
    //    unsigned long long ulMaxPrimeFactor = 1;
    //    bIsPrime = false;

    //    for (unsigned long long ulDivisor = ullMax; ulDivisor > ullMin; ulDivisor--)
    //    {
    //        ulRem = N % ulDivisor;
    //        if (0 != ulRem)	// Not a factor
    //        {
    //            continue;
    //        }
    //        // If the given number is divisible by the current number, 
    //        // check whether it is prime or not
    //        ulQuotient = N / ulDivisor;
    //        ullMin = ulQuotient;

    //        if (IsPrime(ulDivisor))
    //        {
    //            if (ulDivisor > ulMaxPrimeFactor)
    //            {
    //                ulMaxPrimeFactor = ulDivisor;
    //            }
    //            bIsPrime = true;
    //            break;
    //        }
    //        else if (IsPrime(ulQuotient))
    //        {
    //            if (ulQuotient > ulMaxPrimeFactor)
    //            {
    //                ulMaxPrimeFactor = ulQuotient;
    //            }
    //            bIsPrime = true;
    //        }
    //        else
    //        {
    //        }
    //    }
    //    if (bIsPrime)
    //    {
    //        std::cout << ulMaxPrimeFactor << std::endl;
    //    }
    //}

    return 0;
}
