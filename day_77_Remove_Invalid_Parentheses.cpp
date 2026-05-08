// Link: https://www.geeksforgeeks.org/problems/remove-invalid-parentheses/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        int cnt = 0;

        for (char ch : s)
        {
            if (ch == '(')
            {
                cnt++;
            }
            else if (ch == ')')
            {
                cnt--;

                if (cnt < 0)
                    return false;
            }
        }

        return cnt == 0;
    }
    vector<string> validParenthesis(string &s)
    {
        // code here
        vector<string> ans;

        queue<string> q;
        unordered_set<string> vis;

        q.push(s);
        vis.insert(s);

        bool found = false;

        while (!q.empty())
        {

            string curr = q.front();
            q.pop();

            if (isValid(curr))
            {
                ans.push_back(curr);
                found = true;
            }

            if (found)
                continue;

            for (int i = 0; i < curr.size(); i++)
            {
                if (curr[i] != '(' && curr[i] != ')')
                    continue;

                string next = curr.substr(0, i) + curr.substr(i + 1);

                if (vis.find(next) == vis.end())
                {
                    vis.insert(next);
                    q.push(next);
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        string s;
        cin >> s;
        Solution ob;
        vector<string> ans = ob.validParenthesis(s);
        for (auto &x : ans)
        {
            cout << x << "\n";
        }
    }
    return 0;
}

/*
Question: Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid. Return all the possible results.


Example 1:
Input: s = "()())()"
Output: ["(())()","()()()"]
Explanation: The input string has one extra closing parenthesis. Each of the two results removes a different closing parenthesis.

Example 2:
Input: s = "(a)())()"
Output: ["(a())()","(a)()()"]
Explanation: The input string has one extra closing parenthesis. Each of the two results removes a different closing parenthesis.

Example 3:
Input: s = ")("
Output: [""]
Explanation: The input string has two extra parentheses. An empty string is also valid.

Constraints:
1 <= s.length <= 25
s consists of lowercase English letters and parentheses '(' and ')'.

==================================================================================================
Approach: BFS
1. Start with the original string in the queue.
2. For each string, check if it's valid. If it is, add it to the answer list and set a flag to indicate that we've found a valid string at the current level.
3. If we haven't found a valid string at the current level, generate all possible strings by removing one parenthesis at a time and add them to the queue for the next level.
4. Continue this process until we find valid strings, at which point we stop generating new strings and return the list of valid strings.
5. Sort the answer list before returning to ensure the results are in a consistent order.
6. Use a set to avoid processing the same string multiple times.

Time Complexity: O(N * 2^N) in the worst case, where N is the length of the string. This is because we may generate all possible combinations of parentheses by removing characters.
Space Complexity: O(N * 2^N) in the worst case, due to the

Dry Run:
Input: s = "()())()"
1. Start with the original string in the queue: q = ["()())()"]
2. Check if "()())()" is valid: No
3. Generate new strings by removing one parenthesis at a time:
    - Remove '(': ")())()"
    - Remove ')': "(()))()"
    - Remove '(': "()()()"
    - Remove ')': "()()()"
    - Remove '(': "()()))"
    - Remove ')': "()())("
    - Remove '(': "()())()"
    - Remove ')': "()())()"
    q = [")())()", "(()))()", "()()()", "()()()", "()()))", "()())(", "()())()", "()())()"]
4. Check if any of the new strings are valid:
    - ")())()": No
    - "(()))()": No
    - "()()()": Yes (add to ans)
    - "()()()": Yes (add to ans)
    - "()()))": No
    - "()())(": No
    - "()())()": No
5. Since we found valid strings at this level, we stop generating new strings and return the answer list: ans = ["(())()", "()()()"]
6. Sort the answer list: ans = ["(())()", "()()()"]


*/