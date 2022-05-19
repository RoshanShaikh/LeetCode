#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &a1, int m, vector<int> &a2, int n)
    {
        /* Naive Approach
        for (int i = m, j = 0; j < n; i++, j++)
        {
            a1[i] = a2[j];
        }
        sort(a1.begin(), a1.end());
          */

        int p1 = m - 1, p2 = n - 1, i = m + n - 1;
        while (p2 >= 0)
        {
            if (p1 >= 0 && a1[p1] > a2[p2])
                a1[i--] = a1[p1--];
            else
                a1[i--] = a2[p2--];
        }
    }
};

int main()
{
    vector<int> a1 = {1, 2, 3, 0, 0, 0};
    vector<int> a2 = {2, 5, 6};
    Solution().merge(a1, 3, a2, 3);
    // for (auto &&i : a1)
    // {
    //     cout << i << " ";
    // }

    return 0;
}