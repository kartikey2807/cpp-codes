#include <bits/stdc++.h>
#include <set>
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
    lld n, i;
    cin >> n;
    lld r, m;
    set <lld> S[4];
    for(i = 0; i<n; i+=1){
        cin >> r;
        S[r].insert(i);
    }
        m =S[1].size();
    for(i = 1; i<4; i+=1){
        if(S[i].size()<m){
            m=S[i].size();
        }
    }
    set<lld>::iterator it1;
    set<lld>::iterator it2;
    set<lld>::iterator it3;
    it1 = S[1].begin();
    it2 = S[2].begin();
    it3 = S[3].begin();
    cout << m <<  "\n";
    for(i = 0; i<m; i+=1){
        cout << (*it1)+1 << " " << (*it2)+1 << " " << (*it3)+1 << "\n";
        it1++;
        it2++;
        it3++; 
    }
    return 0;
}