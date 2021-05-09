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
#define auth set <lld> :: iterator
#define pb push_back
vector <pair <lld, lld> > order;
void make (pair <lld, lld> B[]){
	map <lld, lld> cnt;
	for(lld i = 0; i < 4; i += 1){
		if (!cnt.count(B[i].first)){
			cnt[B[i].first] = B[i].second;
		}
		else{
			cnt[B[i].first] = min(cnt[B[i].first], B[i].second);
		}
	}
	map <lld, lld> :: iterator itr = cnt.begin();
	lld j = itr->first;
	lld b = itr->second;
	itr++;
	lld a = itr->second;
	lld diff = b-a;
	for(lld i = b; i >= a; i -= 1){
		lld x = j;
		lld y = i;
		lld cnt = 0;
		while(cnt <= diff){
			order.pb(make_pair(x,y));
			cnt += 1;
			x++; y++;
		}
		j += 1;
	}
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      pair <lld, lld> A[4];
      pair <lld, lld> B[4];
      for(lld i = 0; i < 4; i += 1)
      	cin >> A[i].first >> A[i].second;
      for(lld i = 0; i < 4; i += 1)
      	cin >> B[i].first >> B[i].second;
     	set <pair <lld, lld> > vis;
     	lld x1, x2, y1, y2;
     	if (A[1].first == A[0].first){
     		y1 = A[1].second;
     		y2 = A[0].second;
     	}
     	else{
     		x1 = A[1].first;
     		x2 = A[0].first;
     	}
     	if (A[2].first == A[1].first){
     		y1 = A[2].second;
     		y2 = A[1].second;
     	}
     	else{
     		x1 = A[2].first;
     		x2 = A[1].first;
     	}
     	for(lld i = min(x1,x2); i <= max(x1,x2); i += 1){
     		for(lld j = min(y1,y2); j <= max(y1,y2); j += 1){
     			vis.insert(make_pair(i,j));
     		}
     	}
     	make(B);
     	lld f = 0;
     	for(lld i = 0; i < order.size(); i += 1){
     		if (vis.count(order[i]))
     			f = 1;
     	}
     	if (f == 1) cout << "YES\n";
     	else cout << "NO\n";
      return 0;
}