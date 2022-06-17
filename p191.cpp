#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int count;
        while (n > 0)
        {
            if ((n & 1))
                count++;
            n = n >> 1;
        }
        return count;
    }
};

int main()
{
    Solution ob;
    while (true)
    {
        int n;
        cin >> n;
        cout << ob.hammingWeight(n) << endl;
    }
    return 0;
}