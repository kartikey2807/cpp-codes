// if you get a wrong answer but you are convinced
// that your logic is correct do :- 1) read the
// entire code and try to find if something needs
// to be added 2) start making test cases that you
// think can possibly give WA. Double cannot be used
// for comparisons use div and mod instead. 
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
#define PI 3.14159265358979323
#define foi(i,n) for(lld i = 0; i < n; i+=1)
#define fod(i,n) for(lld i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define auth set <lld> :: iterator
#define pb push_back
#define LEN 3000000
lld c;
set <lld> vis;
vector <lld>v[LEN];
vector <lld> order;
lld calc (lld a, lld b) {return (((a+b)*(a+b+1))/2)+b;}
void dfs (lld pos)
{
	vis.insert(pos);
	c++;
	order.pb(pos);
	for(lld i = 0; i < v[pos].size(); i += 1)
		if (!vis.count(v[pos][i]))
			dfs(v[pos][i]);
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, m;
      cin >> n >> m;
      char dda[n+1][m+1];
      for(lld i = 1; i <= n; i += 1){
      	for(lld j = 1; j <= m; j += 1){
      		cin >> dda[i][j];
      	}
      }
      for(lld i = 1; i <= n; i += 1){
      	for(lld j = 2; j <= m; j += 1){
      		if (dda[i][j] == '.' && dda[i][j-1] == '.'){
      			v[calc(i,j)].pb(calc(i,j-1));
      			v[calc(i,j-1)].pb(calc(i,j));
      		}
      	}
      }
      for(lld j = 1; j <= m; j += 1){
      	for(lld i = 2; i <= n; i += 1){
      		if (dda[i][j] == '.' && dda[i-1][j] == '.'){
      			v[calc(i,j)].pb(calc(i-1,j));
      			v[calc(i-1,j)].pb(calc(i,j));
      		}
      	}
      }
      lld x = 0;
      map <lld, lld> mac;
      map <lld, lld> val;
      for(lld i = 1; i <= n; i += 1){
      	for(lld j = 1; j <= m; j += 1){
      		if (dda[i][j] == '.' && !vis.count(calc(i,j))){
      			c = 0;
      			x++;
      			order.clear();
      			dfs(calc(i,j));
      			val[x] = c;
      			for(lld k = 0; k < order.size(); k += 1){
      				mac[order[k]] = x;
      			}
      		}
      	}
      }
      for(lld i = 1; i <= n; i += 1){
      	for(lld j = 1; j <= m; j += 1){
      		if (dda[i][j]  ==  '.'){
      			cout << dda[i][j];
      		}
      		else{
      			lld sum = 0;
      			set <lld> sis;
      			if (j >= 2 && dda[i][j-1] == '.'){
      				if (!sis.count(mac[calc(i,j-1)])){
      					sis.insert(mac[calc(i,j-1)]);
      					sum += val[mac[calc(i,j-1)]];
      				}
      			}
      			if (j <= m-1&&dda[i][j+1] == '.'){
      				if (!sis.count(mac[calc(i,j+1)])){
      					sis.insert(mac[calc(i,j+1)]);
      					sum += val[mac[calc(i,j+1)]];
      				}
      			}
      			if (i >= 2 && dda[i-1][j] == '.'){
      				if (!sis.count(mac[calc(i-1,j)])){
      					sis.insert(mac[calc(i-1,j)]);
      					sum += val[mac[calc(i-1,j)]];
      				}
      			}
      			if (i <= n-1&&dda[i+1][j] == '.'){
      				if (!sis.count(mac[calc(i+1,j)])){
      					sis.insert(mac[calc(i+1,j)]);
      					sum += val[mac[calc(i+1,j)]];
      				}
      			}
      			sum += 1;
      			sum %=10;
      			cout << sum;
      		}
      	}
      	cout << "\n";
      }
      return 0;
}