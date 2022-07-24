#include <bits/stdc++.h>
using namespace std;

class NumberContainers
{
    map<int, int> map;

public:
    NumberContainers()
    {
    }

    void change(int index, int number)
    {
        map[index] = number;
    }

    int find(int number)
    {
        for (auto &&it : map)
        {
            if (it.second == number)
            {
                return it.first;
            }
        }

        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

int main()
{

    return 0;
}