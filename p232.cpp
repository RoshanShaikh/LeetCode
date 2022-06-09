#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
private:
    stack<int> s1;

public:
    MyQueue()
    {
    }
    // O(1)
    /*
    void push(int x)
    {
        s1.push(x);
    }*/
    // O(n)
    void push(int x)
    {
        stack<int> s2;
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s2.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // O(n)
    /*
    int pop()
    {
        stack<int> s2;
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int retVal = s2.top();
        s2.pop();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return retVal;
    }
    */

    // O(1)
    int pop()
    {
        int retVal = s1.top();
        s1.pop();
        return retVal;
    }

    // O(n)
    /*int peek()
    {
        stack<int> s2;
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        int retVal = s2.top();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return retVal;
    }*/

    // O(1)
    int peek()
    {
        return s1.top();
    }

    bool empty()
    {
        return s1.empty();
    }
};

int main()
{
    MyQueue q;
    for (int i = 0; i < 5; i++)
    {
        q.push(i + 1);
    }
    cout << q.peek() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.empty() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.empty() << endl;
    return 0;
}