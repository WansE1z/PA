	
#include <cstdio>
#include <cstring>
#define INF 1000000000
#define MAXN 1000
int n, from[MAXN+1], q[MAXN+1], v[MAXN+1][MAXN+1], f[MAXN+1][MAXN+1], c[MAXN+1][MAXN+1];
int bfs(){
    int st, dr, p, x;
    st=0;
    dr=1;
    q[0]=1;
    memset(from, 0, sizeof from);
    while((st<dr)&&(from[n]==0)){
        for(p=1; p<=v[q[st]][0]; p++){
            x=v[q[st]][p];
            if((from[x]==0)&&(c[q[st]][x]>f[q[st]][x])){
                from[x]=q[st];
                q[dr++]=x;
            }
        }
        st++;
    }
    return (from[n]!=0);
}
int main(){
    int m, i, x, y, z, ans, min, p;
    FILE *fin, *fout;
    fin=fopen("in", "r");
    fout=fopen("out", "w");
    fscanf(fin, "%d%d", &n, &m);
    for(i=1; i<=m; i++){
        fscanf(fin, "%d%d%d", &x, &y, &z);
        v[x][++v[x][0]]=y;
        v[y][++v[y][0]]=x;
        c[x][y]+=z;
    }
    while(bfs()){
        for(p=1; p<=v[n][0]; p++){
            x=v[n][p];
            if((from[x]!=0)&&(c[x][n]>f[x][n])){
                from[n]=x;
                min=INF;
                i=n;
                while(i!=1){
                    if(min>c[from[i]][i]-f[from[i]][i]){
                        min=c[from[i]][i]-f[from[i]][i];
                    }
                    i=from[i];
                }
                i=n;
                while(i!=1){
                    f[from[i]][i]+=min;
                    f[i][from[i]]-=min;
                    i=from[i];
                }
            }
        }
    }
    ans=0;
    for(i=1; i<n; i++){
        ans+=f[i][n];
    }
    fprintf(fout, "%d\n", ans);
    fclose(fin);
    fclose(fout);
    return 0;
}