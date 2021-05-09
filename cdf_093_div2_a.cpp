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
    lld n, k;
    cin >> n;
    cin >> k;
    lld i, j;
    dbl X[n];
    dbl Y[n];
    dbl s, d;
    for(i = 0; i < n; i += 1){
        cin >> X[i];
        cin >> Y[i];
    }
    d = 0;
    for(i = 1; i < n; i += 1){
        s = sqrt(pow(X[i] - X[i-1],2) + pow(Y[i] - Y[i-1],2));
        d+= s;
    }
        d*= k;
        cout << fixed << setprecision(9) << d / 50.00 << "\n";
    return 0;
}