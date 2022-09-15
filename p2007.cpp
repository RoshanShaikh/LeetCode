#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findOriginalArray(vector<int> &changed)
    {
        sort(changed.begin(), changed.end());
        vector<int> orig;

        int n = changed.size();

        if (n % 2 == 1)
            return orig;

        int k = n / 2;

        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++)
        {
            freq[changed[i]]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (freq[changed[i] > 0])
            {
                if (freq[changed[i] * 2] > 0)
                {
                    orig.push_back(changed[i]);
                    freq[changed[i]]--;
                    freq[changed[i] * 2]--;
                }
                else
                {
                    return {};
                }
            }
        }

        return orig;
    }
};

int main()
{

    return 0;
}