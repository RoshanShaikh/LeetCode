#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int edgeScore(vector<int> &edges)
    {
        int ans = 0;
        int n = edges.size();
        vector<int> scores(n, 0);

        for (int i = 0; i < n; i++)
        {
            scores[edges[i]] += i;
            if (scores[edges[i]] > scores[ans])
            {
                ans = edges[i];
            }
            if (scores[edges[i]] == scores[ans])
            {
                ans = min(ans, edges[i]);
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}