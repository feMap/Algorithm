#include <stdio.h>
#define inf 99999999

int main()
{
    int dis[10],i,k,n,m,u[10],v[10],w[10];

    // 优化增加的变量
    int bak[10],check,flag;

    scanf("%d %d", &n, &m);

    for(i=1; i<=n ; i++)
        scanf("%d %d %d", &u[i], &v[i], &w[i]);

    for(i=1; i<=n; i++)
        dis[i] = inf;

    dis[1] = 0;

    for(k=1; k<=n-1; k++)
    {
        check = 0;
        for(i=1; i<=m; i++)
        {
            if(dis[v[i]] > dis[u[i]] + w[i])
            {
                dis[v[i]] = dis[u[i]] + w[i];
                check = 1;
            }
        }

        if(check == 0)
            break;
    }

    //负权回路检测
    flag = 0;

    for(i=1; i<=m; i++){
        if(dis[v[i]] > dis[u[i]] + w[i])
        {
            //dis[v[i]] = dis[u[i]] + w[i];
            flag = 1;
        }
    }

    if(flag == 1)
        printf("There is negative weight circuit!\n");
    else
    {
        for(i=1; i<=n; i++)
            printf("%d ", dis[i]);
    }

    return 0;
}