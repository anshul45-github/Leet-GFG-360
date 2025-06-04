// https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/
// Medium

#include <string>
using namespace std;

class Solution {
    int larger(string& word, int idx1, int idx2, int numFriends) {
        int k = 0;
        while(k < word.size() - numFriends + 1 && k + idx1 < word.size()) {
            if(word[k + idx1] < word[k + idx2])
                return idx2;
            else if(word[k + idx1] > word[k + idx2])
                return idx1;
            k++;
        }
        return idx2;
    }
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1)
            return word;
        int largest = 0;
        for(int i = 1; i < word.size(); i++) 
            largest = larger(word, i, largest, numFriends);
        return word.substr(largest, min(word.size() - largest, word.size() - numFriends + 1));
    }
};