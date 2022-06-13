#include <bits/stdc++.h>
using namespace std;

class Solution
{
    double solve(double x, int n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        double ans = pow(x, n / 2);
        if (n % 2 == 0)
            return ans * ans;
        return ans * ans * x;
    }

public:
    double myPow(double x, int n)
    {
        if (n < 0)
            return 1 / solve(x, n * -1);
        return pow(x, n);
    }
};

int main()
{

    return 0;
}