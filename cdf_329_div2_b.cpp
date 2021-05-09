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
void psort (lld A[], lld B[], lld n)
{
	pair <lld, lld> P[n];
	for(lld i = 0; i < n; i += 1){
		P[i].first  = A[i];
		P[i].second = B[i];
	}
	sort(P,P+n);
	for(lld i = 0; i < n; i += 1){
		A[i] = P[i].first;
		B[i] = P[i].second;
	}
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, x1, x2, a, b;
      cin >> n >> x1 >>x2;
      lld y1[n],y2[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> a >> b;
      	y1[i] = (a*x1)+b;
      	y2[i] = (a*x2)+b;
      }
      psort(y2,y1,n);
      psort(y1,y2,n);
      set <lld>  vis;
      map <lld, lld> mac;
      lld f = 0;
      for(lld i = 0; i < n; i += 1){
      	mac[y2[i]]++;
      	if (mac[y2[i]] == 1)
      		vis.insert(y2[i]);
      }
      for(lld i = 1; i < n; i += 1){
      	if (y1[i] == y1[i-1]){
      		mac[y2[i-1]]--;
      		if (mac[y2[i-1]] == 0)
      			vis.erase(y2[i-1]);
      	}
      	else{
      		mac[y2[i-1]]--;
      		if (mac[y2[i-1]] == 0)
      			vis.erase(y2[i-1]);
      		auth itr = vis.begin();
      		if ((*itr)  < y2[i-1])
      			f = 1;
      	}
      }
      if (f == 1) cout << "YES";
      else cout << "NO";
      return 0;
}