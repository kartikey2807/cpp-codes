// if you get a wrong answer but you are convinced
// that your logic is correct do :- 1) read the
// entire code and try to find if something needs
// to be added 2) start making test cases that you
// think can possibly give WA.
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
#define pb push_back
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      lld n;
      cin >> n;
      set <string> subv;
      for(lld i = 0; i < n; i += 1){
      	string s;
      	cin >> s;
      	lld len = s.size();
      	for(lld j = 0; j < len; j += 1){
      		for(lld k = j; k < len; k += 1){
      			string temp = "";
      			for(lld start = j; start <= k; start++){
      				temp += s[start];
      			}
      			subv.insert(temp);
      		}
      	}
      }
      for(char a = 'a'; a <= 'z'; a++){
      	string temp = "";
      	temp += a;
      	if (!subv.count(temp)){
      		cout << temp;
      		return 0;
      	}
      }
      for(char a = 'a'; a <= 'z'; a++){
      	for(char b = 'a'; b <= 'z'; b++){
      		string temp = "";
      		temp += a;
      		temp += b;
      		if (!subv.count(temp)){
      			cout << temp;
      			return 0;
      		}
      	}
      }
      for(char a = 'a'; a <= 'z'; a++){
      	for(char b = 'a'; b <= 'z'; b++){
      		for(char c = 'a'; c <= 'z'; c++){
      			string temp = "";
      			temp += a;
      			temp += b;
      			temp += c;
      			if (!subv.count(temp)){
      				cout << temp;
      				return 0;
      			}
      		}
      	}
      }
      return 0;
}