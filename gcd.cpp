#include <iostream>
#include <time.h>
using namespace std;

long int middle_school(long int m, long int n)
{
    long int i, gcd;
    clock_t start, end;
    start = clock();
    for (i = 1; i <= m && i <= n; ++i)
    {
        if (m % i == 0 && n % i == 0)
            gcd = i;
    }
    end = clock();
    cout << endl << "Time taken:" << (end - start) / CLOCKS_PER_SEC << " sec , GCD ";
    return gcd;
}

long int euclid(long int m, long int n)
{
    clock_t start, end;
    start = clock();
    long int r;
    while (n != 0)
    {
        r = m % n;
        m = n;
        n = r;
    }
    end = clock();
    cout << endl << "Time taken:" << (end - start) / CLOCKS_PER_SEC << " sec , GCD ";
    return m;
}

long int sub(long int m, long int n)
{
    clock_t start, end;
    start = clock();
    m = (m < 0) ? -m : m;
    n = (n < 0) ? -n : n;
    while (m != n)
    {
        if (m > n)
        {
            m = m - n;
        }
        else
        {
            n = n - m;
        }
    }
    end = clock();
    cout << "Time taken :" << (end - start) / CLOCKS_PER_SEC << " sec , GCD ";
    return m;
}

main()
{
    long int x, y;
    cout << "\t\t ANALYSIS OF THE TWO ALGORITHMS" << endl << endl;
    cout << "GCD : " << endl;
    cout << "enter two numbers:";
    cin >> x >> y;
    cout << endl << endl << "GCD-Middle School : " << middle_school(x, y);
    cout << endl << endl << "GCD-Euclid : " << euclid(x, y);
    cout << endl << endl << "------------------------------------------------";
    cout << endl << endl << "GCD- subtraction : " << sub(x, y);
}   
