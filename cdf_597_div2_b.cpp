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
    lld T, j;
    cin >> T;
    for(j = 0; j < T; j += 1){
        lld n, i;
        cin >> n;
        lld a, b;
        lld c, s;
        cin >> a;
        cin >> b;
        cin >> c;
        string t;
        cin >> t;
        string r;
        r  =  "";
        for(i = 0;i<n;i += 1){
            r+= 'N';
        }
        s = 0;
        for(i = 0;i<n;i += 1){
            if (t[i]  == 'S'){
                if (a > 0){
                    a-= 1;
                    s+= 1;
                    r[i]='R';
                }
            }
        }
        for(i = 0;i<n;i += 1){
            if (t[i]  == 'R'){
                if (b > 0){
                    b-= 1;
                    s+= 1;
                    r[i]='P';
                }
            }
        }
        for(i = 0;i<n;i += 1){
            if (t[i]  == 'P'){
                if (c > 0){
                    c-= 1;
                    s+= 1;
                    r[i]='S';
                }
            }
        }
        for(i = 0;i<n;i += 1){
            if (r[i]  == 'N'){
                if (a > 0){
                    a-= 1;
                    r[i]='R';
                }
                else{
                if (b > 0){
                    b-= 1;
                    r[i]='P';
                }
                else{
                    c-= 1;
                    r[i]='S';
                }
                }
            }
        }
        if (n % 2 == 0){
            if (s  >= (n/2)){
                cout <<"YES";
                cout << "\n";
                cout << r;
                cout << "\n";
            }
            else{
                cout << "NO";
                cout << "\n";
            }
        }
        else{
            if (s  >  (n/2)){
                cout <<"YES";
                cout << "\n";
                cout << r;
                cout << "\n";
            }
            else{
                cout << "NO";
                cout << "\n";
            }
        }
    }
    return 0;
}