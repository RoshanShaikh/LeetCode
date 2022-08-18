#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<pair<int, int>> sort(unordered_map<int, int> &M)
    {

        vector<pair<int, int>> A;

        for (auto &it : M)
        {
            A.push_back(it);
        }

        sort(A.begin(), A.end(), [](pair<int, int> &a, pair<int, int> &b)
             { return a.second > b.second; });

        return A;
    }

public:
    int minSetSize(vector<int> &arr)
    {
        int n = arr.size();
        int cnt = 0;
        unordered_map<int, int> map;

        for (int i = 0; i < n; i++)
        {
            map[arr[i]]++;
        }

        vector<pair<int, int>> sorted_map = sort(map);
        int noOfEle = 0;
        for (auto &&i : sorted_map)
        {
            noOfEle += i.second;
            cnt++;
            if (noOfEle >= n / 2)
                break;
        }

        return cnt;
    }
};

int main()
{
    unordered_map<int, int> a = {
        {1, 3},
        {2, 9},
        {6, 3},
        {5, 10}};

    vector<pair<int, int>> sorted = sort(a);

    for (auto &&i : sorted)
    {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}