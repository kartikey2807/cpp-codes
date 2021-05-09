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
bool div1 (char a)
{
	lld x = (lld)a-48;
	if (x%8 == 0) return true;
	return false;
}
bool div2 (char a, char b)
{
	lld x = (lld)a-48, y = (lld)b-48;
	if (((x*10)+y)%8 == 0)
		return true;
	return false;
}
bool div3 (char a, char b, char c)
{
	lld x = (lld)a-48, y = (lld)b-48, z = (lld)c-48;
	if (((x*100)+(y*10)+z)%8 == 0)
		return true;
	return false;
}
int main ()
{
      #ifndef ONLINE_JUDGE
      freopen("inputf.in",  "r",  stdin);
      freopen("outputf.in", "w", stdout);
      #endif
      FastIO
      string s;
      cin >> s;
      lld len = s.size();
      for(lld i = 0; i < len; i += 1){
      	if (div1(s[i]))
      		{cout << "YES\n" << s[i]; return 0;}
      }
      for(lld i = 0; i < len; i += 1){
      	for(lld j = i+1; j < len; j += 1){
      		if (div2(s[i],s[j]))
      			{cout << "YES\n" << s[i] << s[j]; return 0;}
      	}
      }
      for(lld i = 0; i < len; i += 1){
      	for(lld j = i+1; j < len; j += 1){
      		for(lld k = j+1; k < len; k += 1){
      			if (div3(s[i],s[j],s[k]))
      				{cout << "YES\n" << s[i] << s[j] << s[k]; return 0;}
      		}
      	}
      }
      cout << "NO";
      return 0;
}