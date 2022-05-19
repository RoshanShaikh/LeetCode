#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size() - 1, m = nums2.size() - 1;
        deque<int> merged;
        while (n >= 0 && m >= 0)
        {
            merged.push_front(nums1[n] > nums2[m] ? nums1[n--] : nums2[m--]);
        }
        while (n >= 0)
        {
            merged.push_front(nums1[n--]);
        }
        while (m >= 0)
        {
            merged.push_front(nums2[m--]);
        }

        // for (auto &&i : merged)
        // {
        //     cout << i << " ";
        // }
        // cout << "\n";

        n = merged.size();
        double result = 0.0;
        if (n % 2 == 0)
        {
            result = (merged.at((n / 2) - 1) +
                      merged.at(n / 2)) /
                     2.0;
        }
        else
        {
            result = merged.at(((n + 1) / 2) - 1);
        }
        return result;
    }
};

int main()
{

    return 0;
}