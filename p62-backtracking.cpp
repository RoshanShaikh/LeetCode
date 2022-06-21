#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void solve(int &i, int &j, int &m, int &n, int &count)
    {
        if (i == m - 1 && j == n - 1)
        {
            count++;
            return;
        }

        if (i + 1 < m)
        {
            i++;
            solve(i, j, m, n, count);
            i--;
        }
        if (j + 1 < n)
        {
            j++;
            solve(i, j, m, n, count);
            j--;
        }
    }

public:
    int uniquePaths(int m, int n)
    {
        int count = 0;
        int i = 0, j = 0;
        solve(i, j, m, n, count);
        return count;
    }
};

int main()
{

    return 0;
}