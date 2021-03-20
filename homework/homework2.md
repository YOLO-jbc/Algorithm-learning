## 题目1
从前，有从1到n依次编号的n个同学和n 盏灯。
1号同学将所有的灯都关掉；
2号同学将编号为2的倍数的灯都打开；
3号同学则将编号为3的倍数的灯作相反处理（该号灯如打开的，则关掉；如关闭的，则打开）；
以后的同学都将自己编号的倍数的灯，作相反处理。
问：经n个同学操作后，哪些灯是打开的？


## 代码
```cpp
/**
* light_game.cpp
* @author Jiang Bingchen
* @description Algorithm homework
* @created 2021-03-09  16:46:10.
* @last-modified 2021-03-13  16:23:40.
*/
#include <bits/stdc++.h>
using namespace std;
class light_game
{
private:
    int size;
    vector<bool> light_list;
    void deal(int a)
    {

        int temp = a + 1;
        for (int i = a; i < size; i += temp)
        {
            light_list[i] = !light_list[i];
        }
    }

public:
    void init()
    {
        cout << "how many lights?" << endl;
        cin >> size;
        light_list.resize(size, false);
    }
    void ope()
    {
        for (int i = 1; i <= size / 2; i++)
        {
            deal(i);
        }
        for (int i = size / 2 + 1; i < size; i++)
        {
            light_list[i] = !light_list[i];
        }
        for (int i = 0; i < size; i++)
        {
            if (light_list[i])
                cout << "light " << i + 1 << " is on" << endl;
        }
    }
};
int main()
{
    light_game sol;
    sol.init();
    sol.ope();
}
```


## 题目2
给出方案求解最小公倍数问题。

```cpp
#include <bits/stdc++.h>
using namespace std;
class Least_common_multiple
{
private:
    int ans(int a, int b)
    {
        int temp1 = max(a, b), temp2 = min(a, b);
        for (int i = temp1;; i += temp1)
        {
            if (i % temp2 == 0)
                return i;
        }
    }

public:
    void ope()
    {
        int a, b;
        cout << "input two integers" << endl;
        cin >> a >> b;
        cout << "the least common multiple of them is " << ans(a, b) << endl;
    }
};
int main()
{
    Least_common_multiple sol;
    sol.ope();
}
```
计科1904蒋秉辰
8208190621