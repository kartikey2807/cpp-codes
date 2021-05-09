#include <bits/stdc++.h>
#include <set>
#include <limits>
#include <string>
using namespace std;
typedef long long int lld;
#define MAXN std::numeric_limits<lld>::max()
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
    lld A[n];
    lld c, d;
    for(i = 0; i < n; i += 1){
        cin >> A[i];
    }
    lld m, j;
    cin >> m;
    lld B[m];
    for(i = 0; i < m; i += 1){
        cin >> B[i];
    }
    sort(A , A + n);
    sort(B , B + m);
    i = 0;
    j = 0;
    c = 0;
    d = 0;
    while (i  <  n){
        if (B[j] < A[i]){
            if (A[i]-B[j]<=1){
                c++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        else{
            if (B[j]-A[i]<=1){
                c++;
                i++;
                j++;
            }
            else{
                i++;
            }
        }
    }
    cout << c<<"\n";
    return 0;
}