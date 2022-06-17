#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans = 1;
        int count = 0;
        for (int i = 0; i < 32; i++)
        {
            ans = ans << 1;
            ans = ans | (n & 1);
            count++;
            n /= 2;
        }
        return ans;
    }
};

int main()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            cout << rand() % 2;
        }
        cout << "\n";
    }
    return 0;
}