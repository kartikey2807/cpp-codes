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
    lld a;
    lld b;
    cin >> a;
    cin >> b;
    lld c = 6 - (a>b?a:b)+1;
    lld max = 6 > c ? 6 : c;
    lld min = 6 < c ? 6 : c;
    while (min != 0){
        lld rem = max % min;
        max = min;
        min = rem;
    }
    cout <<(c/max)<<"/"<<(6/max)<<"\n";
    return 0;
}