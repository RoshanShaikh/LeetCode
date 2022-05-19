#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        /*
        for (int i = 0; i < nums.size(); i++)
        {
            int num = target - nums[i];
            vector<int>::iterator it = find(nums.begin(), nums.end(), num);
            int pos = distance(nums.begin(), it);
            if (pos < nums.size() && pos != i)
            {
                return {nums[i], nums[pos]};
            }
        }
        */

        // Usign Map

        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            if (map[target - nums[i]] != 0)
            {
                return {map[target - nums[i]] - 1, i};
            }
            map[nums[i]] = i + 1;
        }
        return {0, 0};
    }
};

int main()
{

    return 0;
}