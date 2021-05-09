// if you get a wrong answer but you are convinced
// that your logic is correct do :- 1) read the
// entire code and try to find if something needs
// to be added 2) start making test cases that you
// think can possibly give WA.
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
#define pb push_back
vector <pair <lld, lld> > order;
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      cin >> n;
      char dda[n][n];
      for(lld i = 0; i < n; i += 1){
      	for(lld j = 0; j < n; j += 1){
      		cin >> dda[i][j];
      	}
      }
      lld x = 0, y = 0;
      for(lld i = 0; i < n; i += 1){
      	lld cnt = 0;
      	for(lld j = 0; j < n; j += 1){
      		if (dda[i][j] == 'E')
      			cnt++;
      	}
      	if (cnt == n)
      		x = 1;
      }
      for(lld j = 0; j < n; j += 1){
      	lld cnt = 0;
      	for(lld i = 0; i < n; i += 1){
      		if (dda[i][j] == 'E')
      			cnt++;
      	}
      	if (cnt == n)
      		y = 1;
      }
      if (x == 1 && y == 1){
      	cout << "-1";
      }
      else{
      	for(lld i = 0; i < n; i += 1){
      		for(lld j = 0; j < n; j += 1){
      			if (dda[i][j] == '.')
      				order.pb({i,j});
      		}
      	}
      	lld cnt_row[n];
      	memset(cnt_row, 0, sizeof(cnt_row));
      	for(lld i = 0; i < order.size(); i += 1){
      		cnt_row[order[i].first]++;
      	}
      	lld f = 1;
      	for(lld i = 0; i < n; i += 1){
      		if (cnt_row[i] == 0)
      			f = 0;
      	}
      	if (f == 1){
      		for(lld i = 0; i < n; i += 1){
      			for(lld j = 0; j < order.size(); j += 1){
      				if (order[j].first == i){
      					cout << order[j].first+1 << " " << order[j].second+1 << "\n";
      					break;
      				}
      			}
      		}
      	}
      	else{
      		for(lld i = 0; i < n; i += 1){
      			for(lld j = 0; j < order.size(); j += 1){
      				if (order[j].second == i){
      					cout << order[j].first+1 << " " << order[j].second+1 << "\n";
      					break;
      				}
      			}
      		}
      	}
      }
      return 0;
}