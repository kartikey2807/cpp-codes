#include <bits/stdc++.h>
#include <set>
#include <map>
#include <string>
using namespace std;
typedef long long int lld;
#define FastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
double getComb (double n, double x){
    if (x > n){
        return 0;
    }
    else{
        double r = 1.0;
        for(double i = 1.0; i<=x; i += 1){
            double a = n-i+1;
            double b = a / i;
            r*=b;
        }
        return r;
    }
}
void merge(lld brr[], lld arr[], lld l, lld m, lld r){
    lld i , j ,  k;
    lld n1 = m-l+1; 
    lld n2 = r - m;
    lld L1[n1],L2[n1];
    lld R1[n2],R2[n2];
    for (i = 0; i < n1; i++){
        L1[i] = arr[l + i];
        L2[i] = brr[l + i];
    }
    for (j = 0; j < n2; j++){
        R1[j] = arr[m+1+j];
        R2[j] = brr[m+1+j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L1[i] <= R1[j]){
            arr[k] = L1[i];
            brr[k] = L2[i];
            i++;
        }
        else{
            arr[k] = R1[j];
            brr[k] = R2[j];
            j++;
        }
        k++;
    }
        while (i   <   n1){
            arr[k] = L1[i];
            brr[k] = L2[i];
            i++;
            k++;
        }
        while (j   <   n2){
            arr[k] = R1[j];
            brr[k] = R2[j];
            j++;
            k++;
        }
}
void mergeSort(lld brr[], lld arr[], lld l, lld r){
    if (l < r)
    {
        lld m = l+(r-l)/2;
        mergeSort(brr, arr,l, m);
        mergeSort(brr,arr,m+1,r);
        merge(brr, arr, l, m, r);
    } 
} 
int main () {
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("inputf.in",  "r",  stdin);
    // for writing output to output.txt
    freopen("outputf.in", "w", stdout);
    #endif
    FastIO
    lld n, m;
    cin >> n;
    cin >> m;
    lld i, j;
    lld x, y;
    lld A[n][n];
    for(i = 0; i<n; i+=1){
    for(j = 0; j<n; j+=1){
        A[i][j]= 0;
    }
    }
    for(i = 0; i<m; i+=1){
        cin >> x;
        cin >> y;
        x-=1;
        y-=1;
        A[x][y]= 1;
        A[y][x]= 1;
    }
    lld c , t = 0;
    set <lld> :: iterator itr;
    while(1){
    set <lld> rep;
        for(i = 0; i<n; i+=1){
            c = 0;
        for(j = 0; j<n; j+=1){
            if (A[i][j] == 1){
                c+= 1;
            }
        }
            if (c==1){
                rep.insert(i);
            }
        }
        if (rep.size()  >= 1){
                t+= 1;
        }
        else{
                break;
        }
        for(itr = rep.begin(); itr!=rep.end(); itr++){
        for(j = 0; j<n; j+= 1){
            A[*itr][j] = 0;
            A[j][*itr] = 0;
        }
        }
    }
        cout  << t << "\n";
    return 0;
}