#include <stdio.h>
int f[1000] = {0}, n, m, k, sum=0;

void init()
{
    int i;
    for(i=1; i<=n; i++)
        f[i] = i;
}

int getf(int x)
{
    if(f[x] == x)
        return x;
    else
    {
        f[x] = getf(f[x]);
        return f[x];
    }
}

void merge(int x,int y)
{
    int t1,t2;
    t1 = getf(x);
    t2 = getf(y);
    if(t1 != t2)
    {
        f[t2] = t1;
    }
}

int main()
{
    int i, x, y;
    scanf("%d %d", &n, &m);

    init();
    for(i=1; i<=m; i++)
    {
        scanf("%d %d", &x, &y);
        merge(x,y);
    }

    for(i=1; i<=n; i++)
    {
        if(f[i] == i)
            sum++;
    }

    printf("%d \n", sum);

    return 0;
}