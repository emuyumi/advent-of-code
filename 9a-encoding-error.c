#include <stdio.h>
#include <stdbool.h>
typedef long long ll;

ll arr[1001];

int main(){
    FILE *in;
    in=fopen("test.txt", "r");
    for (int i=1;i<=1000;++i) fscanf(in,"%lld",&arr[i]);
    for (int i=26;i<=1000;++i){
        bool flag=0;
        for (int j=i-25;j<i;++j)
            for (int k=j+1;k<i;++k)
                if (arr[j]+arr[k]==arr[i]) flag=1;
        if (!flag){
            printf("%lld",arr[i]);
            break;
        }
    }
}