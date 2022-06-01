#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
            if (map[nums[i]] == 2)
                return true;
        }
        return false;
    }

    /* Using Sorting
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[i-1])
                return true;
        }
        return false;
    }
    */
};

int main()
{

    return 0;
}