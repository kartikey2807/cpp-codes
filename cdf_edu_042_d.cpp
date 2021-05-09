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
      lld n;
      cin >> n;
      lld A[n];
      for(lld i = 0; i < n; i += 1){
      	cin >> A[i];
      }
      map <lld, priority_queue <lld, vector <lld>, greater <lld> > > mac;
      set <lld> val;
      for(lld i = 0; i < n; i += 1){
      	mac[A[i]].push(i);
      }
      for(lld i = 0; i < n; i += 1){
      	if (mac[A[i]].size()>1){
      		val.insert(A[i]);
      	}
      }
      while(!val.empty()){
      	auth itr = val.begin();
      	lld l = mac[*itr].top(); mac[*itr].pop();
      	lld r = mac[*itr].top(); mac[*itr].pop();
      	mac[2*(*itr)].push(r);
      	if (mac[*itr].size() <= 1)
      		val.erase(*itr);
      	if (mac[2*(*itr)].size() > 1)
      		val.insert(2*(*itr));
      }
      map <lld, lld> pos;
      for(map <lld, priority_queue <lld, vector <lld>, greater <lld> > > :: iterator itr = mac.begin(); itr != mac.end(); itr++){
      	priority_queue <lld, vector <lld>, greater <lld> > q = itr->second;
      	if (!q.empty())
      		pos[q.top()] = itr->first;
      }
      cout << pos.size() << "\n";
      for(map <lld, lld> :: iterator itr = pos.begin(); itr != pos.end(); itr++)
      	cout << itr->second << " ";
      return 0;
}