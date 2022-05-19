#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        nums1.clear();
        vector<int>::iterator itr = nums2.begin();
        while (itr != nums2.end())
        {
            if (!s1.count(*itr))
                nums2.erase(itr);
            else
                s1.erase(*itr);
            cout << *itr;
        }

        return nums2;
    }
};

int main()
{
    vector<int> a = {1, 2, 2, 1};
    vector<int> b = {2, 2};
    Solution().intersection(a, b);
    return 0;
}