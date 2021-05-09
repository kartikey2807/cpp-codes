#include <bits/stdc++.h>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <limits>
using namespace std;
typedef long long int lld;
#define MAXN 1000001
#define FastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
lld spf[MAXN];
void sieve (){
    spf[1]= 1;
    for(lld i=2; i<MAXN; i+=1)
        spf[i] = i;
    for(lld i=4; i<MAXN; i+=2)
        spf[i] = 2;
    for(lld i=3; i*i<MAXN;i++)
    {
        if (spf[i] == i)
        {
            for(lld j=i*i;j<MAXN;j+=i){
                if (spf[j]==j)
                    spf[j]= i;
            }
        }
    }
}
vector <lld>  getFactorization (lld x){
    vector<lld>ret; 
    while (x != 1){
        ret.push_back(spf[x]);
        x/= spf[x];
    }
    return ret;
}
double getComb (double n  ,  double x){
    if (x > n){
        return 0;
    }
    else{
        double r = 1.0;
        for(double i = 1.0;i<=x; i = i + 1){
            double a = n-i+1;
            double b = a / i;
            r*=b;
        }
        return r;
    }
}
lld f;
set <lld> DFS (set <lld> S[], lld x,char c){
    set <lld> visit;
    stack <lld> stk;
    map <lld,lld> m;
    lld y;
    lld z;
    lld w;
    visit.insert(x);
        stk.push(x);
        map <lld , lld> :: iterator  p;
        while (!stk.empty()){
            y = stk.top();
                stk.pop();
                set<lld>::iterator pos;
                for(pos = S[y].begin(); pos != S[y].end(); pos++){
                    z = *pos;
                    if (visit.count(z)){
                        if (m.count(y)){
                            p=m.find(y);
                            w=p->second;
                            if (z != w){
                                f  = 1;
                            }
                        }
                    }
                }
                for(pos = S[y].begin(); pos != S[y].end(); pos++){
                    z = *pos;
                    if (!visit.count(z)){
                        visit.insert(z);
                            stk.push(z);
                            m.insert(pair<lld,lld>(z, y));
                    }
                }
        }
    return visit;
}
int main () {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("inputf.in",  "r",  stdin);
    // for writing output to output.txt
    freopen("outputf.in", "w", stdout);
    #endif
    FastIO
    lld n , L;
    cin >>  n;
    L = (lld)ceil(log10(n));
    lld A [L];
    lld k , r;
    k = L - 1;
    while  (n != 0){
        if (n % 10 == 4){
            A[k] = 0;
        }
        if (n % 10 == 7){
            A[k] = 1;
        }
        k -= 1;
        n /=10;
    }
    lld i, s;
    s = 0;
    r = 0;
    for(i=L-1;i>=0;i-=1){
        lld a = pow(2,r);
        s += A[i]*a;
        r += 1;
    }
    for(i = 0; i<L;i+=1){
        lld a = pow(2,i);
        s += a;
    }
    cout << s << "\n";
    return 0;
}