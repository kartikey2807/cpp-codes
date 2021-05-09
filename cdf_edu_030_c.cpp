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
      lld n, m, k;
      cin >> n >> m >> k;
      lld dda[n][m];
      for(lld i = 0; i < n; i += 1){
      	for(lld j = 0; j < m; j += 1){
      		cin >> dda[i][j];
      	}
      }
      vector <pair<lld,lld> > v (m);
      for(lld j = 0; j < m; j += 1){
      	lld f = 0;
      	for(lld i = 0; i < n; i += 1){
      		if (dda[i][j])
      			f = 1;
      	}
      	if (f == 1){
      		lld ans = 0;
      		lld pos;
      		for(lld i = 0; i < n; i += 1){
      			if (dda[i][j]){
      				lld cnt = 0;
      				for(lld start = i; start < min(i+k,n); start++){
      					cnt += dda[start][j];
      				}
      				if (cnt > ans){
      					ans=cnt;
      					pos=i;
      				}
      			}
      		}
      		v[j] = make_pair(ans,pos);
      	}
      	else{
      		v[j] = make_pair(-1,-1);
      	}
      }
      lld sum = 0;
      lld change = 0;
      for(lld j = 0; j < m; j += 1){
      	if (v[j].first == -1)
      		continue;
      	for(lld i = 0; i < v[j].second; i += 1){
      		if (dda[i][j])
      			change++;
      	}
      	sum += v[j].first;
      }
      cout << sum << " " << change;
      return 0;
}