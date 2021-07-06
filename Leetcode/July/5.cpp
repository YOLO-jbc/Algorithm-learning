/* 726. Number of Atoms */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    stack<map<string, int>> mstack;
    string countOfAtoms(string formula)
    {
        map<string, int> tempmap;
        int size = formula.size();
        mstack.push(tempmap);
        for (int i = 0; i < size; i++)
        {
            tempmap.clear();
            if (formula[i] == '(')
            {
                mstack.push(tempmap);
                continue;
            }
            else if (formula[i] == ')')
            {
                if (formula[i + 1] >= '0' && formula[i + 1] <= '9')
                {
                    i++;
                    int times = get_num(formula, i);
                    if (mstack.size() > 1)
                    {
                        tempmap = mstack.top();
                        mstack.pop();
                        for (auto &t : tempmap)
                        {
                            t.second *= times;
                            mstack.top()[t.first] += t.second;
                        }
                    }
                    else //!only one hash
                    {
                        for (auto t : mstack.top())
                        {
                            t.second *= times;
                        }
                    }
                }
                else
                {
                    tempmap = mstack.top();
                    mstack.pop();
                    for (auto &t : tempmap)
                    {
                        mstack.top()[t.first] += t.second;
                    }
                }
            }
            else if (formula[i] >= 'A' && formula[i] <= 'Z')
            {
                string temp = "";
                temp.push_back(formula[i]);
                if (formula[i + 1] >= '0' && formula[i + 1] <= '9') //!nums
                {
                    i++;
                    int time = get_num(formula, i);
                    if (mstack.top()[temp] != 0)
                        mstack.top()[temp] += time;
                    else
                        mstack.top()[temp] = time;
                }
                else if (formula[i + 1] >= 'a' && formula[i + 1] <= 'z') //!element
                {
                    temp.push_back(formula[i + 1]);
                    i++;

                    if (formula[i + 1] >= '0' && formula[i + 1] <= '9')
                    {
                        i++;
                        int time = get_num(formula, i);
                        if (mstack.top()[temp] != 0)
                            mstack.top()[temp] += time;
                        else
                            mstack.top()[temp] = time;
                        continue;
                    }
                    if (mstack.top()[temp] == 0)
                        mstack.top()[temp] = 1;
                    else
                        mstack.top()[temp] += 1;
                }
                else //!single atom
                {
                    if (mstack.top()[temp] == 0)
                        mstack.top()[temp] = 1;
                    else
                        mstack.top()[temp] += 1;
                }
            }
        }
        tempmap = mstack.top();
        string ans = "";
        for (auto t : tempmap)
        {
            string times;
            ans.append(t.first);
            times = to_string(t.second);
            if (t.second != 1)
                ans.append(times);
        }
        return ans;
    }

private:
    int get_num(string s, int &i)
    {
        int ret = s[i] - '0';
        int j;
        for (j = i + 1; j < s.size(); j++)
        {
            if (s[j] >= '0' && s[j] <= '9')
            {
                ret *= 10;
                ret += s[j] - '0';
                i++;
            }
            else
                break;
        }
        return ret;
    }
};
int main()
{
    Solution sol;
    cout << sol.countOfAtoms("Mg(H2O)N") << endl;
}