// https://leetcode.com/problems/compare-version-numbers/
// Medium

// Given two version numbers, version1 and version2, return:
// -1 if version1 is less than version2,
// 1 if version1 is greater than version2, and
// 0 if they are equal.

#include <string>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0;
        int j = 0;
        while(i < version1.size() && j < version2.size()) {
            string num1 = "";
            string num2 = "";
            while(i < version1.size() && version1[i] != '.')
                num1 += version1[i++];
            while(j < version2.size() && version2[j] != '.')
                num2 += version2[j++];
            int n1 = stoi(num1);
            int n2 = stoi(num2);
            if(n1 < n2)
                return -1;
            if(n1 > n2)
                return 1;
            i++;
            j++;
        }
        while(i < version1.size()) {
            string num = "";
            while(i < version1.size() && version1[i] != '.')
                num += version1[i++];
            int n = stoi(num);
            if(n > 0)
                return 1;
            i++;
        }
        while(j < version2.size()) {
            string num = "";
            while(j < version2.size() && version2[j] != '.')
                num += version2[j++];
            int n = stoi(num);
            if(n > 0)
                return -1;
            j++;
        }
        return 0;
    }
};