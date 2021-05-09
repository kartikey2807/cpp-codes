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
      string s[52];
      for(lld i = 0; i < 26; i += 1){
      	char x = (char)(i+65);
      	s[i] = x;
      }
      for(lld i =26; i < 52; i += 1){
      	char x = (char)(i-26+97);
      	s[i] = 'A';
      	s[i]+= x;
      }
      lld n, k;
      cin >> n >> k;
      vector <string> v;
      string x;
      cin >> x;
      if (x == "YES"){
      	for(lld i = 0; i < k; i += 1)
      		v.push_back(s[i]);
      }
      else{
      	for(lld i = 0; i<k-1; i += 1)
      		v.push_back(s[i]);
      	v.push_back(s[0]);
      }
      for(lld i = 1; i < n-k+1; i += 1){
      	cin >> x;
      	if (x == "YES"){
      		foi(j,52){
      			lld f = 1;
      			for(lld k = i; k < v.size(); k += 1)
      				if (s[j] == v[k])
      					f = 0;
      			if (f == 1){v.push_back(s[j]);break;}
      		}
      	}
      	else{
      		v.push_back(v[i]);
      	}
      }
      foi(i,v.size()) cout << v[i] << " ";
      return 0;
}