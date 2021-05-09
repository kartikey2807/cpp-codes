#include <bits/stdc++.h>
#include <set>
#include <stack>
#include <vector>
using namespace std;
typedef double  dbl;
typedef long long int lld;
#define PI 3.141592653589793238
#define FastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
double getComb (double n, double x){
    if (x > n){
        return 0;
    }
    else{
        double r = 1.0;
        for(double i = 1.0; i<=x;i+=1){
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
    lld i, c;
    lld j, f;
    lld A[n];
    for(i = 0;i < n; i++){
        cin >> A[i];
    }
    c = 0;
    set<lld>::iterator ps;
    for(i = 0; i < n;i++){
        lld D[10];
        f = 1;
        for(j=0;j<10;j++){
            D[j] = 0;
        }
        while (A[i] != 0){
            lld r=A[i]%10;
            D[r]+=  1;
            A[i]/= 10;
        }
        for(j=0;j<=k;j++){
            if (D[j]== 0){
                f = 0;
                break;
            }
        }
            if (f==1){
                c+=1 ;
            }
    }
    cout << c << "\n";
    return 0;
}