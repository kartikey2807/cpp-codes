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
    dbl d, h;
    dbl v, e;
    cin >> d;
    cin >> h;
    cin >> v;
    cin >> e;
    if ((PI) * (d/2) * (d/2) * e  < v){
        cout << "YES\n";
        cout <<fixed<<setprecision(12) << ((PI)*(d/2)*(d/2)*h)/(v-((PI)*(d/2)*(d/2)*e));
    }
    else
        cout <<  "NO\n";
    return 0;
}