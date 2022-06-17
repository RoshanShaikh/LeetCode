#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;
        if ((n & (n - 1)) == 0)
            return true;
        return false;
    }
};

int main()
{
    Solution ob;
    while (true)
    {
        int n;
        cin >> n;
        cout << (ob.isPowerOfTwo(n) ? "true" : "false") << endl;
    }
    return 0;
}