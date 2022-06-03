#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    string multiply(string &n, int &m)
    {
        string result = "";
        int carry = 0;
        for (int i = n.size() - 1; i >= 0; i--)
        {
            int digit = n[i] - '0';
            int mul = digit * m + carry;
            result.insert(result.begin(), char((mul % 10) + '0'));
            carry = mul / 10;
        }
        if (carry > 0)
            result.insert(result.begin(), carry + '0');
        return result;
    }
    string add(string &a, string &b)
    {
        int n = a.size();
        int m = b.size();
        int i = n - 1, j = m - 1;
        string result = "";
        int carry = 0;
        while (i >= 0 && j >= 0)
        {
            int sum = a[i] + b[j] - 2 * ('0') + carry;
            result.insert(result.begin(), char((sum % 10) + '0'));
            carry = sum / 10;
            i--;
            j--;
        }
        while (i >= 0)
        {
            int sum = a[i] - ('0') + carry;
            result.insert(result.begin(), char((sum % 10) + '0'));
            carry = sum / 10;
            i--;
        }
        while (j >= 0)
        {
            int sum = b[j] - ('0') + carry;
            result.insert(result.begin(), char((sum % 10) + '0'));
            carry = sum / 10;
            j--;
        }
        if (carry > 0)
            result.insert(result.begin(), carry + '0');
        return result;
    }
    string multiply(string &num1, string &num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";
        int n = num1.size();
        int m = num2.size();
        string result = "";
        for (int i = 0; i < m; i++)
        {
            int digit = num2[i] - '0';
            string mul = multiply(num1, digit);
            result.push_back('0');
            result = add(result, mul);
        }
        return result;
    }
};

int main()
{
    string s;
    string n;
    Solution ob;
    while (true)
    {
        cin >> s;
        cin >> n;
        cout << ob.multiply(s, n) << endl;
    }
    return 0;
}