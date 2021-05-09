#include <bits/stdc++.h>
#include <queue>
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
    cin >> s;
    lld i, n;
    n = s.length();
    priority_queue < lld, vector<lld>, greater<lld> > pq;
    for(i = 0; i<n;i+=2){
        char c = s[i];
        pq.push(((lld)c) - 48);
    }
    while (true){
        cout << pq.top();
        pq.pop ();
        if (pq.empty ()){
            break;
        }
        cout<<"+";
    }
    cout  << "\n";
    return 0;
}