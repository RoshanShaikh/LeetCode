#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &v)
    {
        int n = v.size();
        int i = 0, j = n - 1;
        int maxArea = 0;
        while (i < j)
        {
            maxArea = max(maxArea, (j - i) * min(v[i], v[j]));
            if (v[i] <= v[j])
                i++;
            else
                j--;
        }

        return maxArea;
    }
};

int main()
{
    vector<int> v = {1, 2, 5, 6, 7, 7};
    // vector<int>::iterator maxit1 = max_element(v.begin(), v.end());
    int pos1 = max_element(v.begin(), v.end()) - v.begin();
    int max1 = v[pos1];
    for (auto &&i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    v.erase(v.begin() + pos1);
    for (auto &&i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    int pos2 = max_element(v.begin(), v.end()) - v.begin();
    int max2 = v[pos2];
    cout << max1 << " " << max2 << endl;

    v.insert(v.begin() + pos1, max1);
    for (auto &&i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << pos1 << " " << pos2;
    return 0;
}