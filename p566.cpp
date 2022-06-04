#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        int n = mat.size();
        int m = mat[0].size();
        if (n == r || m == c || m * n != r * c)
            return mat;
        vector<vector<int>> ans(r, vector<int>(c));
        for (int i = 0; i < m * n; i++)
        {                                          
            ans[i / c][i % c] = mat[i / n][i % n]; 
        }
        return ans;
    }
};

int main()
{

    return 0;
}