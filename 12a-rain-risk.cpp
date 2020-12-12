#include <bits/stdc++.h>

using namespace std;

int main(){
    int n=783;
    freopen("test.txt","r",stdin);
    int dx=0, dy=0, dir=90;
    for (int i=1;i<=n;++i){
        char op; int v;
        cin >> op >> v;
        if (op=='N') dx+=v;
        if (op=='S') dx-=v;
        if (op=='E') dy+=v;
        if (op=='W') dy-=v;
        if (op=='L') dir=(dir-v+360)%360;
        if (op=='R') dir=(dir+v)%360;
        if (op=='F'){
            if (dir==0) dx+=v;
            if (dir==90) dy+=v;
            if (dir==180) dx-=v;
            if (dir==270) dy-=v;
        }
    }
    cout << abs(dx)+abs(dy) << '\n';
}