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
set <lld> order;
void fact(lld a)
{
	while(a%2 == 0)
		{a/=2; order.insert(2);}
	for(lld i = 3; i <= sqrt(a); i += 2){
		while(a%i == 0)
			{a/=i; order.insert(i);}
	}
	if (a > 2)
		order.insert(a);
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, a, b;
      cin >> n >> a >> b;
      fact(a);
      fact(b);
      pair <lld , lld> p[n];
      p[0] = make_pair(a,b);
      for(lld i = 1; i < n; i += 1){
      	cin >> p[i].first >> p[i].second;
      }
      for(auth itr = order.begin(); itr != order.end(); itr++){
      	lld temp = *itr;
      	lld f = 1;
      	for(lld i = 0; i < n; i += 1){
      		if (p[i].first%temp != 0 && p[i].second%temp != 0){
      			f = 0;
      			break;
      		}
      	}
      	if (f == 1)
      		{cout << temp; return 0;}
      }
      cout << "-1";
      return 0;
}