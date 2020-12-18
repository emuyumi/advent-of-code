#include <bits/stdc++.h>

using namespace std;

bool last[32][32][32][32], arr[32][32][32][32];

void go(){
    swap(last,arr); memset(arr,0,sizeof arr);
    for (int x=1;x<=30;++x){
        for (int y=1;y<=30;++y){
            for (int z=1;z<=30;++z){
                for (int i=1;i<=30;++i){
                    int cnt=0;
                    for (int dx=-1;dx<=1;++dx){
                        for (int dy=-1;dy<=1;++dy){
                            for (int dz=-1;dz<=1;++dz){
                                for (int di=-1;di<=1;++di){
                                    if (dx==0&&dy==0&&dz==0&&di==0) continue;
                                    cnt+=last[x+dx][y+dy][z+dz][i+di];
                                }
                            }
                        }
                    }
                    if (last[x][y][z][i]){
                        if (cnt==2||cnt==3) arr[x][y][z][i]=1;
                    }
                    else{
                        if (cnt==3) arr[x][y][z][i]=1;
                    }
                }
            }
        }
    }
}

int main(){
    int n; n=8;
    for (int i=15;i<=14+n;++i){
        for (int j=15;j<=14+n;++j){
            char a; cin >> a;
            arr[15][15][i][j]=a=='#';
        }
    }
    for (int i=1;i<=6;++i) go();
    int tot=0;
    for (int i=1;i<=30;++i){
        for (int j=1;j<=30;++j){
            for (int k=1;k<=30;++k){
                for (int l=1;l<=30;++l){
                    tot+=arr[i][j][k][l];
                }
            }
        }
    }
    cout << tot << '\n';
}