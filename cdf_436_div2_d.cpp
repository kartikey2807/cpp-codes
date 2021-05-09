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
      lld n;
      cin >> n;
      lld arr[n+1];
      lld cnt[n+1];
      set <lld> vis;
      vector <lld> val, bel;
      memset(cnt, 0, sizeof(cnt));
      for(lld i = 1; i <= n; i += 1){
      	cin >> arr[i];
      	cnt[arr[i]]++;
      	vis.insert(arr[i]);
      	val.push_back(i);
      	bel.push_back(arr[i]);
      }
      lld sum = 0;
      for(lld i = 1; i <= n; i += 1)
      	if (cnt[i] > 1)
      		sum += (cnt[i]-1);
      cout << sum << "\n";
      lld k = 1;
      lld fil[n+1];
      memset(fil, -1, sizeof(fil));
      for(lld i = 0; i < val.size();){
      	if (!vis.count(k)){
      		if (cnt[bel[i]] == 1 && fil[bel[i]] == -1){
      			fil[bel[i]]=1;
      			cnt[bel[i]]--;i++;
      		}
      		else{
      			if (k > bel[i] && fil[bel[i]] == -1){
      				fil[bel[i]]=1;
      				cnt[bel[i]]--;i++;
      			}
      			else{
      				arr[val[i]]=k;
      				cnt[bel[i]]--;k++;i++;
      			}
      		}
      	}
      	else
      		k++;
      }
      for(lld i = 1; i <= n; i += 1)
      	cout << arr[i] << " ";
      return 0;
}