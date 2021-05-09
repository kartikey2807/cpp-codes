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
      string s;
      cin >> s;
      lld n = s.length();
      lld A[n];
      for(lld i = 0; i < n; i += 1){
            A[i] = (lld)s[i]-48;
            A[i]%= 3;
      }
      lld count = 0;
      for(lld i = 0; i < n; i += 1){
            if (A[i] == 0){
                  count++;
            }
            else{
                  if ((i+2 < n && A[i] == 1 && A[i+1] == 1 && A[i+2] == 1) || (i+2 < n && A[i] == 2 && A[i+1] == 2 && A[i+2] == 2)){
                        i+=2;
                        count++;
                  }
                  else{
                        if ((i+1 < n && A[i] == 1 && A[i+1] == 2) || (i+1 < n && A[i] == 2 && A[i+1] == 1)){
                              i+=1;
                              count++;
                        }
                  }
            }
      }
      cout << count;
      return 0;
}