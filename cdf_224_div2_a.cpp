#include <bits/stdc++.h>
#include <set>
#include <stack>
#include <vector>
using namespace std;
typedef char chr;
typedef double  dbl;
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
    string x;
    cin >> x;
    lld i, n;
    lld j, m;
    lld a, b;
    chr temp;
    queue <chr>  A;
    queue <chr>  B;
    queue <chr>  C;
    n = s.length();
    m = x.length();
    for(i = 0; i<n; i++){
        if (s[i] != '|'){
            A.push(s[i]);
        }
        else{
            j=i+1;
            break;
        }
    }
    for(i = j; i<n; i++){
            B.push(s[i]);
    }
    for(i = 0; i<m; i++){
            C.push(x[i]);
    }
    a  = A.size();
    b  = B.size();
    if (a>b){
        while (a>b && !C.empty()){
            temp = C.front();
                B.push(temp);
                    C.pop ();
                        b+=1;
        }
    }
    else{
        while (b>a && !C.empty()){
            temp = C.front();
                A.push(temp);
                    C.pop ();
                        a+=1;
        }
    }
    if (C.size()%2==0 &&a==b){
        lld sz = C.size()/ 2;
        lld lz = C.size()/ 1;
        while (lz>sz){
            temp = C.front();
                A.push(temp);
                    C.pop ();
                        lz--;
        }
        while (lz> 0){
            temp = C.front();
                B.push(temp);
                    C.pop ();
                        lz--;
        }
        while (!A.empty()==1){
            cout << A.front();
            A.pop();
        }
        cout << "|";
        while (!B.empty()==1){
            cout << B.front();
            B.pop();
        }
    }
    else
        cout<<"Impossible\n";
    return 0;
}