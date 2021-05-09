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
lld edges;
lld nodes;
void DFS (set<lld>S[],lld x,bool visit[]){
    stack <lld> stk;
    lld y;
    set  <lld>  old;
    visit[x] = true;
        stk.push(x);
        while (!stk.empty()){
            y = stk.top();
            old.insert(y);
                stk.pop();
                nodes+= 1;
                set<lld>::iterator itr;
                for(itr = S[y].begin(); itr!=S[y].end(); itr++){
                    if (!old.count((*itr))){
                        edges += 1;
                    }
                }
                for(itr = S[y].begin(); itr!=S[y].end(); itr++){
                    if (visit[*itr]==false){
                        visit[*itr] = true;
                            stk.push(*itr);
                    }
                }
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
    lld n, m;
    cin >> n;
    cin >> m;
    lld x, y;
    lld i, f;
    set <lld> S[n+1];
    for(i = 0;i<m;i++){
        cin >> x;
        cin >> y;
        S[x].insert(y);
        S[y].insert(x);
    }
    bool visit[n+1];
    for(i = 0; i<=n; i += 1){
            visit[i] = false;
    }
    lld p;
    p = 1;
    f = 1;
    set<lld> :: iterator pos;
    while (p != n){
        if (!visit[p]){
            edges = 0;
            nodes = 0;
            DFS(S, p, visit);
            if (edges!=(nodes*(nodes-1))/2){
                f = 0;
                break;
            }
        }
                p+= 1;
    }
    if (f  == 0){
        cout <<"NO"<<"\n";
    }
    else{
        cout<<"YES"<<"\n";
    }
    return 0;
}