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
      lld n, a, b;
      cin >> n >> a >> b;
      lld f = 0;
      pair <lld, lld>ans;
      for(lld x = 0; (x*a) <= n; x += 1){
      	if ((n-(x*a))%b == 0){
      		ans = {x, (n-(x*a))/b};
      		f = 1;
      		break;
      	}
      }
      if (f == 0)
      	{cout << "-1"; return 0;}
      vector <lld> v(n+1);
      for(lld i = 1; i <= ans.first; i += 1){
      	lld start = (i*a)-(a-1);
      	lld end = i*a;
      	v[end]= start;
      	while(start < end){
      		v[start]= start+1;
      		start++;
      	}
      }
      for(lld i = 1; i <= ans.second;i += 1){
      	lld end = (i*b)+(ans.first*a);
      	lld start = end-(b-1);
      	v[end]= start;
      	while(start < end){
      		v[start]= start+1;
      		start++;
      	}
      }
      for(lld i = 1; i <= n; i += 1)
      	cout << v[i] << " ";
      return 0;
}