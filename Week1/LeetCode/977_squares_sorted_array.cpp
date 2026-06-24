// LeetCode 977 - Squares of a Sorted Array
// Approach: Two pointers from both ends. Largest square is always at one of the ends.
// Follow-up: O(n) two-pointer instead of O(n log n) sort.
// Time: O(n) | Space: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int left = 0, right = n - 1, pos = n - 1;

        while (left <= right) {
            int lsq = nums[left] * nums[left];
            int rsq = nums[right] * nums[right];
            if (lsq > rsq) {
                result[pos--] = lsq;
                left++;
            } else {
                result[pos--] = rsq;
                right--;
            }
        }
        return result;
    }
};
