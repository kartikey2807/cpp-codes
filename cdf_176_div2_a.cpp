#include <bits/stdc++.h>
#include <set>
#include <stack>
#include <vector>
using namespace std;
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
    char d[4][4];
    lld C_h, C_d;
    for(lld i = 0;  i < 4; i += 1){
        for(lld j = 0;j<4; j += 1){
            cin >>d[i][j];
        }
    }
    lld f = 0;
    for(lld i = 0;  i < 3; i += 1){
        for(lld j = 0;j<3; j += 1){
            C_h = 0;
            C_d = 0;
            if (d[i+0][j+0] =='#'){
                C_h+=1;
            }
            else
                C_d+=1;
            if (d[i+0][j+1] =='#'){
                C_h+=1;
            }
            else
                C_d+=1;
            if (d[i+1][j+0] =='#'){
                C_h+=1;
            }
            else
                C_d+=1;
            if (d[i+1][j+1] =='#'){
                C_h+=1;
            }
            else
                C_d+=1;
            if ((C_h == 3 && C_d == 1) || (C_h == 1 && C_d == 3) || (C_h == 4 && C_d == 0) || (C_h == 0 && C_d == 4))
                f  = 1;
        }
    }
    if (f == 1)
        cout <<"YES\n";
    else
        cout << "NO\n";
    return 0;
}