#include <bits/stdc++.h>
#include <set>
#include <stack>
#include <vector>
using namespace std;
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
lld gcd (lld x, lld y){
    lld r;
    while(y != 0){
        r = x % y;
        x = y;
        y = r;
    }
    return(x);
}
int main () {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("inputf.in",  "r",  stdin);
    // for writing output to output.txt
    freopen("outputf.in", "w", stdout);
    #endif
    FastIO
    lld l, r;
    cin >> l;
    cin >> r;
    lld i, j;
    lld k, f;
    f = 0;
    for(i = l; i <= r-2; i += 1){
        for(j = i+1;j<=r-1; j++){
            for(k=j+1;k<=r; k++){
                if (gcd(j, i) == 1 && gcd(k, j) == 1 && gcd(k, i) != 1){
                    f = 1;
                    break;
                }
            }
            if (f == 1) break;
        }
            if (f == 1) break;
    }
    if (f == 1)
        cout << i << " " << j << " " << k << "\n";
    else
        cout << "-1\n";
    return 0;
}