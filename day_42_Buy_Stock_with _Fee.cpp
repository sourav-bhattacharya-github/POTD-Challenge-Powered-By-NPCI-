// Link: https://www.geeksforgeeks.org/problems/buy-stock-with-transaction-fee/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &arr, int fee)
    {
        int n = arr.size();

        int aheadBuy = 0;  // dp[i+1][1]
        int aheadSell = 0; // dp[i+1][0]

        for (int i = n - 1; i >= 0; i--)
        {
            int currBuy = max(-arr[i] + aheadSell, aheadBuy);
            int currSell = max(arr[i] - fee + aheadBuy, aheadSell);

            aheadBuy = currBuy;
            aheadSell = currSell;
        }

        return aheadBuy;
    }
};

int main()
{
    Solution sol;
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;

    int result = sol.maxProfit(prices, fee);
    cout << result << endl; // Output: Maximum profit with transaction fee

    return 0;
}

/*
Question: You are given an array of stock prices and a transaction fee. You can buy and sell stocks multiple times, but each transaction incurs a fee. Find the maximum profit you can achieve.

Example 1:
Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buy on day 0 (price = 1)
- Sell on day 3 (price = 8)
- Buy on day 4 (price = 4)
- Sell on day 5 (price = 9)
The total profit is (8 - 1 - 2) + (9 - 4 - 2) = 8.

Example 2:
Input: prices = [1, 3, 7, 5, 10, 3], fee = 3
Output: 6
Explanation: The maximum profit can be achieved by:
- Buy on day 0 (price = 1)
- Sell on day 2 (price = 7)
The total profit is (7 - 1 - 3) = 3.
- Buy on day 3 (price = 5)
- Sell on day 4 (price = 10)
The total profit is (10 - 5 - 3) = 2.
The total profit is 3 + 2 = 5.
The total profit is 6.

Constraints:
1 <= prices.length <= 5 * 10^4
1 <= prices[i] < 5 * 10^4
0 <= fee < 5 * 10^4

================================================================================================
Approach: Dynamic Programming (Space Optimized)
1. We can use two variables, `aheadBuy` and `aheadSell`, to store the maximum profit for the next day when we are in a "buy" state and a "sell" state, respectively.
2. We iterate through the prices array in reverse order, calculating the current day's maximum profit for both states based on the future values stored in `aheadBuy` and `aheadSell`.
3. The final answer will be stored in `aheadBuy` after processing all days, as it represents the maximum profit when we are allowed to buy on the first day.

Time Complexity: O(n), where n is the number of days (length of the prices array).
Space Complexity: O(1) due to the use of only a constant amount of extra space
for the variables.

Dry Run:
Input: prices = [1, 3, 2, 8, 4, 9], fee = 2
- Start from the last day (i = 5):
    - currBuy = max(-9 + 0, 0) = 0
    - currSell = max(9 - 2 + 0, 0) = 7
    - aheadBuy = 0, aheadSell = 7
- i = 4:
    - currBuy = max(-4 + 7, 0) = 3
    - currSell = max(4 - 2 + 0, 7) = 7
    - aheadBuy = 3, aheadSell = 7
- i = 3:
    - currBuy = max(-8 + 7, 3) = 3
    - currSell = max(8 - 2 + 3, 7) = 9
    - aheadBuy = 3, aheadSell = 9
- i = 2:
    - currBuy = max(-2 + 9, 3) = 7
    - currSell = max(2 - 2 + 3, 9) = 9
    - aheadBuy = 7, aheadSell = 9
- i = 1:
    - currBuy = max(-3 + 9, 7) = 7
    - currSell = max(3 - 2 + 7, 9) = 9
    - aheadBuy = 7, aheadSell = 9
- i = 0:
    - currBuy = max(-1 + 9, 7) = 8
    - currSell = max(1 - 2 + 7, 9) = 9
    - aheadBuy = 8, aheadSell = 9
Output: 8

*/