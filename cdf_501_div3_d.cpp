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
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, k, s;
      cin >> n >> k >> s;
     	if (k*(n-1) < s || s < k) {cout << "NO"; return 0;}
     	lld q = s/k;
     	lld r = s%k;
     	vector <lld> v(k);
     	for(lld i = 0; i < k; i += 1){
     		if (i%2 == 0)
     			v[i] = q+1;
     		else  v[i] = 1;
     	}
     	if (k%2 == 0){
     		s -= k*(v[0]-v[1]);
     		lld j = k-2;
     		while(s > 1){
     			if (v[j] < n){
     				v[j]++;
     				s -= 2;
     			}
     			else
     				j -= 2;
     		}
     		if (s == 1){
     			if (v[j] < n){
     				v[j]++;
     			}
     			else{
     				j -= 2;
     				v[j]++;
     			}
     			v[k-1]++;
     		}
     	}
     	else{
     		if (k == 1){
     			v[k-1] = s+1;
     		}
     		else{
     			s -= k*(v[0]-v[1]);
     			lld j = 0;
     			while(s > 1){
     				if (v[j] < n){
     					v[j]++;
     					s -= 2;
     				}
     				else
     					j += 2;
     			}
     			if (s == 1)
     				v[k-1]++;
     		}
     	}
     	cout << "YES\n";
     	for(lld i = 0; i < k; i += 1)
     		cout << v[i] << " ";
      return 0;
}