#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;
        int count = 0;
        for (int i = 2; i < n; i++)
        {
            if (prime[i])
            {
                count++;

                for (int j = i + i; j < n + 1; j += i)
                {
                    prime[j] = false;
                }
            }
        }
    }
};

int main()
{
    Solution().countPrimes(10);
    return 0;
}