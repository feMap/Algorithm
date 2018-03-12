#include <stdio.h>

struct note
{
    int u;
    int v;
    int w;
};

struct note a[100],t;
int book[100]={0};

void quickSort(int left, int right)
{
    int i,j;
    i = left+1;
    j = right;

    if(left == right) return;

    while(i != j)
    {
        while(a[j].w >= a[left].w)
        {
            j--;
        }

        while(a[i].w =< a[left].w)
        {
            i++;
        }
        if(i < j)
        {
            t = a[i]; a[i] = a[j]; a[j] = t;
        }
    }

    t = a[left]; a[left] = a[i]; a[i] = t;

    quickSort(left, i-1);
    quickSort(i+1, right);

}

int main()
{
    int i,j,n,m,sum=0;
    scanf("%d %d", &n, &m);

    for(i=1; i<=m; i++)
    {
        scanf("%d %d %d", &a[i].u, &a[i].u, &a[i].w);
    }

    quickSort();

    for(j=1; j<=m; j++) 
    {
        if(book[a[j].u] == 0  || book[a[j].v == 0])
        {
            book[a[j].u] = 1;
            book[a[j].v] = 1;
            sum += a[j].w;
        }
    }

    printf("%d \n", sum);

    return 0;
}