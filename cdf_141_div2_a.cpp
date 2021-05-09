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
    lld A[4];
    lld i, c;
    for(i = 0; i<4; i+=1){
        cin >>A[i];
    }
    sort(A, A + 4);
    c = 0;
    lld s;
    s = 0;
    for(i = 1; i<4; i+=1){
        if (A[i]==A[i-1]){
            c+=1;
        }
        else{
            s+=c;
            c =0;
        }
    }
            s+=c;
            cout<<s<<"\n";
    return 0;
}