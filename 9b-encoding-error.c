#include <stdio.h>
#include <stdbool.h>
typedef long long ll;

ll arr[1001], ans=105950735, tot;

int main(){
    FILE *in;
    in=fopen("test.txt", "r");
    for (int i=1;i<=1000;++i) fscanf(in,"%lld",&arr[i]);
    int l=1, r;
    for (r=1;r<=1000;++r){
        tot+=arr[r];
        while (tot>ans) tot-=arr[l++];
        if (tot==ans) break;
    }
    ll mn=arr[l], mx=arr[l];
    for (int i=l;i<=r;++i){
        if (mn>arr[i]) mn=arr[i];
        if (mx<arr[i]) mx=arr[i];
    }
    printf("%lld",mn+mx);
}