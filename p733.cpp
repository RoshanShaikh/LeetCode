#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void floodFill(vector<vector<int>> &image, int sr, int sc, int oldColor, int newColor)
    {
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int oldColor = image[sr][sc];
        if (oldColor == newColor)
            return image;
        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if (i >= 0 && i < image.size() && j >= 0 && j < image[0].size() && image[i][j] == oldColor)
            {
                image[i][j] = newColor;
                q.push({i, j + 1});
                q.push({i, j - 1});
                q.push({i + 1, j});
                q.push({i - 1, j});
            }
        }
        return image;
    }
};

int main()
{
    vector<vector<int>> img = {
        {0, 0, 0},
        {0, 1, 1},
    };
    img = Solution().floodFill(img, 1, 1, 1);
    for (auto &&i : img)
    {
        for (auto &&j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}