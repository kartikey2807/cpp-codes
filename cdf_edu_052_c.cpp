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
void no () {cout << "NO\n";}
void yes() {cout << "YES\n";}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, k;
      cin >> n >> k;
      lld A[n], h_lim = MIN;
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      	h_lim = max(h_lim,A[i]);
      }
      vector <lld> v (h_lim+2);
      for(lld i = 0; i < n; i += 1){
      	v[1]++;
      	v[A[i]+1]--;
      }
      for(lld i = 2; i < v.size(); i += 1){
      	v[i] += v[i-1];
      }
      lld p = -1;
      for(lld i = 1; i < v.size(); i += 1){
      	if (v[i] > 0 && v[i] < n){
      		p = i;
      		break;
      	}
      }
      if (p == -1) {cout << "0"; return 0;}

      lld cnt = 0;
      for(lld i = p; i < v.size(); i += 1){
      	lld len = 0;
      	while(i < v.size()){
      		len += v[i];
      		if (len > k)
      			break;
      		i++;
      	}
      	i--; cnt++;
      }
      cout << cnt;
      return 0;
}