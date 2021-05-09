#include <bits/stdc++.h>
#include <set>
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
    lld n, i;
    cin >> n;
    n+=1;
    lld A[n];
    lld B[n];
    for(i = 1; i<n; i+=1){
        cin >>A[i];
    }
    for(i = 1; i<n; i+=1){
        B[A[i]]= i;
    }
    for(i = 1; i<n; i+=1){
        cout <<B[i]<< " ";
    }
    return 0;
}