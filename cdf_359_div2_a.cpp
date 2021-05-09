#include <bits/stdc++.h>
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
    lld n, x;
    cin >> n;
    cin >> x;
    lld i, j;
    lld t = 0;
    for(i = 0;i<n;i+=1){
        char c;
        lld  d;
        cin >> c;
        cin >> d;
        if (c == '+'){
            x += d;
        }
        else{
            if (x >= d){
                x -= d;
            }
            else{
                t += 1;
            }
        }
    }
    cout << x << " " << t << "\n";
    return 0;
}