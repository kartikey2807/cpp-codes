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
    cin >> n;
    if (n == 0){
        cout << "1\n";
    }
    else{
        switch (n%4){
            case 2: cout << "4\n"; 
                    break;
            case 3: cout << "2\n"; 
                    break;
            case 0: cout << "6\n"; 
                    break;
            case 1: cout << "8\n"; 
                    break;
        }
    }
    return 0;
}