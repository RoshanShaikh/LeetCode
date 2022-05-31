#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> nextSmaller(vector<int> heights)
    {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        for (int i = n - 1; i >= 0; i--)
        {
            while (st.top() != -1 && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmaller(vector<int> heights)
    {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < n; i++)
        {
            while (st.top() != -1 && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> next = nextSmaller(heights);
        vector<int> prev = prevSmaller(heights);
        int maxArea = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int l = heights[i];
            if (next[i] == -1)
                next[i] = n;
            int b = next[i] - prev[i] - 1;
            maxArea = max(maxArea, l * b);
        }
        return maxArea;
    }
};

int main()
{

    return 0;
}