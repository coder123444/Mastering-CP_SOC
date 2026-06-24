// LeetCode 136 - Single Number
// Approach: XOR all elements. Duplicate elements cancel out (a^a=0), leaving the unique one.
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int x : nums)
            result ^= x;
        return result;
    }
};
