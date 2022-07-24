#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSameAfterReversals(int num)
    {
        if (num == 0)
            return true;

        if (num % 10 == 0)
            return false;

        return true;
    }
};
int main()
{
    for (int i = 0; i <= 1000000; i++)
        cout << i + 1 << endl;
    return 0;
}