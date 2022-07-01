#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
            return n;

        /*

        int count = 1;
        int j = 0;

        for (int i = 1; i < n; i++)
        {
            if (count < 2 && nums[i] == nums[j])
            {
                nums[++j] = nums[i];
                count++;
            }
            else if (nums[i] != nums[j])
            {
                count = 1;
                nums[++j] = nums[i];
            }
        }

        return j + 1;
        */

        int k = 2;

        for (int i = 2; i < n; i++)
        {
            if (nums[i] != nums[k - 2])
            {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};

int main()
{
    vector<int> v = {1, 1, 1, 2, 2, 3};

    int k = Solution().removeDuplicates(v);

    for (int i = 0; i < k; i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}