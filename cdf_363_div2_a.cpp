#include <bits/stdc++.h>
#include <set>
#include <stack>
#include <vector>
using namespace std;
typedef char chr;
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
    lld n, i;
    cin >> n;
    chr C[n];
    lld A[n];
    lld m, f;
    for(i = 0; i<n; i++){
        cin >>C[i];
    }
    for(i = 0; i<n; i++){
        cin >>A[i];
    }
    f = 0;
    m=std::numeric_limits<lld>::max();
    for(i = 0;i<n-1;i++){
        if (C[i]=='R' && C[i+1]=='L'){
            lld d = (A[i+1] - A[i])/2;
            if (d < m){
                m = d;
            }
            f = 1;
        }
    }
    if (f == 1)
        cout << m;
    else
        cout << "-1";
    return 0;
}