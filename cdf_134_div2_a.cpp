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
        for(double i = 1.0; i<=x; i+=1){
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
    lld m, i;
    m =2*n+1;
    lld A[m];
    for(i = 0; i<m; i+=1){
        cin >>A[i];
    }
    for(i = 1; i<m; i+=2){
        if (k == 0)
            break ;
        if ((A[i]-1) > A[i-1] && (A[i]-1) > A[i+1]){
            k -= 1;
            A[i]--;
        }
    }
    for(i = 0; i<m; i+=1){
        cout<<A[i] << " ";
    }
    return 0;
}