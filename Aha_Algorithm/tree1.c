#include <stdio.h>

int h[101];
int n;

void swap(int x, int y)
{
    int t;
    t = h[x];
    h[x] = h[y];
    h[y] = t;
    return;
}

void siftdown(int i)
{
    int t, flag=0;

    // i*2 <= n 表示的含义是i节点至少有左儿子
    // i*2+1 <= n 表示i节点有两个儿子
    while(i*2 <= n && flag == 0)
    {
        if(h[i] > h[i*2])
            t = i*2;
        else
            t = i;

        if(i*2+1 <= n)
        {
            if(h[t] > h[i*2 + 1])
                t = i*2 + 1;
        }

        if(t != i)
        {
            swap(t,i);
            // 继续向下检索，直到超过堆元素位置
            i = t;
        }
        else
            // 防止已经取到合适的位置
            flag=1;
    }

    return;
}

void siftup(int i)
{
    int flag=0;
    if(i == 1) return;

    while(i != 1 && flag==0)
    {
        if(h[i]<h[i/2])
            swap(i,i/2);
        else
            flag = 1;
        i = i/2;
    }
    return;
}

void create()
{
    int i;
    for(i = n/2; i>=1; i--)
    {
        siftdown(i);
    }
    return;
}

int deletemax()
{
    int t;
    t = h[1];
    h[1] = h[n];
    n--;
    siftdown(1);
    return t;
}

int main()
{
    int i, num;
    scanf("%d", &num);

    for(i=1; i<=num; i++)
        scanf("%d", &h[i]);

    n = num;

    create();

    for(i=1; i<=num; i++)
        printf("%d ", deletemax());

    return 0;
}