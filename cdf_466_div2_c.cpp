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
      lld n, k;
      string s;
      cin >> n >> k >> s;
      if (k > n){
      	set <char> c;
      	for(lld i = 0; i < n; i++)
      		c.insert(s[i]);
      	set <char> :: iterator itr = c.begin();
      	while(n < k){
      		s += (*itr);
      		n++;
      	}
      	cout << s;
      }
      else{
      	set <char> x;
      	for(lld i = 0; i < n; i++)
      		x.insert(s[i]);
      	char c[k];
      	for(lld i = 0; i < k; i++)
      		c[i] = s[i];
      	set <char> :: iterator itr;
      	set <char> :: iterator pos;
      	pos = x.begin();
      	for(lld i = k-1; i >= 0; i -= 1){
      		itr = x.find(c[i]);
      		itr++;
      		if (itr!= x.end()){
      			c[i] = *itr;
      			break;
      		}
      		else
      			c[i] = *pos;
      	}
      	foi(i,k) cout << c[i];
      }
      return 0;
}