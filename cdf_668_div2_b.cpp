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
      	set <lld> pos, neg;
      	for(lld i = 0; i < n; i += 1){
      		if (A[i] >= 0)
      			pos.insert(i);
      		else  neg.insert(i);
      	}
      	set <lld> :: iterator itr = pos.begin();
      	while(itr != pos.end()){
      		lld loc = (*itr);
      		neg.insert(loc);
      		set <lld> :: iterator it = neg.find(loc);
      		it++;
      		neg.erase(loc);
      		if (it == neg.end()){
      			break;
      		}
      		else{
      			vector <lld> v;
      			while(it != neg.end()){
      				lld diff1 = A[loc];
      				lld diff2 = 0-A[(*it)];
      				if (diff2 > diff1){
      					A[loc] -= diff1;
      					A[(*it)] += diff1;
      					if (A[(*it)] == 0)
      						v.pb((*it));
      				}
      				else{
      					A[(*it)] += diff2;
      					A[loc] -= diff2;
      					v.pb(*it);
      				}
      				if (A[loc] == 0)
      					break;
      				it++;
      			}
      			for(lld i = 0; i < v.size(); i += 1)
      				neg.erase(v[i]);
      		}
      		itr++;
      	}
      	lld sum = 0;
      	for(set <lld> :: iterator itr = neg.begin(); itr != neg.end(); itr++){
      		sum -= A[*itr];
      	}
      	cout << sum << "\n";
      }
      return 0;
}