// LeetCode 1456 - Maximum Number of Vowels in a Substring of Given Length
// Approach: Sliding window of size k. Track vowel count, slide across the string.
// Time: O(n) | Space: O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        auto isVowel = [](char c) {
            return string("aeiou").find(c) != string::npos;
        };

        int count = 0;
        for (int i = 0; i < k; i++)
            if (isVowel(s[i])) count++;

        int maxCount = count;
        for (int i = k; i < (int)s.size(); i++) {
            if (isVowel(s[i])) count++;
            if (isVowel(s[i - k])) count--;
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};
