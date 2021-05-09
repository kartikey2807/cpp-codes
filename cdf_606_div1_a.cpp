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
        string s;
        cin >> s;
        lld n, i;
        n = s.length();
        set <lld>C_set;
        for(i = 0; i < n-2; i+=1){
            if (s[i] == 'o' && s[i+1] == 'n' && s[i+2] == 'e'){
                C_set.insert(i+1);
            }
            if (s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o'){
                if (i < n-4){
                    if (s[i+2]=='o'&&s[i+3]=='n'&&s[i+4]=='e'){
                        C_set.insert(i+2);
                        i+=4;
                    }
                    else{
                        C_set.insert(i+1);
                    }
                }
                else{
                        C_set.insert(i+1);
                }
            }
        }
        cout << C_set.size() << "\n";
        set <lld>  ::  iterator  itr;
        for(itr = C_set.begin(); itr != C_set.end(); itr++){
            cout << *itr + 1 <<  " ";
        }
            cout << "\n";
        T-=1;
    }
    return 0;
}