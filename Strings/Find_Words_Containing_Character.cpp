// https://leetcode.com/problems/find-words-containing-character/
// Easy

// Given an array of strings words and a character x, return the indices of the words that contain the character x.

// Example 1:
// Input: words = ["hello", "world", "leetcode"], x = 'o'
// Output: [0, 1, 2]
// Explanation: The words "hello" and "world" contain the character 'o', so their indices are returned.

// Example 2:
// Input: words = ["apple", "banana", "cherry"], x = 'a'
// Output: [0, 1]
// Explanation: The words "apple" and "banana" contain the character 'a', so their indices are returned.

// Constraints:
// 1 <= words.length <= 50
// 1 <= words[i].length <= 50
// words[i] consists of lowercase English letters.

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> a;
        for(int i = 0; i < words.size(); i++) {
            for(char ch : words[i]) {
                if(ch == x) {
                    a.push_back(i);
                    break;
                }
            }
        }
        return a;
    }
};