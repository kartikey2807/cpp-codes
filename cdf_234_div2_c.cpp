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
      lld n, m, x, y, z, p;
      cin >> n >> m >> x >> y >> z >> p;
      pair <lld, lld> mac[p];
      for(lld i = 0; i < p; i += 1)
      	cin >> mac[i].first >> mac[i].second;
      x = x%4;
      while(x){
      	for(lld i = 0; i < p; i += 1){
      		pair <lld, lld> temp = mac[i];
      		mac[i].first = temp.second;
      		mac[i].second = n-temp.first+1;
      	}
      	swap(n,m);
      	x--;
      }
      y = y%2;
      while(y){
      	for(lld i = 0; i < p; i += 1){
      		mac[i].second = m-mac[i].second+1;
      	}
      	y--;
      }
      z = z%4;
      while(z){
      	for(lld i = 0; i < p; i += 1){
      		pair <lld, lld> temp = mac[i];
      		mac[i].second = temp.first;
      		mac[i].first = m-temp.second+1;
      	}
      	swap(n,m);
      	z--;
      }
      for(lld i = 0; i < p; i += 1)
      	cout << mac[i].first << " " << mac[i].second << "\n";
      return 0;
}