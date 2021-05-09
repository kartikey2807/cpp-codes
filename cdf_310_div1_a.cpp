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
      lld n, k;
      cin >> n >> k;
      lld len[k];
      vector <lld> v[k];
      for(lld i = 0; i < k; i += 1){
      	cin >> len[i];
      	for(lld j = 0; j < len[i]; j += 1){
      		lld r;
      		cin >> r;
      		v[i].push_back(r);
      	}
      }
      lld sum = 0;
      lld p;
      for(lld i = 0; i < k; i += 1){
      	if (v[i][0] == 1){
      		lld cnt = 0;
      		for(lld j = 1; j < len[i]; j += 1){
      			if (v[i][j] == v[i][j-1]+1)
      				cnt++;
      			else
      				break;
      		}
      		cnt++;
      		sum += 2*(len[i]-cnt);
      		p = i;
      		break;
      	}
      }
      for(lld i = 0; i < k; i += 1){
      	if (i == p)
      		continue;
      	sum += len[i]-1+len[i];
      }
      cout << sum;
      return 0;
}