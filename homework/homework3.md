### 1. 调研学习相似度的定义方法。
除了用欧式距离来计算个体之间的相似程度之外，也可以用余弦相似度的方法来计算个体之间的相似程度。
对于两个二维向量，其余弦可按照如下公式计算：

![formula1](formula1.jpg)

对于两个n维向量，其余弦可按照如下的公式计算：

![formula2](formula2.png)

**余弦值越接近1，就表明夹角越接近0度，也就是两个向量越相似，夹角等于0，即两个向量相等，这就叫"余弦相似性"。**


### 2. 给出方案实现O（1）时间内获得栈中最小值的函数？假如是队列呢？
如果要实现在O（1）时间复杂度内获得栈中的最小值，便不能考虑对其进行排序或者遍历来找出其最小值，则只能在对栈进行push或pop时做一些手脚。我们可以用两个栈来实现该功能。
**栈`a`用来存储数据，而栈`b`的顶部元素用来记录此时栈中的最小值**。假如我们此时需要将元素`i`压入栈，若此时栈`b`为空或者`i`小于栈`b`的栈顶元素，则将元素`i`压入栈`b`。当需要将栈`a`执行出栈时，如果此时`a`的栈顶元素也为`b`的栈顶元素，则将`a`，`b`同时`pop`，否则仅将`a`执行`pop`。
如果是队列的话，我们已经实现在O（1）时间获得栈中最小值的函数，我们又知道可以用两个栈实现队列，那么自然而然可以想到用两个可以获得最小值的栈类型来组成我们所需要的，能够获得最小值的队列类型。

代码示例如下：
```cpp
/**
* find_min_in_container.cpp
* @author Jiang Bingchen
* @description Algorithm homework
* @created 2021-03-16  21:47:02.
* @last-modified 2021-03-20  22:23:53.
*/
#include <bits/stdc++.h>
using namespace std;
template <class T>
class mystack
{
public:
    stack<T> data;
    stack<T> assit;
    mystack() {}
    bool empty()
    {
        return data.empty();
    }
    void push(T i)
    {   
        data.push(i);
        //push i in stack assit when it is empty or i is not bigger than assit.top()
        if (assit.empty())
        {
            assit.push(i);
            return;
        }
        if (i <= assit.top())
            assit.push(i);
    }
    void pop()
    {
        if (data.empty())
        {
            cout << "error: the stack is empty!" << endl;
            return;
        }
        //pop the top element if it's equal to the top element of stack data
        if (data.top() == assit.top())
            assit.pop();
        data.pop();
    }
    T top()
    {
        if (data.empty())
        {
            cout << "error: the stack is empty" << endl;
            return -1;
        }
        return data.top();
    }
    T min()
    {
        if (data.empty())
        {
            cout << "error: the stack is empty" << endl;
            return -1;
        }
        return assit.top();
    }
};
template <class T>
class myqueue
{
public:
    mystack<T> in;
    mystack<T> out;
    myqueue() {}
    void push(T i)
    {
        in.push(i);
    }
    void pop()
    {
        if (in.empty() && out.empty())
        {
            cout << "error: the queue is empty !" << endl;
            return;
        }
        T temp;
        if (out.empty())
            while (!in.empty())
            {
                temp = in.top();
                in.pop();
                out.push(temp);
            }
        out.pop();
    }
    T minimum()
    {
        if (out.empty())
            return in.min();
        else if (in.empty())
            return out.min();
        else if (out.empty() && out.empty())
        {
            cout << "error: the queue is empty!" << endl;
            return -1;
        }
        else
            return min(in.min(), out.min());
    }
};
int main()
{
    myqueue<int> solqueue;
    solqueue.push(5);
    solqueue.push(3);
    solqueue.push(2);
    solqueue.push(8);
    solqueue.push(7);
    solqueue.push(4);
    cout << solqueue.minimum() << endl;
    solqueue.pop();
    solqueue.pop();
    solqueue.pop();
    cout << solqueue.minimum() << endl;
}
```