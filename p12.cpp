#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        map<int, string> map;
        map[1] = "I";
        map[4] = "IV";
        map[5] = "V";
        map[9] = "IX";
        map[10] = "X";
        map[40] = "XL";
        map[50] = "L";
        map[90] = "XC";
        map[100] = "C";
        map[400] = "CD";
        map[500] = "D";
        map[900] = "CM";
        map[1000] = "M";

        string ans = "";
        for (auto &&i = map.rbegin(); i != map.rend(); i++)
        {
            while ((*i).first < num)
            {
                ans += (*i).second;
                num -= (*i).first;
            }
        }
        return ans;
    }
};

int main()
{
    unordered_map<int, string> map;
    cout << map[10];
    return 0;
}