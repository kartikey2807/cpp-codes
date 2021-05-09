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
    lld x, r;
    cin >> x;
    stack <lld> stk;
    while (x >= 10){
        r = x % 10;
        stk.push(r <= (9-r) ? r:(9-r));
        x = x / 10;
    }
    if (x==9)
        stk.push(9);
    else
        stk.push(x <= (9-x) ? x:(9-x));
    while (!stk.empty()){
        cout<<stk.top();
              stk.pop();
    }
    return 0;
}