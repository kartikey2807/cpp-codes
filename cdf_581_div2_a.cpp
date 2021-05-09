#include <bits/stdc++.h>
#include <set>
#include <stack>
#include <vector>
using namespace std;
typedef double  dbl;
typedef long long int lld;
#define FastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
double getComb (double n, double x){
    if (x > n){
        return 0;
    }
    else{
        double r = 1.0;
        for(double i = 1.0; i<=x; i += 1){
            double a = n-i+1;
            double b = a / i;
            r*=b;
        }
        return r;
    }
}
int main () {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("inputf.in",  "r",  stdin);
    // for writing output to output.txt
    freopen("outputf.in", "w", stdout);
    #endif
    FastIO
    string s;
    cin >> s;
    lld i, n;
    lld f, c;
    n = s.length();
    f = 0;
    c = 0;
    for(i = 1;i < n;i++){
        if (s[i] == '1'){
            f = 1;
        }
            c+= 1;
    }
    if (c%2 == 0){
        if (f==1)
            cout << (c / 2) + 1;
        else
            cout << (c / 2) + 0;
    }
    else{
            cout << (c / 2) + 1;
    }
    return 0;
}