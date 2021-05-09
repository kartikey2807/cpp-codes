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
    lld n, m;
    lld t, i;
    cin >> n;
    cin >> m;
    cin >> t;
    double s = 0.0;
    for(i = 4; i<t;i+=1){
        double x = getComb((double) n, (double)  i);
        double y = getComb((double) m, (double)t-i);
        s+=(x*y);
    }
    cout << s << "\n";
    return 0;
}