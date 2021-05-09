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
      string s;
      cin >> s;
      set <lld> zero, ones;
      for(lld i = 0; i < s.size(); i += 1){
      	if (s[i] == '0')
      		zero.insert(i);
      	else
      		ones.insert(i);
      }
      vector <set <lld> > mc;
      while(true){
      	if (zero.empty())
      		break;
      	auth itr = zero.begin();
      	set <lld> temp;
      	temp.insert(*itr);
      	lld prev = (*itr);
      	lld cnt = 1;
      	while(true){
      		if (cnt%2){
      			ones.insert(prev);
      			auth pos = ones.find(prev);
      			pos++;
      			if (pos == ones.end()){
      				ones.erase(prev);
      				break;
      			}
      			else{
      				ones.erase (prev);
      				temp.insert(*pos);
      				prev = *pos;
      			}
      		}
      		else{
      			zero.insert(prev);
      			auth pos = zero.find(prev);
      			pos++;
      			if (pos == zero.end()){
      				zero.erase(prev);
      				temp.erase(prev);
      				break;
      			}
      			else{
      				zero.erase (prev);
      				temp.insert(*pos);
      				prev = *pos;
      			}
      		}
      		cnt++;
      	}
      	for(auth itr = temp.begin(); itr != temp.end(); itr++){
      		if (zero.count(*itr)) zero.erase(*itr);
      		else ones.erase(*itr);
      	}
      	mc.pb(temp);
      }
      if (!ones.empty()) {cout << "-1"; return 0;}

      cout << mc.size() << "\n";
      for(lld i = 0; i < mc.size(); i += 1){
      	cout << mc[i].size() << " ";
      	for(auth itr = mc[i].begin(); itr != mc[i].end(); itr++)
      		cout << (*itr)+1 << " ";
      	cout << "\n";
      }
      return 0;
}