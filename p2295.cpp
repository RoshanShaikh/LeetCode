#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> arrayChange(vector<int> &nums, vector<vector<int>> &operations)
    {
        int m = operations.size();
        int n = nums.size();
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; i++)
        {
            map[nums[i]].push_back(i);
        }
        for (int i = 0; i < m; i++)
        {
            for (auto &&j : map[operations[i][0]])
            {
                nums[j] = operations[i][1];
                map[operations[i][1]] = map[operations[i][0]];
                map.erase(operations[i][0]);
            }
        }
        return nums;
    }
};

int main()
{

    return 0;
}