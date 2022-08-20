#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findFirstOccurrence(vector<int> &nums, int start, int end, int key)
    {
        int ans = -1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (nums[mid] == key)
            {
                ans = mid;
                end = mid - 1;
            }
            else if (nums[mid] < key)
            {
                start = mid + 1;
            }
            else if (nums[mid] > key)
            {
                end = mid - 1;
            }
        }

        return ans;
    }

public:
    int reductionOperations(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        
        int prev = 0;
        int cnt = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] != nums[i + 1])
            {
                ans += cnt + prev;
                prev += cnt;
                cnt = 1;
            }
            else
            {
                cnt++;
            }
        }

        // int count = 0;
        // int i = n;
        // int largest = nums[n - 1];
        // while (i > 0)
        // {
        //     i = findFirstOccurrence(nums, 0, i - 1, largest);
        //     if (i > 0)
        //     {
        //         count += n - i;
        //         largest = nums[i - 1];
        //     }
        // };

        return ans;
    }
};

int main()
{
    vector<int> v = {1, 1, 2, 2, 3, 3, 3};

    int ans = Solution().reductionOperations(v);
    cout << ans;

    return 0;
}