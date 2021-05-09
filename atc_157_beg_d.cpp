#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
using namespace std;
typedef double  dbl;
typedef long long int lld;
#define foi(i,n) for(i = 0; i < n; i+=1)
#define fod(i,n) for(i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define L 100005
lld Map[L];
lld Sap[L];
lld Dap[L];
lld Kap[L];
lld dfs (vector <lld> V[] ,  lld x ,  lld count){
	set <lld> visit;
	stack <lld> stk;
	lld y, j, c = 0;
	visit.insert(x);
		stk.push(x);
		while (!stk.empty()) {
			y = stk.top();
				stk.pop();
				c++;
				Dap[y]= count;
				for(j = 0; j < V[y].size(); j++){
					if (!visit.count(V[y][j])){
						visit.insert(V[y][j]);
							stk.push(V[y][j]);
					}
				}
		}
		set<lld>::iterator p;
		for(p = visit.begin();p!=visit.end();){
			Map[*p] = c;
			p ++;
		}
	return visit.size();
}
int main (){
    #ifndef ONLINE_JUDGE
    freopen("inputf.in",  "r",   stdin);
    freopen("outputf.in", "w",  stdout);
    #endif
    FastIO
    lld n, m;
    lld k, i;
    lld x, y;
    cin >> n;
    cin >> m;
    cin >> k;
    set <lld> st[n+1];
    vector<lld>V[n+1];
    foi(i,L){
    		Map[i]= 0;
    		Sap[i]= 0;
    		Dap[i]= 0;
    		Kap[i]= 0;
    }
    foi(i,m){
    	cin >> x >> y;
    V[x].push_back(y);
    V[y].push_back(x);
    Sap[x]++;
    Sap[y]++;
    }
    lld count = 1;
    for(i = 1; i<=n; i++){
    	if (Dap[i] ==  0){
    		lld l= dfs(V,i,count);
    	}
    	count+= 1;
    }
    foi(i,k){
    	cin >> x >> y;
    		if (Dap[x] == Dap[y]){
    			Kap[x] ++;
    			Kap[y] ++;
    		}
    }
    lld r;
    for(i = 1; i<=n; i++){
    	r = Sap[i]+Kap[i];
    	r+= 1;
    	cout << (Map[i]-r) << " ";
    }
    return 0;
}