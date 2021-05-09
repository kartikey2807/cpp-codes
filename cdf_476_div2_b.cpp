// みなさん私はカーティキー・シャルマです。LNMIITで勉強しています。私は2年目で、コロナパンデミックが発
// 生しています。世界は終わりそうだ。だから私はそれを最大限に生きたいと思っています。それはつまり、コー
// ドを最大限に意味しているのです。私の好きなアニメは「キメツノヤイバ」で、私の一番の男の子はゼニツで、
// 私の一番の女の子はネズコです。私の好きな呼吸スタイルは息吹です。私の最高の悪魔の血の芸術は、
// ククシボによって使用される月の息です。ムーザンは亡くなり、今ではタンジローがポップの新しい魔王です。
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
#define foi(i,n) for(i = 0; i < n; i+=1)
#define fod(i,n) for(i=n-1; i >=0; i-=1)
#define MAX std::numeric_limits<lld>::max()
#define MIN std::numeric_limits<lld>::min()
#define FastIO  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",   stdin);
      freopen("outputf.in", "w",  stdout);
      #endif
      FastIO
      lld n, k;
      cin >> n >>  k;
      char dda[n][n];
      for(lld i = 0; i < n; i += 1){
            for(lld j = 0; j < n; j += 1){
                  cin >> dda[i][j];
            }
      }
      map <pair<lld,lld>,lld> count;
      for(lld i = 0; i < n; i += 1){
            lld pount = 0;
            queue <lld> X;
            queue <lld> Y;
            for(lld j = 0; j < n; j += 1){
                  if (dda[i][j]  ==  '.'){
                        X.push(i);
                        Y.push(j);
                        pount+= 1;
                  }
                  else{
                        pount = 0;
                        while(!X.empty()){
                              X.pop();
                              Y.pop();
                        }
                  }
                  if (pount == k){
                        pount-= 1;
                        queue <lld> temp_X = X;
                        queue <lld> temp_Y = Y;
                        while(!temp_X.empty()){
                              count[{temp_X.front(), temp_Y.front()}]++;
                              temp_X.pop();
                              temp_Y.pop();
                        }
                        X.pop();
                        Y.pop();
                  }
            }
      }
      for(lld j = 0; j < n; j += 1){
            lld pount = 0;
            queue <lld> X;
            queue <lld> Y;
            for(lld i = 0; i < n; i += 1){
                  if (dda[i][j]  ==  '.'){
                        pount+= 1;
                        X.push(i);
                        Y.push(j);
                  }
                  else{
                        pount = 0;
                        while(!X.empty()){
                              X.pop();
                              Y.pop();
                        }
                  }
                  if (pount == k){
                        pount-= 1;
                        queue <lld> temp_X = X;
                        queue <lld> temp_Y = Y;
                        while(!temp_X.empty()){
                              count[{temp_X.front(), temp_Y.front()}]++;
                              temp_X.pop();
                              temp_Y.pop();
                        }
                        X.pop();
                        Y.pop();
                  }
            }
      }
      if (count.empty()){
            cout <<"1 1";
      }
      else{
            lld max = MIN;
            lld row , col;
            for(lld i = 0; i < n; i += 1){
                  for(lld j = 0; j < n; j += 1){
                        if (count[{i,j}] > max){
                              max =count[{i,j}];
                              row = i;
                              col = j;
                        }
                  }
            }
            cout << row+1 << " " << col+1 << "\n";
      }
      return 0;
}