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
      lld t, l;
      cin >> t;
      foi(l,t){
      	lld n;
      	cin >> n;
      	lld A[n];
      	for(lld i = 0; i < n; i += 1){
      		cin >> A[i];
      	}
      	vector <pair <lld, lld> > v;
      	for(lld i = 0; i < n; i += 1){
      		if (A[i] == 1){
      			lld j;
      			for(j = i; j < n; j += 1){
      				if (A[j] == 0)
      					break;
      			}
      			v.pb(make_pair(i,j-1));
      			i = j-1;
      		}
      	}
      	lld ans = MAX;
      	for(lld i = 0; i < v.size(); i += 1){
      		lld sum = 0;
      		for(lld j = i-1; j >= 0; j -= 1){
      			sum += v[j+1].first-v[j].second-1;
      		}
      		for(lld j = i+1; j < v.size(); j += 1){
      			sum += v[j].first-v[j-1].second-1;
      		}
      		ans = min(ans,sum);
      	}
      	cout << ans << "\n";
      }
      return 0;
}