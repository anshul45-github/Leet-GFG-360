#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n) {
        if(n == 1 || n == 2)
                return 1;
        int a = 1;
        int b = 1;
        for(int i = 2; i < n; i++) {
                int k = b;
                b = a + b;
                a = k;
        }
        return b;
}

int main()
{
        int n;
        cin >> n;
        cout << fibonacci(n);
        return 0;
}
