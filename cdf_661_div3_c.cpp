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
      	string s;
      	cin >> n >> s;
      	lld A[n];
      	set <lld> zero, one;
      	for(lld i = 0; i < n; i += 1){
      		A[i] = (lld)s[i]-48;
      	}
      	for(lld i = 0; i < n; i += 1){
      		if (A[i] == 0) zero.insert(i);
      		else one.insert(i);
      	}
      	lld B[n];
      	lld cnt = 1;
      	for(lld i = 0; i < n; i += 1){
      		if ((A[i] == 0 && !zero.count(i)) || (A[i] == 1 && !one.count(i)))
      			continue;
      		lld x = i;
      		B[x] = cnt;
      		while(true){
      			if (A[x] == 0){
      				zero.erase(x);
      				one.insert(x);
      				set <lld> :: iterator itr = one.find(x);
      				itr++;
      				lld temp;
      				if (itr == one.end()){one.erase(x);break;}
      				else{one.erase(x);temp = *itr;}
      				x = temp;
      			}
      			else{
      				one.erase(x);
      				zero.insert(x);
      				set <lld> :: iterator itr = zero.find(x);
      				itr++;
      				lld temp;
      				if (itr == zero.end()){zero.erase(x);break;}
      				else{zero.erase(x);temp = *itr;}
      				x = temp;
      			}
      			B[x] = cnt;
      		}
      		cnt++;
      	}
      	cout << cnt-1 << "\n";
      	for(lld i = 0; i < n; i += 1){
      		cout << B[i] << " ";
      	}
      	cout << "\n";
      }
      return 0;
}