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
void psort (lld A[], lld B[], lld n)
{
	pair <lld, lld> P[n];
	for(lld i = 0; i < n; i += 1){
		P[i].first  = A[i];
		P[i].second = B[i];
	}
	sort(P,P+n);
	for(lld i = 0; i < n; i += 1){
		A[i] = P[i].first;
		B[i] = P[i].second;
	}
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld t, l;
      cin >> t;
      foi(l,t){
      	string s;
      	cin >> s;
      	lld n = s.length();
      	lld A[n];
      	for(lld i = 0; i < n; i += 1){
      		A[i] = (lld)s[i]-65;
      	}
      	map <lld, lld> cnt;
      	cnt[15] = cnt[17] = cnt[18]=0;
      	for(lld i = 0; i < n; i += 1){
      		cnt[A[i]]++;
      	}
      	lld a[3], b[3];
      	lld i = 0;
      	for(map <lld, lld> :: iterator itr = cnt.begin(); itr != cnt.end(); itr++){
      		a[i] = itr->first ;
      		b[i] = itr->second;
      		i++;
      	}
      	psort(b,a,3);
      	lld x;
      	switch(a[2]){
      		case 15 : x = 18; break;
      		case 17 : x = 15; break;
      		case 18 : x = 17; break;
      	}
      	for(lld i = 0; i < n; i += 1){
      		cout << (char)(x+65);
      	}
      	cout << "\n";
      }
      return 0;
}