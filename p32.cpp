#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    int longestValidParentheses(string s)
    {
        int maxLength = 0;
        /* Using Stack
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (c == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if (st.empty())
                {
                    st.push(i);
                }
                else
                {
                    maxLength = max(i - st.top(), maxLen);
                }
            }
        }
        return maxLength;
        */
        /* Withous Using Extra space
         int open = 0, close = 0;
         for (int i = 0; i < s.size(); i++)
         {
             char c = s[i];
             if (c == '(')
                 open++;
             else
                 close++;
             if (open == close)
                 maxLength = max(maxLength, close * 2);
             else if (open < close)
                 open = close = 0;
         }
         for (int i = s.size() - 1; i >= 0; i--)
         {
             char c = s[i];
             if (c == '(')
                 open++;
             else
                 close++;
             if (open == close)
             maxLength = max(maxLength, close * 2);
             else if (open > close)
                 open = close = 0;
         }
         return maxLength;
         */
        int maxans = 0;
        vector<int> dp(s.size(), 0);
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
                {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1] >= 2) ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                maxLength = max(maxLength, dp[i]);
            }
        }
        return maxLength;
    }
};

int main()
{
    Solution().longestValidParentheses("()(()))()())))))");
    return 0;
}