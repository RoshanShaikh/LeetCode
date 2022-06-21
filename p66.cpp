#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 0;
        int i = digits.size() - 1;
        do
        {
            digits[i] = digits[i] + 1 + carry;
            carry = digits[i] / 10;
            digits[i] %= 10;
            i--;
        } while (carry != 0 && i >= 0);

        if (carry > 0)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};

int main()
{

    return 0;
}