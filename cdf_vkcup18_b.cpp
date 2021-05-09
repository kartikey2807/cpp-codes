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
void poo ()
{
	cout << "-1";
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, d, h;
      cin >> n >> d >> h;
      vector <pair <lld, lld> > mac;
      if (n == 2){
      	cout << "1 2";
      	return 0;
      }
      else{
      	if (d == 1 && h == 1){
      		poo();
      		return 0;
      	}
      }
      if (d%2){
      	if (h <=d/2){
      		poo();
      		return 0;
      	}
      	else{
      		lld c = 0;
      		lld j = 2;
      		vector <lld> vis(n+1);
      		vis[1]= 1;
      		for(lld i = 2; i <= n; i += 1){
      			if (c == h)
      				break;
      			mac.pb(make_pair(i-1,i));
      			vis[i] = 1;
      			c++;
      			j++;
      		}
      		lld r = d-h;
      		if (r){
      			mac.pb(make_pair(1,j+0));
      			vis[j] = 1;
      			j++;
      			r--;
      			while(r){
      				mac.pb(make_pair(j-1,j));
      				vis[j] = 1;
      				j++;
      				r--;
      			}
      			for(lld i = 1; i <= n; i += 1){
      				if (vis[i] == 0)
      					mac.pb(make_pair(1,i));
      			}
      		}
      		else{
      			lld x = j-2;
      			for(lld i = 1; i <= n; i += 1){
      				if (vis[i] == 0)
      					mac.pb(make_pair(x,i));
      			}
      		}
      	}
      }
      else{
      	if (h < d/2){
      		poo();
      		return 0;
      	}
      	else{
      		lld c = 0;
      		lld j = 2;
      		vector <lld> vis(n+1);
      		vis[1]= 1;
      		for(lld i = 2; i <= n; i += 1){
      			if (c == h)
      				break;
      			mac.pb(make_pair(i-1,i));
      			vis[i] = 1;
      			c++;
      			j++;
      		}
      		lld r = d-h;
      		if (r){
      			mac.pb(make_pair(1,j+0));
      			vis[j] = 1;
      			j++;
      			r--;
      			while(r){
      				mac.pb(make_pair(j-1,j));
      				vis[j] = 1;
      				j++;
      				r--;
      			}
      			for(lld i = 1; i <= n; i += 1){
      				if (vis[i] == 0)
      					mac.pb(make_pair(1,i));
      			}
      		}
      		else{
      			lld x = j-2;
      			for(lld i = 1; i <= n; i += 1){
      				if (vis[i] == 0)
      					mac.pb(make_pair(x,i));
      			}
      		}
      	}
      }
      for(lld i = 0; i < mac.size(); i += 1)
      	cout << mac[i].first << " " << mac[i].second << "\n";
      return 0;
}