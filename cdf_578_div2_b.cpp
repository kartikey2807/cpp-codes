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
    lld T;
    cin >> T;
    while (T!=0){
        lld n, m;
        lld k, i;
        cin >> n;
        cin >> m;
        cin >> k;
        lld H[n];
        for(i = 0; i < n; i+=1){
            cin >> H[i];
        }
        lld f = 1;
        for(i = 1; i < n; i+=1){
            if (H[i-1] >= H[i]){
                m+=H[i-1]-H[i];
                H[i-1]  = H[i];
                if (H[i-1] > k){
                    m +=k;
                    H[i-1]-= k;
                }
                else{
                    m +=H[i-1];
                    H[i-1] = 0;
                }
            }
            else{
                if (H[i]-H[i-1] < k){
                    if (k-(H[i]-H[i-1])<H[i-1]){
                        m +=  k - (H[i]-H[i-1]);
                        H[i-1]-=k-(H[i]-H[i-1]);
                    }
                    else{
                        m += H[i-1];
                        H[i-1]  = 0;
                    }
                }
                else{
                    if ((H[i]-H[i-1]) - k > m){
                        f = 0;
                        break;
                    }
                    else{
                        m-=(H[i] - H[i-1]) - k;
                    }
                }
            }
        }
            if (f == 0)
                cout <<  "NO\n";
            else
                cout << "YES\n";
        T-=1;
    }
    return 0;
}