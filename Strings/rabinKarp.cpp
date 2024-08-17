#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int BASE = 1000000;
public:
    bool Rabin_Karp(string source, string target) {
        if(source == "")
            return false;

        int m = target.size();
        int power = 1;

        for(int i = 0; i < m; i++)
            power = (power*31) % BASE;

        int targetCode = 0;

        for(int i = 0; i < m; i++)
            targetCode = (targetCode * 31 + target[i]) % BASE;

        int hashCode = 0;

        for(int i = 0; i < source.size(); i++){
            hashCode = (hashCode*31 + source[i]) % BASE;
            if(i < m - 1)
                continue;
            if(i >= m)
                hashCode = (hashCode - source[i - m] * power) % BASE;
            if(hashCode < 0)
                hashCode += BASE;
            if(hashCode == targetCode) {
                if(source.substr(i - m + 1, m) == target)
                    return true;
            }
        }
        return false;
    }

    int repeatedStringMatch(string A, string B) {
        if(B == "")
        return 0;

        int count = 1;
        string source = A;

        while(source.size() < B.size()){
            count++;
            source += A;
        }

        if(Rabin_Karp(source, B))
            return count;
        if(Rabin_Karp(source + A, B))
            return count + 1;

        return -1;
    }
};
