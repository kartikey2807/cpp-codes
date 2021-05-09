// if you get a wrong answer but you are convinced
// that your logic is correct do :- 1) read the
// entire code and try to find if something needs
// to be added 2) start making test cases that you
// think can possibly give WA. Double cannot be used
// for comparisons use div and mod instead. do not use
// complex data structures if double matrix can be used..
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
      lld n;
      cin >> n;
      lld C[n],P[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> C[i] >> P[i];
      }
      lld k;
      cin >> k;
      lld A[k],B[k];
      for(lld i = 0; i < k; i += 1){
      	cin >> A[i];
      	B[i] = i+1;
      }
      psort(A,B,k);
      set<lld>vis;
      lld sum = 0;
      vector <pair <lld, lld> > mac;
      for(lld i = 0; i < k; i += 1){
      	lld pos =  -1;
      	lld ans = MIN;
      	for(lld j = 0; j < n; j += 1){
      		if (vis.count(j)){
      			continue;
      		}
      		if (C[j] <= A[i]){
      			if (P[j] > ans){
      				ans=P[j];
      				pos =  j;
      			}
      		}
      	}
      	if (pos != -1){
      		sum+=ans;
      		vis.insert(pos);
      		mac.pb(make_pair(pos+1,B[i]));
      	}
      }
      cout << mac.size() << " " << sum <<  "\n";
      for(lld i = 0; i < mac.size(); i += 1)
      	cout << mac[i].first << " " << mac[i].second << "\n";
      return 0;
}