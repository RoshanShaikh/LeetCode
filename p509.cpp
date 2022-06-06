#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long fib(long long n)
    {
        if (n <= 1)
            return n;
        long long a = 0, b = 1;
        long long c;
        for (long long i = 0; i < n - 1; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};

int main()
{
    Solution ob;
    while (true)
    {
        long long n;
        cin >> n;
        cout << ob.fib(n) << "\n---------------\n";
    }

    return 0;
}