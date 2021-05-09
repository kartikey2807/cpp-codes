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
set <lld> vis;
map <lld, lld> mac;
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n, k;
      cin >> n >> k;
      lld S[n],M[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> S[i] >> M[i];
      }
      vis.insert(0);
      mac[0] = k;
      for(lld i = 0; i < n; i += 1){
      	auth itr = vis.begin();
      	mac[*itr]--;
      	if (mac[*itr] == 0)
      		vis.erase(*itr);
      	cout << max(S[i],*itr) + M[i] << "\n";
      	mac[max(S[i],*itr)+M[i]]++;
      	if (mac[max(S[i],*itr)+M[i]] == 1)
      		vis.insert(max(S[i],*itr)+M[i]);
      }
      return 0;
}