// https://leetcode.com/problems/push-dominoes/
// 838. Push Dominoes
// Medium

#include<string>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        for(int i = 0; i  < dominoes.size(); i++) {
            if(dominoes[i] == 'L') {
                // int cnt = 0;
                int j = i - 1;
                // cout << j << " ";
                while(j >= 0 && dominoes[j] == '.') {
                    dominoes[j] = 'L';
                    // cout << j << " " << dominoes << " ";
                    j--;
                }
            }
            else if(dominoes[i] == 'R') {
                int j = i + 1;
                int cnt = 0;
                while(j < dominoes.size() && dominoes[j] == '.') {
                    cnt++;
                    j++;
                }
                if(dominoes[j] == 'L') {
                    j--;
                    for(int k = 0; k < (cnt >> 1); k++)
                        dominoes[j--] = 'L';
                    j = i + 1;
                    for(int k = 0; k < (cnt >> 1); k++)
                        dominoes[j++] = 'R';
                    i += cnt + 1;
                }
                else {
                    j = i + 1;
                    for(int k = 0; k < cnt; k++)
                        dominoes[j++] = 'R';
                }
            }
        }
        return dominoes;
    }
};