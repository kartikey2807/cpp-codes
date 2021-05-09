#include <bits/stdc++.h>
#include <set>
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
    string s;
    lld i, n;
    std::getline(std::cin, s);
    n = s.length();
    set<char> Cset;
    for(i = 0; i<n;  i += 1 ){
        if (s[i] >= 'a' && s[i] <='z'){
            Cset.insert(s[i]);
        }
    }
    cout <<Cset.size()<< "\n";
    return 0;
}