#include <bits/stdc++.h>
using namespace std;

class MinStack
{
    stack<long> st;
    long mini = INT_MAX;

public:
    MinStack()
    {
    }

    void push(long val)
    {
        if (st.empty())
        {
            st.push(val);
            mini = val;
        }
        else if (val >= mini)
        {
            st.push(val);
        }
        else
        {
            st.push(2 * val * 1L - mini);
            mini = val;
        }
    }

    void pop()
    {
        if (st.top() < mini)
        {
            mini = 2 * mini * 1L - st.top();
        }
        st.pop();
    }

    int top()
    {
        if (st.top() < mini)
        {
            return mini;
        }
        else
        {
            return st.top();
        }
    }

    int getMin()
    {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * long param_3 = obj->top();
 * long param_4 = obj->getMin();
 */

int main()
{
    MinStack ob;
    ob.push(2147483646);
    ob.push(2147483646);
    ob.push(-2147483647);
    // ["MinStack","push","push","push","top","pop","getMin","pop","getMin","pop","push","top","getMin","push","top","getMin","pop","getMin"]
    // [[],[2147483646],[2147483646],[2147483647],[],[],[],[],[],[],[2147483647],[],[],[-2147483648],[],[],[],[]]

    cout << ob.top() << endl;
    ob.pop();
    cout << ob.getMin() << endl;
    ob.pop();
    cout << ob.getMin() << endl;
    ob.pop();
    ob.push(2147483647);
    cout << ob.top() << endl;
    cout << ob.getMin() << endl;
    ob.push(-2147483648);
    cout << ob.top() << endl;
    cout << ob.getMin() << endl;
    ob.pop();
    cout << ob.getMin() << endl;

    return 0;
}