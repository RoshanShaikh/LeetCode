#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x <= 1)
            return x;
        int l = 1, h = x / 2;
        int mid = (l + h) / 2;
        while (l <= h)
        {
            unsigned long square = x / mid;
            if (square == mid)
                return mid;
            else if (square > mid)
                l = mid + 1;
            else
                h = mid - 1;
            mid = (l + h) / 2;
        }
        return mid;
    }
};

int main()
{
    Solution ob;
    while (true)
    {
        int n;
        cin >> n;
        cout << ob.mySqrt(n) << endl;
    }
    return 0;
}