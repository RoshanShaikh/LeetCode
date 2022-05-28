#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        vector<int> freq(n, 0);
        for (int i = 0; i < roads.size(); i++)
        {
            freq[roads[i][0]]++;
            freq[roads[i][1]]++;
        }
        sort(freq.begin(), freq.end());
        long long sum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            sum += freq[i] * (long long)(i + 1);
        }
        return sum;
    }
};

int main()
{
    return 0;
}