#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int red = 0, white = 0, blue = 0;

        for (auto &&i : nums)
        {
            switch (i)
            {
            case 0:
                red++;
                break;

            case 1:
                white++;
                break;

            default:
                blue++;
                break;
            }
        }

        int i = 0;
        while (red--)
            nums[i++] = 0;

        while (white--)
            nums[i++] = 1;

        while (blue--)
            nums[i++] = 2;
    }
};

int main()
{

    return 0;
}