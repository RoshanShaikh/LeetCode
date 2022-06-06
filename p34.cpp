#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	vector<int> searchRange(vector<int> &nums, int target)
	{
		int start = 0, end = nums.size() - 1;
		vector<int> ans = {-1, -1};
		while (start <= end)
		{
			int mid = (start + end + 1) / 2;
			if (target == nums[mid])
			{
				ans[0] = ans[1] = mid;
				int i = mid++;
				int j = mid--;
				while (i < nums.size() && j >= 0)
				{
					if (nums[i] == target)
						ans[1] = i;
					else
						break;
					if (nums[j] == target)
						ans[0] = j;
					else
						break;
					i++;
					j--;
				}
				while (i < nums.size() && nums[i] == target)
				{
					ans[1] = i;
				}
				while (j >= 0 && nums[j] == target)
				{
					ans[0] = j;
				}
				break;
			}
			else if (target < nums[mid])
				end = mid - 1;
			else
				start = mid + 1;
		}
		return ans;
	}
};

int main()
{
	vector<int> v = {1};
	Solution().searchRange(v, 1);
	return 0;
}