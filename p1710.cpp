#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(),
             [](vector<int> first, vector<int> second)
             { return first[1] > second[1]; });

        int ans = 0;

        for (auto &&pr : boxTypes)
        {
            if (truckSize >= pr[0])
            {
                truckSize -= pr[0];
                ans += pr[0] * pr[1];
            }
            else
            {
                ans += truckSize * pr[1];
                break;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}