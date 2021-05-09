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
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      string a;
      string b;
      cin >> a >> b;
      set <lld> c[26];
      for(lld i = 0; i < a.size(); i += 1){
      	c[(lld)a[i]-97].insert((lld)b[i]-97);
      }
      for(lld i = 0; i < b.size(); i += 1){
      	c[(lld)b[i]-97].insert((lld)a[i]-97);
      }
      map <lld, lld> mac;
      for(lld i = 0; i < 26; i += 1){
      	if (c[i].size() == 0)
      		continue;
      	if (c[i].size()  > 1)
      		{cout << "-1"; return 0;}
      	set <lld> :: iterator itr = c[i].begin();
      	if (c[*itr].size() == 0)
      		mac[i] = *itr;
      	if (c[*itr].size() == 1)
      	{
      		set <lld> :: iterator pos = c[*itr].begin();
      		if ((*pos) == i){mac[i] = *itr;}
      		else {cout << "-1"; return 0;}
      	}
      	if (c[*itr].size()  > 1)
      		{cout << "-1"; return 0;}
      }
      set <lld> vis;
      map <char, char> man;
      for(map <lld, lld> :: iterator itr = mac.begin(); itr != mac.end(); itr++){
      	if (itr->first != itr->second)
      	{
      		if (!vis.count(itr->first))
      		{
      			man[(char)(itr->first+97)] = (char)(itr->second+97);
      			vis.insert(itr->first);
      			vis.insert(itr->second);
      		}
      	}
      }
      cout << man.size() << "\n";
      for(map <char, char> :: iterator itr = man.begin(); itr!=man.end(); itr++)
      	cout << itr->first << " " << itr->second << "\n";
      return 0;
}