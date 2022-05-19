#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        // Using String
        /*
        string str = to_string(x);
        int l = 0, r = str.size() - 1;
        while (l < r)
        {
            if (str[l] != str[r])
                return false;
            l++;
            r--;
        }
        return true;
        */

        /*
        if (x < 0)
            return false;
        int reverse = 0;
        int tmp = x;
        int rem = 0;
        while (tmp > 0)
        {
            rem = tmp % 10;
            reverse = reverse * 10 + rem;
            tmp = tmp / 10;
        }
        return reverse == x;
        */
        int reverse = 0;
        int rem = 0;
        if (x < 0)
            return false;
        while (x > reverse)
        {
            rem = x % 10;
            reverse = reverse * 10 + rem;
            x = x / 10;
        }
        cout << x << " " << reverse;
        return x == reverse || x == reverse / 10;
    }
};

int main()
{
    Solution().isPalindrome(10);
    return 0;
}