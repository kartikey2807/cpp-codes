#include <bits/stdc++.h>
#include <set>
#include <stack>
#include <vector>
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
    lld n, s;
    cin >> n;
    string t;
    s = 0;
    while (n!=0){
        cin >> t;
        if (t == "Cube")
            s += 6;
        if (t ==  "Octahedron" )
            s += 8;
        if (t == "Tetrahedron" )
            s += 4;
        if (t == "Icosahedron" )
            s += 20;
        if (t == "Dodecahedron")
            s += 12;
        n-=1;
    }
    cout <<s;
    return 0;
}