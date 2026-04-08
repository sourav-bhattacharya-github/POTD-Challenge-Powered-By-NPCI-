// Link: https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void segregate0and1(vector<int> &arr)
    {
        // code here

        int left = 0;
        int right = arr.size() - 1;

        while (left < right)
        {
            if (arr[left] == 0)
            {
                left++;
            }
            else if (arr[right] == 1)
            {
                right--;
            }
            else
            {
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {0, 1, 0, 1, 0, 1};
    sol.segregate0and1(arr);
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}