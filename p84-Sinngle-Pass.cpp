#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        int n = heights.size();
        int maxArea = 0;
        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
            {
                int height = heights[st.top()];
                st.pop();
                int width;
                if (st.empty())
                    width = i;
                else
                {
                    width = i - st.top() - 1;
                    cout << st.top() << " ";
                }
                maxArea = max(maxArea, height * width);
                cout << height * width << "\n";
            }
            st.push(i);
        }
        return maxArea;
    }
};

int main()
{
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    Solution().largestRectangleArea(heights);

    return 0;
}