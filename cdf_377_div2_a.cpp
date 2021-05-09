#include <bits/stdc++.h>
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
int main () {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("inputf.in",  "r",  stdin);
    // for writing output to output.txt
    freopen("outputf.in", "w", stdout);
    #endif
    FastIO
    lld k, r;
    cin >> k;
    cin >> r;
    lld m, s;
    s = 10*k;
    m = 10;
    lld i ;
    for(i = 9; i >= 0; i-= 1){
        s-= k;
        if (((s-r)%10 == 0 || s%10 == 0) && (s != 0)){
            m = i;
        }
    }
    cout << m << "\n";
    return 0;
}