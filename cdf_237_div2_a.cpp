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
    lld n, i;
    lld j, f;
    cin >> n;
    char dia;
    char oth;
    char dda[n][n];
    for(i = 0; i<n; i += 1){
        for(j = 0; j<n;j++){
            cin >>dda[i][j];
        }
    }
    dia = dda[0][0];
    oth = dda[0][1];
    f = 1;
    for(i = 0; i<n; i += 1){
        for(j = 0; j<n;j++){
            if (i == j || i+j == n-1){
                if (dda[i][j] != dia){
                    f = 0;
                }
            }
            else{
                if (dda[i][j] != oth){
                    f = 0;
                }
            }
        }
    }
    if (dia  ==  oth){
        f  = 0;
    }
    if (f == 1)
        cout << "YES";
    else
        cout <<  "NO";
    return 0;
}