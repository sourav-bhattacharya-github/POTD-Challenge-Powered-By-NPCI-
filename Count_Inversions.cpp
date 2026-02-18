#include <vector>
class Solution
{
public:
    int mergeAndCount(vector<int> &arr, int left, int mid, int right)
    {
        vector<int> temp;

        int i = left, j = mid + 1;

        int inv = 0;

        while (i <= mid && j <= right)
        {
            if (arr[i] <= arr[j])
            {
                temp.push_back(arr[i++]);
            }
            else
            {
                temp.push_back(arr[j++]);
                inv += (mid - i + 1);
            }
        }

        while (i <= mid)
            temp.push_back(arr[i++]);
        while (j <= right)
            temp.push_back(arr[j++]);

        for (int k = left; k <= right; k++)
        {
            arr[k] = temp[k - left];
        }

        return inv;
    }

    int mergeSort(vector<int> &arr, int left, int right)
    {
        int inv = 0;
        if (left < right)
        {
            int mid = (left + right) / 2;
            inv += mergeSort(arr, left, mid);
            inv += mergeSort(arr, mid + 1, right);

            inv += mergeAndCount(arr, left, mid, right);
        }

        return inv;
    }

    int inversionCount(vector<int> &arr)
    {
        // Code Here
        return mergeSort(arr, 0, arr.size() - 1);
    }
};