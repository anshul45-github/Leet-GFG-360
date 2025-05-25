// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/
// Medium

// Given an array of strings words, return the maximum length of a palindrome that can be built using each word exactly once.

// Words consist of lowercase English letters.

// If it is impossible to form any palindrome, return 0.

// Example 1:
// Input: words = ["lc","cl","gg"]
// Output: 6
// Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl".

// Example 2:
// Input: words = ["ab","ty","yt","lc","cl","ab"]
// Output: 8
// Explanation: One longest palindrome is "ty" + "lc" + "cl" + "yt" + "ab" + "ab" = "tylcclyt".

// Example 3:
// Input: words = ["cc","ll","xx"]
// Output: 2
// Explanation: One longest palindrome is "cc".

// Constraints:
// 1 <= words.length <= 10^5
// 1 <= words[i].length == 2
// words[i] consists of lowercase English letters.

// Note: This code is written in C++14 standard.

// The code is designed to solve the problem of finding the longest palindrome by concatenating two-letter words.

// The solution uses a hash map to count occurrences of each word and checks for palindromic pairs.

// The algorithm efficiently calculates the maximum length of a palindrome that can be formed with the given words.

// Time complexity: O(n), where n is the number of words.

// Space complexity: O(n), for storing the word counts in the hash map.

// The code is efficient and suitable for large input sizes, adhering to the problem constraints.

#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        for(int i = 0; i < words.size(); i++)
            mp[words[i]]++;
        bool same = false;
        int ans = 0;
        for(string& word : words) {
            reverse(word.begin(), word.end());
            if(mp[word]) {
                if(word[0] == word[1]) {
                    if(mp[word] % 2 == 1) {
                        ans += mp[word] * 2;
                        mp[word] = 0;
                        if(same)
                            ans -= 2;
                        same = true;
                    }
                    else { 
                        ans += mp[word] * 2;
                        mp[word] = 0;
                    }
                }
                else {
                    int a = mp[word];
                    mp[word] = 0;
                    reverse(word.begin(), word.end());
                    int b = mp[word];
                    mp[word] = 0;
                    ans += min(a, b) * 4;
                }
            }
        }
        return ans;
    }
};