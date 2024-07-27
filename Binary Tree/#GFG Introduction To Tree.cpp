/**
 * Optimal solution using maths
 * Time complexity = O(1)
 * Space Complexity = O(1)
 */

class Solution {
  public:
    int countNodes(int i) {
        // your code here
        int y = (1 << i) - 1;
        i--;
        int x = (1 << i) - 1;
        return y - x;
    }
};
