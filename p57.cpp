#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        int n = intervals.size();

        if (n == 0)
        {
            ans.push_back(newInterval);
            return ans;
        }

        bool overlapped = false;

        int newStart = newInterval[0];
        int newEnd = newInterval[1];
        int i = 0;

        if (newStart > intervals[0][0])
        {
            ans.push_back(intervals[0]);
            i++;
            overlapped = true;
        }
        else
            ans.push_back(newInterval);

        while (i < n)
        {
            if (!overlapped)
            {
                int lastStart = ans.back()[0];
                int lastEnd = ans.back()[1];

                if (newStart <= lastEnd)
                {
                    int start = min(newStart, lastStart);
                    int end = max(newEnd, lastEnd);

                    ans.pop_back();
                    ans.push_back({start, end});
                    overlapped = true;
                }
                else
                {
                    if (newEnd < intervals[i][0])
                    {
                        ans.push_back(newInterval);
                        overlapped = true;
                    }
                    else
                        ans.push_back(intervals[i++]);
                }
            }
            else
            {

                int lastStart = ans.back()[0];
                int lastEnd = ans.back()[1];

                int start = intervals[i][0];
                int end = intervals[i][1];

                if (start <= lastEnd)
                {
                    start = min(start, lastStart);
                    end = max(end, lastEnd);

                    ans.pop_back();
                    ans.push_back({start, end});
                    i++;
                }
                else
                {
                    break;
                }
            }
        }

        if(!overlapped){
            int lastStart = ans.back()[0];
            int lastEnd = ans.back()[1];

            if (newStart <= lastEnd)
            {
                int start = min(newStart, lastStart);
                int end = max(newEnd, lastEnd);

                ans.pop_back();
                ans.push_back({start, end});
                overlapped = true;
            }else
            {
                ans.push_back(newInterval);
            }
        }

        while (i < n)
        {
            ans.push_back(intervals[i++]);
        }

        return ans;
    }
};

int main()
{

    return 0;
}