// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution
{
private:
    bool isAllocationPossible(int a[], int n, int m, int mid)
    {
        int pageSum = 0;
        int stCount = 1;
        for (int i = 0; i < n; i++)
        {
            if (pageSum + a[i] <= mid)
            {
                pageSum += a[i];
            }
            else
            {
                stCount++;
                pageSum = a[i];
            }
            if (stCount > m || pageSum > mid)
            {
                return false;
            }
        }
        return true;
    }

public:
    // Function to find minimum number of pages.
    int findPages(int a[], int n, int m)
    {
        // code here
        int s = 0;
        int e = 0;
        for (int i = 0; i < n; i++)
        {
            e += a[i];
        }
        int ans = -1;
        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (isAllocationPossible(a, n, m, mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends