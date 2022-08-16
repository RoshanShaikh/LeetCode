#include <bits/stdc++.h>
using namespace std;

class Solution
{
    static const int MOD = 1e9 + 7;

public:
    int concatenatedBinary(int n)
    {
        unsigned long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans = (ans << (int(log2(i)) + 1)) % MOD;
            ans += i;
        }

        return (ans % MOD);
    }
};
// 1 462911642 310828084 499361981 356435599 757631812

int main()
{
    Solution ob;
    int n = 0;
    while (n != -1)
    {
        cin >> n;
        cout << ob.concatenatedBinary(n) << endl;
    }

    return 0;
}