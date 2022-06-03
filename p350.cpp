#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
            swap(nums1, nums2);
        int n = nums1.size();
        int m = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0;
        int j = 0;
        vector<int> ans;
        while (i < n)
        {
            if (nums1[i] == nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] > nums2[j])
                j++;
            else
                i++;
        }
        ans.shrink_to_fit();
        return ans;
    }
};

int main()
{
    vector<int> v(10);
    v.shrink_to_fit();
    cout << v.size() << endl;
    return 0;
}