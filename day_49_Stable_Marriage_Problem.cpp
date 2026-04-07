// Link: https://www.geeksforgeeks.org/problems/stable-marriage-problem/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> stableMarriage(vector<vector<int>> &men, vector<vector<int>> &women)
    {
        int n = men.size();

        vector<int> wife(n, -1);    // woman → man
        vector<int> husband(n, -1); // man → woman
        vector<int> next(n, 0);     // next proposal index

        // rank[w][m] → preference rank of man m for woman w
        vector<vector<int>> rank(n, vector<int>(n));

        for (int w = 0; w < n; w++)
        {
            for (int i = 0; i < n; i++)
            {
                rank[w][women[w][i]] = i;
            }
        }

        queue<int> freeMen;
        for (int i = 0; i < n; i++)
            freeMen.push(i);

        while (!freeMen.empty())
        {
            int m = freeMen.front();
            freeMen.pop();

            int w = men[m][next[m]];
            next[m]++;

            if (wife[w] == -1)
            {
                // woman is free
                wife[w] = m;
                husband[m] = w;
            }
            else
            {
                int m2 = wife[w];

                if (rank[w][m] < rank[w][m2])
                {
                    // woman prefers new man
                    wife[w] = m;
                    husband[m] = w;

                    husband[m2] = -1;
                    freeMen.push(m2);
                }
                else
                {
                    // reject
                    freeMen.push(m);
                }
            }
        }

        return husband;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> men = {{0, 1, 2}, {0, 1, 2}, {0, 1, 2}};
    vector<vector<int>> women = {{0, 1, 2}, {0, 1, 2}, {0, 1, 2}};
    vector<int> result = sol.stableMarriage(men, women);
    for (int i = 0; i < result.size(); i++)
    {
        cout << "Man " << i << " is married to Woman " << result[i] << endl;
    }
    return 0;
}

/*
Question: Stable Marriage Problem
Given n men and n women, and their preferences for each other, find a stable matching between the men and women. A stable matching is one where there are no two people of opposite sex who would both prefer each other over their current partners.

Example:
Input:
Men's preferences: [[0, 1, 2], [0, 1, 2], [0, 1, 2]]
Women's preferences: [[0, 1, 2], [0, 1, 2], [0, 1, 2]]
Output: [0, 1, 2]
Explanation: Each man is matched with the woman they prefer most, and each woman is matched with the man they prefer most.

Note: The output is an array where the index represents the man and the value at that index represents the woman he is married to. The output may vary based on the preferences provided.

==================================================================================================================
Approach:
1. Use the Gale-Shapley algorithm to find a stable matching.
2. Initialize all men and women as free.
3. While there are free men:
    a. Select a free man and let him propose to the next woman on his preference list.
    b. If the woman is free, she accepts the proposal.
    c. If the woman is not free, she compares the new proposal with her current partner. If she prefers the new proposal, she accepts it and her current partner becomes free. Otherwise, she rejects the new proposal and the man remains free.
4. Repeat the process until all men are matched. The resulting matches will be stable.


Time Complexity: O(n^2) in the worst case, where n is the number of men/women.
Space Complexity: O(n^2) for the rank matrix and O(n) for the wife and husband arrays.


Dry run:
Men's preferences: [[0, 1, 2], [0, 1, 2], [0, 1, 2]]
Women's preferences: [[0, 1, 2], [0, 1, 2], [0, 1, 2]]
- Initially, all men and women are free.
- Man 0 proposes to Woman 0.
- Woman 0 accepts the proposal since she is free. (Man 0 is now married to Woman 0)
- Man 1 proposes to Woman 0.
- Woman 0 compares Man 1 with her current partner Man 0. Since she prefers Man 0, she rejects the proposal from Man 1. (Man 1 remains free)
- Man 1 proposes to Woman 1.
- Woman 1 accepts the proposal since she is free. (Man 1 is now married to Woman 1)
- Man 2 proposes to Woman 0.
- Woman 0 compares Man 2 with her current partner Man 0. Since she prefers Man 0, she rejects the proposal from Man 2. (Man 2 remains free)
- Man 2 proposes to Woman 1.
- Woman 1 compares Man 2 with her current partner Man 1. Since she prefers Man 1, she rejects the proposal from Man 2. (Man 2 remains free)
- Man 2 proposes to Woman 2.
- Woman 2 accepts the proposal since she is free. (Man 2 is now married to Woman 2)
- All men are now married, and the resulting matches are:
Man 0 is married to Woman 0
Man 1 is married to Woman 1
Man 2 is married to Woman 2


*/