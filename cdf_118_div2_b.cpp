#include <bits/stdc++.h>
#include <set>
#include <string>
#include <limits>
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
void merge1(lld brr[], double arr[], lld l, lld m, lld r){
    lld i , j ,  k;
    lld n1 = m-l+1; 
    lld n2 = r - m;
    double L1 [n1];
    double R1 [n2];
    lld L2[n1];
    lld R2[n2];
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
void mergeSort1(lld brr[], double arr[], lld l, lld r){
    if (l < r)
    {
        lld m = l+(r-l)/2;
        mergeSort1(brr, arr, l, m);
        mergeSort1(brr,arr, m+1,r);
        merge1(brr, arr, l, m , r);
    } 
} 
void merge2(double brr[], lld arr[], lld l, lld m, lld r){
    lld i , j ,  k;
    lld n1 = m-l+1; 
    lld n2 = r - m;
    lld L1[n1];
    lld R1[n2];
    double L2 [n1];
    double R2 [n2];
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
        if (L1[i]  > R1[j]){
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
void mergeSort2(double brr[], lld arr[], lld l, lld r){
    if (l < r)
    {
        lld m = l+(r-l)/2;
        mergeSort2(brr, arr,l, m);
        mergeSort2(brr,arr,m+1,r);
        merge2(brr, arr, l, m, r);
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
    lld n, i;
    lld a, b;
    double k;
    cin >> n;
    cin >> a;
    cin >> b;
    cin >> k;
    lld A[n];
    lld B[n];
    lld P[n];
    double H[n];
    for(i = 0; i<n; i+=1){
        cin >>A[i];
        cin >>B[i];
        P[i]  =  i;
    }
    k = k/100;
    for(i = 0; i<n; i+=1){
        double x=((A[i]*a)*(1-k))+(B[i]*b);
        double y=((B[i]*a)*(1-k))+(A[i]*b);
        H[i] = (x>=y)?x:y;
    }
    mergeSort2(H,P,0,n-1);
    mergeSort1(P,H,0,n-1);
    for(i=n-1;i>=0; i-=1){
        cout<<P[i]+1<<" ";
        cout << fixed << setprecision(2) << H[i] << "\n"; 
    }
    return 0;
}