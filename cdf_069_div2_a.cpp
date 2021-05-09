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
lld prime (lld x){
    for(lld i = 2; i < x; i++){
        if (x%i == 0)
            return 0;
    }
    return 1;
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
    cin >> n;
    cin >> m;
    lld f = 1;
    for(lld i = n+1;;i = i + 1){
        if (prime(i)){
            if (i!=m){
                f = 0;
            }
                break;
        }
    }
    if (f == 1)
        cout << "YES";
    else
        cout <<  "NO";
    return 0;
}