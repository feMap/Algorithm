#include <stdio.h>
int main()
{
    // 1.修改了一下命名方式
    // 2.增加了读取数的数量的参数n
    int book[1001],i,j,t,n;
    
    scanf("%d", &n);

    for(i=0;i<1001;i++)
        book[i]=0;

    for(i=1;i<=n;i++)
    {
        scanf("%d", &t);
        book[t]++;
    }

    for(i=0;i<n;i++)
        for(j=1;j<=book[i];j++)
            printf("%d ", i);

    getchar();getchar();
    return 0;
}