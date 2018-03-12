#include <stdio.h>

#define INF 99999999

int min=INF,book[101],n,e[101][101];

void dfs(int cur, int dis)
{
    int j;
    if(dis>min) return;
    if(cur == n)
    {
        if(dis<min) min=dis;
        return;
    }
    for(j=1; j<=n; j++)
    {
        if(book[j] == 0 && e[cur][j]>0 && e[cur][j] < INF)
        {
            book[j] = 1;
            dfs(j, dis+e[cur][j]);
            book[j] = 0;
        }
    }
    // 深度遍历一定记得函数后面要return
    // 广度遍历是用的while(head<tail)来判断循环停止的
    return;
}

int main()
{
    int i,j,m,a,b,c;
    scanf("%d %d", &n, &m);

    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            if(i == j) e[i][j] = 0;
            else e[i][j] = 99999999;

    for(i=1; i<=m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        e[a][b] = c;
    }

    book[1] = 1;
    dfs(1,0);

    printf("From 1 to n, the shortest distance is: %d", min);

    return 0;
}