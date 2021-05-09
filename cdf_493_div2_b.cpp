#include <bits/stdc++.h>
#include <set>
#include <string>
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
    lld b, c;
    cin >> b;
    lld A[n];
    lld B[n];
    lld o, e;
    for(i = 0; i < n; i += 1){
        cin >> A[i];
        B[i]  =  -1;
    }
    o = 0;
    e = 0;
    lld k;
    k = 0;
    for(i = 0; i < n; i += 1){
        if (A[i] % 2 == 0){
            e++;
        }
        if (A[i] % 2 != 0){
            o++;
        }
        if (e == o){
            if (i!=n-1){
                B[k] = A[i]>A[i+1] ? (A[i]-A[i+1]) : (A[i+1]-A[i]);
                k++;
            }
            e  =  0;
            o  =  0;
        }
    }
    sort(B , B + k);
    c = 0;
    for(i = 0; i < k; i += 1){
        if (b - B[i] >= 0){
            b -=B[i];
            c++;
        }
    }
    cout << c <<"\n";
    return 0;
}