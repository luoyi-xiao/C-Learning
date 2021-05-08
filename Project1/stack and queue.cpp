#include<iostream>
#include<deque>
#include<stdio.h>

using namespace std;

namespace bit

{

    template<class T, class Con = deque<T>>

    class stack
    {
    public:
        stack() 
        {   };

        void push(const T& x)
        {
            _c.push_back(x);
        }

        void pop()
        {
            _c.pop_back();
        }

        T& top()
        {
            return _c.back();
        }

        const T& top()const
        {
            return _c.back();
        }

        size_t size()const
        {
            return _c.size();
        }

        bool empty()const
        {
            return _c.empty();
        }

    private:
        Con _c;
    };



    template<class T, class Con = deque<T>>

    class queue

    {

    public:

        queue(){}

        void push(const T& x)
        {
            _c.push_back(x);
        }

        void pop()
        {
            _c.pop_front();
        }

        T& back()
        {
            return _c.back();
        }

        const T& back()const
        {
            return _c.back();
        }

        T& front()
        {
            return _c.front();
        }

        const T& front()const
        {
            return _c.front();
        }

        size_t size()const
        {
            return _c.size();
        }

        bool empty()const
        {
            return _c.empty();
        }

    private:
        Con _c;
    };
};



int main()
{
    bit::stack<int,deque<int>> s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.pop();
    int tmp = s1.top();
    int size = s1.size();

    bit::queue<int, deque<int>> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.pop();
    int tmp1 = q1.front();
    int size1 = q1.size();

}