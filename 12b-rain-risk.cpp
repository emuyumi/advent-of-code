#include <bits/stdc++.h>

using namespace std;

int main(){
    int n=783;
    freopen("test.txt","r",stdin);
    int x=0, y=0, wx=1, wy=10;
    for (int i=1;i<=n;++i){
        char op; int v;
        cin >> op >> v;
        if (op=='N') wx+=v;
        if (op=='S') wx-=v;
        if (op=='E') wy+=v;
        if (op=='W') wy-=v;
        if (op=='L') v=360-v;
        if (op=='R'||op=='L'){
            while (v!=0){
                swap(wx,wy);
                wx=-wx;
                v-=90;
            }
        }
        if (op=='F'){
            for (int j=1;j<=v;++j) x+=wx, y+=wy;
        }
    }
    cout << abs(x)+abs(y) << '\n';
}