// Link: https://www.geeksforgeeks.org/problems/course-schedule-i/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFinish(int n, vector<vector<int>> &prerequisites)
    {
        // Code here
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (auto &p : prerequisites)
        {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        int count = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;

            for (auto neigh : adj[node])
            {
                indegree[neigh]--;
                if (indegree[neigh] == 0)
                    q.push(neigh);
            }
        }

        return count == n;
    }
};

int main()
{
    Solution sol;
    int n = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    cout << sol.canFinish(n, prerequisites) << endl; // Output: 1 (true)

    n = 2;
    prerequisites = {{1, 0}, {0, 1}};
    cout << sol.canFinish(n, prerequisites) << endl; // Output: 0 (false)

    return 0;
}

/*
Question:
Given the total number of courses and a list of prerequisite pairs, determine if it is possible for a student to finish all courses. For example, if there are 2 courses and the prerequisite pairs are [[1, 0]], it means to take course 1 you have to first take course 0. This is possible, so the output should be true. However, if the prerequisite pairs are [[1, 0], [0, 1]], it means to take course 1 you have to first take course 0 and to take course 0 you have to first take course 1. This creates a cycle and makes it impossible to finish all courses, so the output should be false.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Eplanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Eplanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Constraints:
1 <= numCourses <= 10^5
0 <= prerequisites.length <= 10^5
prerequisites[i].length == 2
prerequisites[i][0] != prerequisites[i][1]
prerequisites[i] are distinct.

===============================================================================================================

🐢 Approach 1: Brute Force (Try all orders)
- Try all permutations of courses
- Check if valid

 Not practical (n! complexity)

🚀 Approach 2: DFS (Cycle Detection)
Idea:
- Use visited + pathVisited
- visited[] → node visited before
- pathVisited[] → node in current recursion
Rule:
If we revisit a node in same path → cycle


⚡ Approach 3: BFS (Kahn’s Algorithm) ⭐ BEST
Idea:
- Count indegree
- Start with nodes having indegree = 0
- Remove them and update graph

👉 If we process all nodes → no cycle


Dry Run:
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Adjacency List:
0 → [1, 2]
1 → [3]
2 → [3]
Indegree:
0: 0
1: 1
2: 1
3: 2
- Start with nodes having indegree 0 → [0]
- Process 0 → count = 1
- Update indegree:
  1: 0
  2: 0
- Add 1 and 2 to queue → [1, 2]
- Process 1 → count = 2
- Update indegree:
  3: 1
- Process 2 → count = 3
- Update indegree:
    3: 0
- Add 3 to queue → [3]
- Process 3 → count = 4

Output: true (count == numCourses)



| Approach | Time     | Space |
| -------- | -------- | ----- |
| DFS      | O(V + E) | O(V)  |
| BFS      | O(V + E) | O(V)  |

*/