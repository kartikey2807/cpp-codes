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
#define VAL 1000000000
#define PRIME 199999
map <pair <lld,lld>, lld> edge;
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, m;
      cin >> n >> m;
      edge[make_pair(1,n)] = 2;
      lld sum = 2;
      for(lld i = n-1; i > 2; i -= 1){
      	edge[make_pair(1,i)] = 1;
      	sum++;
      }
      if (n > 2)
      	edge[make_pair(1,2)] = PRIME-sum;
      m -= n-1;
      lld i= 2;
      while(m){
      	for(lld j = i+1; j <= n; j += 1){
      		if (m == 0)
      			break;
      		edge[make_pair(i,j)] = VAL;
      		m--;
      	}
      	i++;
      }
      if (n > 2)
      	cout << "2 " << PRIME << "\n";
      else  cout << "2 2\n";
      for(map <pair <lld, lld>, lld> :: iterator itr = edge.begin(); itr != edge.end(); itr++)
      	cout << (itr->first).first <<" "<< (itr->first).second <<" "<< itr->second <<"\n";
      return 0;
}