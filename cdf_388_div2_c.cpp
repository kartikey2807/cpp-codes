// マップやその他の非常に複雑なタプルは使用しないでください。そして、文字列
// で遊ぶとき、それを整数配列に変換します。それは不思議です。パニックになら
// ないでください。それに慣れているときは常に競争をしてください。評価が下がっ
// たときに強調しないでください、それは起こります。だから、冷静ですが重要なコード:)
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
void del (set <lld> *val, lld p)
{
	if (!(*val).empty()){
		(*val).insert(p);
		set <lld> :: iterator itr = (*val).find(p);
		set <lld> :: iterator pos = (*val).begin();
		itr++;
		if (itr != (*val).end())
			(*val).erase(*itr);
		else
			(*val).erase(*pos);
		(*val).erase(p);
	}
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      string s;
      cin >> n >> s;
      set <lld> dep, rem;
      for(lld i = 0; i < n; i += 1){
      	if (s[i] == 'D')
      		dep.insert(i);
      	else  rem.insert(i);
      }
      while(!rem.empty() && !dep.empty()){
      	for(lld i = 0; i < n; i += 1){
      		if (!dep.count(i) && !rem.count(i))
      			continue;
      		if (s[i]  == 'D')
      			del(&rem,i);
      		else
      			del(&dep,i);
      	}
      }
      for(lld i = 0; i < n; i += 1){
      	if (!dep.count(i) && !rem.count(i))
      		continue;
      	cout << s[i];
      	return 0;
      }
      return 0;
}