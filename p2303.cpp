#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double calculateTax(vector<vector<int>> &brackets, int income)
    {
        int n = brackets.size();
        int i = 0;
        double tax = 0;
        if (income == 0)
            return 0;
        if (brackets[i][0] == income)
            tax += brackets[i][0] * brackets[i][1] / 100.0;
        else if (brackets[i][0] > income)
            tax += income * brackets[i][1] / 100.0;
        i++;
        while (i < n)
        {
            if (brackets[i][0] <= income)
                tax += (brackets[i][0] - brackets[i - 1][0]) * brackets[i][1] / 100.0;
            else if (brackets[i][0] > income)
            {
                tax += (income - brackets[i - 1][0]) * brackets[i][1] / 100.0;
                break;
            }
            i++;
        }
        tax = round(tax * 100) / 100.0;
        return tax;
    }
};

int main()
{

    return 0;
}