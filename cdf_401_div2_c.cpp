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
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, m;
      cin >> n >> m;
      lld dda[n][m];
      for(lld i = 0; i < n; i += 1){
      	for(lld j = 0; j < m; j += 1){
      		cin >> dda[i][j];
      	}
      }
      set <lld> vis[n];
      for(lld j = 0; j < m; j += 1){
      	lld start = 0;
      	for(lld i = 1; i < n; i += 1){
      		vis[i-1].insert(start);
      		if (dda[i][j] < dda[i-1][j]){
      			start = i;
      		}
      	}
      	vis[n-1].insert(start);
      }
      lld q;
      cin >> q;
      for(lld i = 0; i < q; i += 1){
      	lld l, r;
      	cin >> l >> r;
      	l--; r--;
      	if (vis[r].count(l)){
      		cout<<"Yes\n";
      	}
      	else{
      		vis[r].insert(l);
      		auth itr = vis[r].find(l);
      		if (itr == vis[r].begin()){
      			vis[r].erase(l);
      			cout <<  "No\n";
      		}
      		else{
      			vis[r].erase(l);
      			cout << "Yes\n";
      		}
      	}
      }
      return 0;
}