// Link: https://www.geeksforgeeks.org/problems/find-position-of-set-bit3706/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findPosition(int n) {
        // code here
        if(n == 0 || (n & (n - 1)) != 0) return -1;
        
        int pos = 1;
        
        while(n > 1) {
            n >>= 1;
            pos++;
        }
        
        return pos;
    }
};

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        Solution ob;
        cout << ob.findPosition(n) << endl;
    }
    
    return 0;
}

/*
Question: Given a number N. The task is to find the position of the only set bit in the given number. If there is no set bit or more than one set bit, then return -1.

Example 1:
Input: N = 18
Output: -1
Explanation: 18 in binary is 10010, which has more than one set bit. Hence, the output is -1.

Example 2:
Input: N = 4
Output: 3
Explanation: 4 in binary is 100, which has only one set bit at position 3 (from the right, starting at 1). Hence, the output is 3. 

Example 3:
Input: N = 0
Output: -1
Explanation: 0 in binary is 0, which has no set bits. Hence, the output is -1.  

Constraints:
1 <= N <= 10^8

=================================================================================================

Approach:
1. First, we check if N is 0 or if it has more than one set bit. We can do this by checking if N is not a power of 2, which can be determined using the expression (N & (N - 1)) != 0. If either condition is true, we return -1.
2. If N is a power of 2, we initialize a variable pos to 1, which will keep track of the position of the set bit.
3. We then right shift N until it becomes 1, incrementing pos with each shift. This will give us the position of the set bit.
4. Finally, we return pos as the result.

Dry Run:
Let's take N = 4 as an example:
- N = 4 (binary: 100)
- Check if N is 0 or has more than one set bit: (4 & (4 - 1)) = (4 & 3) = (100 & 011) = 0, so we proceed.
- Initialize pos = 1.
- Right shift N until it becomes 1:
  - N = 4 (binary: 100), pos = 1
  - N >>= 1 -> N = 2 (binary: 10), pos = 2
  - N >>= 1 -> N = 1 (binary: 1), pos = 3
- Now N is 1, so we stop and return pos, which is 3. This indicates that the set bit is at position 3 from the right.

*/