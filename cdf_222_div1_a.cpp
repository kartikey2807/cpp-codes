// 背が高く、誇りを持ってください。どんなに弱くても価値がないと感じても、心を燃やし続け、
// 歯を食いしばって前進します。ボールに丸まって隠れれば、時は過ぎ去ります。あなたが悲し
// みに浸っている間、それはあなたのために止まりません。世界が平和になるためには、すべて
// の悪魔を破壊しなければなりません。柱としての義務を果たしてください。そうすれば、来世
// でもきっとあなたは偉大になるでしょう。 -炎の柱、両十郎連国。
#include <bits/stdc++.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
typedef double  dbl;
typedef long long int lld;
#define PI 3.14159265358979323
#define foi(i,n) for(lld i = 0; i < n; i+=1)
#define fod(i,n) for(lld i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
map <pair <lld, lld>, vector <pair <lld, lld>>> v;
vector <pair <lld, lld>> ans;
set <pair <lld, lld>> vis;
void bfs (pair <lld, lld> pos)
{
	queue <pair <lld, lld>> q;
	vis.insert(pos);
	q.push(pos);
	while(!q.empty()){
		pair <lld, lld> x = q.front();
		q.pop();
		ans.pb(x);
		for(lld i = 0; i < v[x].size(); i += 1){
			if (!vis.count(v[x][i])){
				vis.insert(v[x][i]);
				q.push(v[x][i]);
			}
		}
	}
}
int main ()
{
    #ifndef ONLINE_JUDGE
    freopen("inputf.in",  "r",  stdin);
    freopen("outputf.in", "w", stdout);
    #endif
    FastIO
    lld n, m, k;
    cin >> n >> m >> k;
    char dda[n][m];
    for(lld i = 0; i < n; i += 1){
    	for(lld j = 0; j < m; j += 1){
    		cin >> dda[i][j];
    	}
    }
    for(lld i = 0; i < n; i += 1){
    	for(lld j = 1; j < m; j += 1){
    		if (dda[i][j] == '.' && dda[i][j-1] == '.'){
    			v[{i,j}].pb({i,j-1});
    			v[{i,j-1}].pb({i,j});
    		}
    	}
    }
    for(lld j = 0; j < m; j += 1){
    	for(lld i = 1; i < n; i += 1){
    		if (dda[i][j] == '.' && dda[i-1][j] == '.'){
    			v[{i,j}].pb({i-1,j});
    			v[{i-1,j}].pb({i,j});
    		}
    	}
    }
    for(lld i = 0; i < n; i += 1){
    	for(lld j = 0; j < m; j += 1){
    		if (dda[i][j] == '.' &&  !vis.count({i,j})){
    			bfs({i,j});
    		}
    	}
    }
    reverse(ans.begin(),ans.end());
    for(lld i = 0; i < ans.size(); i += 1){
    	if (k == 0)
    		break;
    	dda[ans[i].first][ans[i].second] = 'X';
    	k--;
    }
    for(lld i = 0; i < n; i += 1){
    	for(lld j = 0; j < m; j += 1){
    		cout << dda[i][j];
    	}
    	cout << "\n";
    }
    return 0;
}