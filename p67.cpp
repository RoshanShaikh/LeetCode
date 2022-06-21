#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string ans = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 && j >= 0)
        {
            int m = a[i--] - '0';
            int n = b[j--] - '0';

            int k = m + n + carry;
            switch (k)
            {
            case 0:
                ans.push_back('0');
                carry = 0;
                break;
            case 1:
                ans.push_back('1');
                carry = 0;
                break;
            case 2:
                ans.push_back('0');
                carry = 1;
                break;
            case 3:
                ans.push_back('1');
                carry = 1;
                break;

            default:
                break;
            }
        }
        while (i >= 0)
        {
            int m = a[i--] - '0';

            int k = m + carry;
            switch (k)
            {
            case 0:
                ans.push_back('0');
                carry = 0;
                break;
            case 1:
                ans.push_back('1');
                carry = 0;
                break;
            case 2:
                ans.push_back('0');
                carry = 1;
                break;

            default:
                break;
            }
        }

        while (j >= 0)
        {
            int m = b[j--] - '0';

            int k = m + carry;
            switch (k)
            {
            case 0:
                ans.push_back('0');
                carry = 0;
                break;
            case 1:
                ans.push_back('1');
                carry = 0;
                break;
            case 2:
                ans.push_back('0');
                carry = 1;
                break;

            default:
                break;
            }
        }

        if (carry)
            ans.push_back('1');

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    cout << Solution().addBinary("1010","1011");
    return 0;
}