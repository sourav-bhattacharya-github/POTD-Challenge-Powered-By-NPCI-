// Link: https://www.geeksforgeeks.org/problems/union-of-two-arrays3538/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findUnion(vector<int> &a, vector<int> &b)
    {
        // code here

        // This is hash map fot each element
        unordered_set<int> set;

        // result array
        vector<int> res;

        // insert all element in hash map set
        for (int ele : a)
        {
            set.insert(ele);
        }

        // it incremend element present in both and for distinct element addnew
        for (int ele : b)
        {
            set.insert(ele);
        }

        // add single time fro each element
        for (auto ele : set)
        {
            res.push_back(ele);
        }

        // return the result
        return res;
    }
};