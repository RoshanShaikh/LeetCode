#include <bits/stdc++.h>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
    bool isBadVersion(int n);

public:
    int firstBadVersion(int n)
    {
        long start = 1, end = n;
        while (start <= end)
        {
            long mid = (start + end) >> 1;
            if (isBadVersion(mid))
                end = mid - 1;
            else
                start = mid + 1;
            if (isBadVersion(mid) && !isBadVersion(mid - 1))
            {
                return mid;
            }
        }
        return 1;
    }
};

int main()
{

    return 0;
}