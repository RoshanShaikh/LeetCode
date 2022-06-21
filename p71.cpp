#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> st;
        int pos1 = path.find_first_of('/');
        while (pos1 < path.size())
        {
            int pos2 = path.find('/', pos1 + 1);
            if (pos2 == string::npos)
            {
                pos2 = path.size();
            }
            string dir = path.substr(pos1 + 1, pos2 - pos1 - 1);
            if (dir == "..")
            {
                if (!st.empty())
                    st.pop_back();
            }
            else if (!dir.empty() && dir != ".")
            {
                st.push_back(dir);
            }
            pos1 = pos2;
        }
        string ans = "";
        for (auto &&str : st)
        {
            ans += "/" + str;
        }
        if (ans.empty())
            ans = "/";
        return ans;
    }
};

int main()
{

    return 0;
}