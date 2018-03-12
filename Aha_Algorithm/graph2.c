#include <stdio.h>

int main()
{
    int i,j,n,m,a,b,cur,book[101]={0},e[101][101];
    int que[10001], head, tail;

    scanf("%d %d", &n, &m);

    //邻接矩阵初始化
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            if(i == j) e[i][j] = 0;
            else e[i][j] = 99999999;

    for(i=1; i<=m; i++)
    {
        scanf("%d %d", &a, &b);
        e[a][b] = 1;
        e[b][a] = 1;
    }

    head=1;
    tail=1;

    que[tail] = 1;
    tail++;
    // 千万记得要对第一个节点标记哟！
    book[1] = 1;

    while(head<tail)
    {

        cur = que[head];
        
        printf("%d ", cur);

        for(i=1; i<=n; i++)
        {
            if(e[cur][i] == 1 && book[i] == 0)
            {
                book[i] == 1;
                que[tail] = i;
                tail++;
            }

            // 这一步可以少运行几次循环
            if(tail > n)
                break;
        }

        head++;
    }

    printf("\n");
    for(i=1; i<=n; i++)
        printf("%d ", que[i]);

    // getchar();getchar();
    return 0;
}