#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        /* Using Extra space
        vector<int> pos, neg;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                neg.push_back(nums[i]);
            else
                pos.push_back(nums[i]);
        }
        for (int i = 0; i < pos.size(); i++)
        {
            nums[i * 2] = pos[i];
        }
        for (int i = 0; i < neg.size(); i++)
        {
            nums[i * 2 + 1] = neg[i];
        }
        */

        int n = nums.size();
        vector<int>::iterator it = nums.begin();
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0 && nums[i] < 0)
            {
                int j = i + 1;
                while (j < n && nums[j] < 0)
                    j++;
                nums.insert(nums.begin() + i, nums[j]);
                nums.erase(nums.begin() + j + 1);
                i++;
            }
            else if (i % 2 != 0 && nums[i] > 0)
            {
                int j = i + 1;
                while (j < n && nums[j] > 0)
                    j++;
                nums.insert(nums.begin() + i, nums[j]);
                nums.erase(nums.begin() + j + 1);
                i++;
            }
            for (int i = 0; i < n; i++)
            {
                cout << nums[i] << " ";
            }
            cout << endl;
        }

        return nums;
    }
};
int main()
{
    vector<int> v = {-1, -2, -3, -4, 5, 9, 3, 6};
    v = Solution().rearrangeArray(v);
    for (auto &&i : v)
    {
        cout << i << " ";
    }

    return 0;
}