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
      lld A[25];
      for(lld i = 1; i <= 24; i += 1){
      	cin >> A[i];
      }
      set <lld> vis;
      lld cnt = 1;
      for(lld i = 1; i <= 24; i += 4){
      	lld f = 1;
      	for(lld j = i+1; j < i+3; j += 1){
      		if (A[j] != A[j-1])
      			f = 0;
      	}
      	if (f == 1)
      		vis.insert(cnt);
      	cnt++;
      }
      if (vis.size() == 2){
      	map <pair <lld, lld>, pair<lld, lld> > idx;
      	for(lld i = 1; i <= 24; i += 1){
      		for(lld j = 1; j <= 24; j += 1){
      			idx[{i,j}] = {A[i],A[j]};
      		}
      	}
      	if (vis.count(1) && vis.count(3)){
      		if (idx[{13,14}] == idx[{7,8}] && idx[{5,6}] == idx[{19,20}] && idx[{17,18}] == idx[{23,24}] && idx[{21,22}] == idx[{15,16}]) {cout << "YES"; return 0;}
      		if (idx[{5,6}] == idx[{15,16}] && idx[{17,18}] == idx[{7,8}] && idx[{21,22}] == idx[{19,20}] && idx[{13,14}] == idx[{23,24}]) {cout << "YES"; return 0;}
      		cout << "NO";
      	}
      	else if (vis.count(2) && vis.count(6)){
      		if (idx[{3,4}] == idx[{18,20}] && idx[{17,19}] == idx[{11,12}] && idx[{9,10}] == idx[{13,15}] && idx[{14,16}] == idx[{1,2}]) {cout << "YES"; return 0;}
      		if (idx[{17,19}] == idx[{1,2}] && idx[{9,10}] == idx[{18,20}] && idx[{14,16}] == idx[{11,12}] && idx[{3,4}] == idx[{13,15}]) {cout << "YES"; return 0;}
      		cout << "NO";
      	}
      	else if (vis.count(4) && vis.count(5)){
      		if (idx[{1,3}] == idx[{6,8}] && idx[{5,7}] == idx[{10,12}] && idx[{9,11}] == idx[{21,23}] && idx[{22,24}] == idx[{2,4}]) {cout << "YES"; return 0;}
      		if (idx[{5,7}] == idx[{2,4}] && idx[{9,11}] == idx[{6,8}] && idx[{22,24}] == idx[{10,12}] && idx[{21,23}] == idx[{1,3}]) {cout << "YES"; return 0;}
      		cout << "NO";
      	}
      	else  cout << "NO";
      }
      else cout << "NO";
      return 0;
}