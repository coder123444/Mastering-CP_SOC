// LeetCode 1122 - Relative Sort Array
// Approach: Use a map to store order from arr1, custom sort arr2 accordingly.
// Elements not in arr1 go at the end in ascending order.
// Time: O(n log n) | Space: O(n)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> order;
        for (int i = 0; i < (int)arr2.size(); i++)
            order[arr2[i]] = i;

        sort(arr1.begin(), arr1.end(), [&](int a, int b) {
            bool inA = order.count(a), inB = order.count(b);
            if (inA && inB) return order[a] < order[b];
            if (inA) return true;
            if (inB) return false;
            return a < b;
        });
        return arr1;
    }
};
