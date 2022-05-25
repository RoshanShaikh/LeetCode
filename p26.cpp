#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &v)
    {
        int j = 0;
        v[j++] = v[0];
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] != v[i - 1])
                v[j++] = v[i];
        }
        return j;
    }
};

int main()
{

    return 0;
}