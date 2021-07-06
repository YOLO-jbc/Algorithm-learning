/* 1418. Display Table of Food Orders in a Restaurant */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    map<int, map<string, int>> table;
    set<string> dishlist;
    vector<vector<string>> displayTable(vector<vector<string>> &orders)
    {
        for (auto t : orders)
        {
            if (dishlist.find(t[2]) == dishlist.end())
            {
                dishlist.insert(t[2]);
            }
        }
        int size1 = orders.size();
        map<string, int> initmap;
        for (auto dish : dishlist)
        {
            initmap[dish] = 0;
        }
        for (int i = 0; i < size1; i++)
        {
            int temptable = stoi(orders[i][1]);
            string tempdish = orders[i][2];
            if (table[temptable].empty())
                table[temptable] = initmap;
            table[temptable][tempdish] += 1;
        }
        vector<vector<string>> ans(table.size() + 1);
        ans[0].push_back("Table");
        for (auto dish : dishlist)
        {
            ans[0].push_back(dish);
        }
        int i = 1;
        for (auto temptable : table)
        {
            ans[i].push_back(to_string(temptable.first));
            for (auto tempdish : temptable.second)
            {
                ans[i].push_back(to_string(tempdish.second));
            }
            i++;
        }
        /*         for(auto tableitr = table.begin();tableitr!=table.end();tableitr++)
        {
            for(auto dishitr = tableitr->second.begin();dishitr!=tableitr->second.end();dishitr++)
            ;
        } */
        return ans;
    }
};
int main()
{
    Solution sol;
    vector<vector<string>> invec = {{"David", "3", "Ceviche"},
                                    {"Corina", "10", "Beef Burrito"},
                                    {"David", "3", "Fried Chicken"},
                                    {"Carla", "5", "Water"},
                                    {"Carla", "5", "Ceviche"},
                                    {"Rous", "3", "Ceviche"}};
    auto ret = sol.displayTable(invec);
    for (auto t : ret)
    {
        for (auto s : t)
        {
            cout << s << " ";
        }
        cout << endl;
    }
}