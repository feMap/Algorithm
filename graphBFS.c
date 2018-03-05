#include <stdio.h>

#define INF 99999999

struct note
{
    int x;
    int s;
};

int main()
{
    struct note que[2501];
    int e[51][51] = {0},book[51]={0};
    int head,tail;

    // 利用flag变量来跳出两层循环
    int i,j,n,m,a,b,cur,start,end,flag=0;

    scanf("%d %d %d %d", &n, &m, &start, &end);

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(i == j) e[i][j] = 0;
            else e[i][j] = INF;

    for(i=1; i<=m; i++)
    {
        scanf("%d %d", &a, &b);
        e[a][b] = 1;
        e[b][a] = 1;
    }

    head = 1;
    tail = 1;
    que[tail].x = start;
    que[tail].s = 0;
    tail++;

    book[start] = 1;

    while(head < tail)
    {
        cur = que[head].x;

        for(i=1; i<=n; i++)
        {
            if(book[i] == 0 && e[cur][i] == 1)
            {
                book[i] = 1;
                que[tail].x = i;
                que[tail].s = que[head].s + 1;
                tail++;
            }

            if(que[tail-1].x == end)
            {
                flag = 1;
                break;
            }
        }

        if(flag == 1)
            break;
        head++;
    }

    printf("Min change point is: %d", que[tail-1].s);

    return 0;
}