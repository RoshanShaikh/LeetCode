#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        st.push('#');
        for (int i = 0; i < s.size(); i++)
        {
            switch (s[i])
            {
            case '(':
            case '{':
            case '[':
                st.push(s[i]);
                break;
            case ')':
                if (st.top() == '(')
                    st.pop();
                else
                    return false;
                break;
            case '}':
                if (st.top() == '{')
                    st.pop();
                else
                    return false;
                break;
            case ']':
                if (st.top() == '[')
                    st.pop();
                else
                    return false;
                break;
            default:
                break;
            }
        }
        if (st.top() == '#')
            return true;
        return false;
    }
};

int main()
{

    return 0;
}