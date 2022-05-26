#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int start = 0, end = nums.size() - 1;
        while (start < end)
        {
            int mid = (start + end + 1) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target)
                end = mid - 1;
            else if (mid == end)
                return mid + 1;
            else
                start = mid + 1;
        }
        if (start == end)
            if (target > nums[start])
                return start + 1;
            else
                return start;
        return -1;
        // return searchInsert(nums, target, start, end);
    }
    int searchInsert(vector<int> &nums, int target, int start, int end)
    {
        if (start == end)
            if (target > nums[start])
                return start + 1;
            else
                return start;
        int mid = (end + start + 1) / 2;
        if (target == nums[mid])
            return mid;
        if (target < nums[mid])
            return searchInsert(nums, target, start, mid - 1);
        else if (mid == end)
            return end + 1;
        else
            return searchInsert(nums, target, mid + 1, end);
    }
};

int main()
{

    return 0;
}