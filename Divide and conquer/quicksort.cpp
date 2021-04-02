#include <bits/stdc++.h>
using namespace std;
template <class T>
class Solution
{
public:
    vector<T> arr;
    void Quicksort1(int left, int right)
    {
        if (left >= right) //!you forget this
            return;
        int i, j, pivot;
        i = left;
        j = right;
        //^recognize the left element as the pivot
        pivot = arr[left];
        while (i < j)
        {
            //!find a small one
            while (arr[j] >= pivot && i < j)
                j--;
            //!find a big one
            while (arr[i] <= pivot && i < j)
                i++;
            //?find a pair of elements shoulb be swapped
            if (i < j)
                swap(arr[i], arr[j]);
        }
        //!pay attention
        swap(arr[i], arr[left]);
        Quicksort1(left, i - 1);
        Quicksort1(i + 1, right);
    }
    void Quicksort2(int left, int right)
    {
        if (left >= right)
            return;
        int i, pivot, store;
        pivot = arr[left];
        store = left + 1;
        for (i = store; i <= right; i++)
        {
            if (arr[i] <= pivot)
            {
                swap(arr[i], arr[store]);
                store++;
            }
        }
        swap(arr[left], arr[store - 1]);
        Quicksort2(left, store - 2);
        Quicksort2(store, right);
    }
    void Quicksort3(int left, int right)
    {
        if (left >= right)
            return;
        int pivot = left;
        int store = pivot + 1;
        for (int i = store; i <= right; i++)
        {
            if (arr[i] <= arr[pivot])
            {
                swap(arr[i], arr[store++]);
            }
        }
        swap(arr[left], arr[store - 1]);
        Quicksort3(left, store - 2);
        Quicksort3(store, right);
    }

    friend ostream &operator<<(ostream &output, Solution a)
    {
        for (auto t : a.arr)
        {
            output << t << " ";
        }
        output << endl;
        return output;
    }

private:
    void swap(T &a, T &b)
    {
        T temp;
        temp = a;
        a = b;
        b = temp;
    }
};
template <class T>
void creat(vector<T> &arr, int size)
{
    arr.resize(size);
    for (auto &t : arr)
    {
        t = rand() % 40;
    }
}
int main()
{
    srand((unsigned)time(NULL));
    int size = rand() % 8 + 8;
    vector<int> arr;
    creat(arr, size);
    Solution<int> a;
    a.arr = arr;
    a.Quicksort3(0, arr.size() - 1);
    cout << a;
}
/* 
    It's obvious that Quicksort2 is better to understand and to write








 */