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
    lld T;
    cin >> T;
    while (T  != 0){
        string s;
        cin >> s;
        string t;
        if (s.length() > 10){
            lld n = s.length() - 2;
            t  =  "";
            lld r;
            lld x;
            x = n;
            while (n != 0){
                r = n % 10;
                n = n / 10;
                t+= (char)(r + 48);
            }
            reverse(t.begin(),t.end());
            cout <<s[0]+t+s[x+1]<<"\n";
        }
        else{
            cout <<s<<"\n";
        }
        T-=1;
    }
    return 0;
}