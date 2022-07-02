#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        horizontalCuts.push_back(h);

        sort(verticalCuts.begin(), verticalCuts.end());
        verticalCuts.push_back(w);

        int m = horizontalCuts.size();
        int n = verticalCuts.size();

        int maxHorizontal = INT_MIN;
        int maxVertical = INT_MIN;

        for (int i = max(m, n); i > 0; i--)
        {
            if (i < m)
            {
                horizontalCuts[i] -= horizontalCuts[i - 1];
                maxHorizontal = max(maxHorizontal, horizontalCuts[i]);
            }

            if (i < n)
            {
                verticalCuts[i] -= verticalCuts[i - 1];
                maxVertical = max(maxVertical, verticalCuts[i]);
            }
        }
        maxHorizontal = max(maxHorizontal, horizontalCuts[0]);
        maxVertical = max(maxVertical, verticalCuts[0]);

        long long ans = (long long)maxHorizontal * maxVertical;

        return ans % 1000000007;
    }
};

int main()
{
    vector<int> h = {3};
    vector<int> w = {3};

    cout << Solution().maxArea(5, 4, h, w);

    return 0;
}