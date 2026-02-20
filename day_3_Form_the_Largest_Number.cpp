// Link: https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1
#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    static bool cmp(string &a, string &b)
    {
        return a + b > b + a;
    }

    string findLargest(vector<int> &arr)
    {
        // code here
        vector<string> temp;

        for (int n : arr)
        {
            temp.push_back(to_string(n));
        }

        sort(temp.begin(), temp.end(), cmp);

        if (temp[0] == "0")
            return "0"; // handel all zeros

        string res = "";

        for (string &s : temp)
        {
            res += s;
        }

        return res;
    }
};