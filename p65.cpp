#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    inline bool isDigit(char &d) { return d <= '9' && d >= '0'; }

    inline bool isSign(char &s) { return s == '+' || s == '-'; }

    bool isInteger(string &s)
    {
        int i = 0;
        int n = s.size();
        if (n == 0)
            return false;

        if (isSign(s[i]))
            i++;

        if (i == n)
            return false;

        while (i < n)
        {
            if (!isDigit(s[i]))
                return false;
            i++;
        }

        return true;
    }

    bool isDecimal(string &s)
    {
        int i = 0;
        int n = s.size();

        if (isSign(s[i]))
            i++;

        bool first = false;
        while (isDigit(s[i]))
        {
            first = true;
            i++;
        }

        if (s[i++] != '.')
            return false;

        bool second = false;
        while (isDigit(s[i]))
        {
            second = true;
            i++;
        }

        return (first || second) && i == n;
    }

public:
    bool isNumber(string s)
    {
        int posOfE = s.find('e');
        if (posOfE == string::npos)
            posOfE = s.find('E');

        if (posOfE == string::npos)
            return isDecimal(s) || isInteger(s);

        string firstPart = s.substr(0, posOfE);
        string secondPart = s.substr(posOfE + 1);

        return isInteger(secondPart) && (isDecimal(firstPart) || isInteger(firstPart));
    }
};

int main()
{
    Solution ob;
    while (1)
    {
        string s;
        cin >> s;
        bool ans = ob.isNumber(s);
        cout << (ans ? "true" : "false") << endl;
    }
    return 0;
}