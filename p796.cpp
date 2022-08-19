#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        s.append(s);
        if (s.find(goal) != string::npos)
            return true;
        return false;
    }
};

int main()
{

    return 0;
}