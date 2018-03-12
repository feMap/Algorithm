#include <stdio.h>

int a[10], book[10], total=0;

void dfs(int step)
{
    int i;
    if(step==10)
    {
        if(100*a[1]+10*a[2]+a[3] + 100*a[4]+10*a[5]+a[6] == 100*a[7]+10*a[8]+a[9])
        {
            total++;
            printf("%d%d%d + %d%d%d = %d%d%d\n", a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
        }
        return;
    }

    for(i=1; i<=9; i++)
    {
        if(book[i] == 0)
        {
            book[i] = 1;
            a[step] = i;

            dfs(step+1);

            book[i] = 0;
        }
    }

    return;
}

int main()
{
    dfs(1);

    printf("total = %d", total/2);

    getchar();getchar();
    return 0;
}