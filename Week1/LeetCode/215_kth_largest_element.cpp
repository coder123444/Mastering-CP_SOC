// LeetCode 215 - Kth Largest Element in an Array
// Approach: QuickSelect (average O(n), no sorting needed).
// Time: O(n) average | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // nth_element rearranges so that the element at (end-k) is what would be there if sorted
        nth_element(nums.begin(), nums.end() - k, nums.end());
        return nums[nums.size() - k];
    }
};

// Manual QuickSelect for deeper understanding:
// int partition(vector<int>& nums, int left, int right) {
//     int pivot = nums[right], i = left;
//     for (int j = left; j < right; j++)
//         if (nums[j] <= pivot) swap(nums[i++], nums[j]);
//     swap(nums[i], nums[right]);
//     return i;
// }
// int quickSelect(vector<int>& nums, int left, int right, int k) {
//     int p = partition(nums, left, right);
//     if (p == k) return nums[p];
//     return p < k ? quickSelect(nums, p+1, right, k) : quickSelect(nums, left, p-1, k);
// }
// int findKthLargest(vector<int>& nums, int k) {
//     return quickSelect(nums, 0, nums.size()-1, nums.size()-k);
// }
