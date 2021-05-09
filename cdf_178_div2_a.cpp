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
    cin >> n;
    lld A[n];
    lld i, j;
    lld x, y;
    for(i = 0; i<n; i+=1){
        cin >>A[i];
    }
    cin >> m;
    for(i = 0; i<m; i+=1){
        cin >> x;
        cin >> y;
        if (x-1 != 0 && x-1!=n-1){
            A [x-2] +=(y - 1);
            A [x+0] +=(A[x-1] -y);
        }
        else{
            if (x-1 == 0){
                A [x+0] += (A[x-1] - y);
            }
            if (x-1==n-1){
                A [x-2]+=y-1;
            }
        }
        A[x-1] = 0;
    }
    for(i = 0; i<n; i+=1){
        cout<< A[i]<<"\n";
    }
    return 0;
}