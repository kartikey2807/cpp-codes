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
#define MAX std::numeric_limits<lld> ::max()
#define MIN std::numeric_limits<lld> ::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define auth set <lld> :: iterator
#define pb push_back
lld cmp (pair <lld, lld> a, pair <lld, lld> b)
{
	if ((a.first*b.second) < (b.first*a.second))
		return 1;
	return 0;
}
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
      	sort(A,A+n);
      	vector <lld> v;
      	for(lld i = 1; i < n; i += 1){
      		if (A[i] == A[i-1]){
      			v.pb(A[i]);
      			i += 1;
      		}
      	}
      	lld pos;
      	lld ans = MAX;
      	pair <lld, lld> frac;
      	for(lld i = v.size()-1; i > 0; i -= 1){
      		lld a =(lld)4*pow(v[i]+v[i-1],2);
      		lld x = a/(v[i]*v[i-1]);
      		lld r = a%(v[i]*v[i-1]);
      		if (x <= ans){
      			if (x < ans){
      				ans = x; 
      				pos = i;
      				frac = {r,v[i]*v[i-1]};
      			}
      			else{
      				pair <lld, lld> p;
      				p={r,v[i]*v[i-1]};
      				if (cmp(p, frac) == 1){
      					pos  = i;
      					frac = p;
      				}
      			}
      		}
      	}
      	cout << v[pos] << " " << v[pos] << " " << v[pos-1] << " " << v[pos-1] << "\n";
      }
      return 0;
}