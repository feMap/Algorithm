#include <stdio.h>

struct note
{
    int x;
    int y;
};

char a[20][21];

int getnum(int i, int j)
{
    int sum, x, y;
    sum = 0;

    x=i; y=j;
    while(a[x][y] != '#')
    {
        if(a[x][y] == 'G')
            sum++;
        x--;
    }

    x=i; y=j;
    while(a[x][y] != '#')
    {
        if(a[x][y] == 'G')
            sum++;
        x++;
    }

    x=i; y=j;
    while(a[x][y] != '#')
    {
        if(a[x][y] == 'G')
            sum++;
        y--;
    }

    x=i; y=j;
    while(a[x][y] != '#')
    {
        if(a[x][y] == 'G')
            sum++;
        y++;
    }

    return sum;
}

int main()
{
    struct note que[401];
    int head=1, tail=1;
    int book[20][20] = {0};

    int i,j,k,sum,max=0,mx,my,n,m,startx,starty,tx,ty;
    int next[4][2]={{1,0},{0,-1},{-1,0},{0,1}};

    scanf("%d %d %d %d", &n, &m, &startx, &starty);

    for(i=0; i<=n-1; i++)
        scanf("%s", a[i]);

    que[tail].x = startx;
    que[tail].y = starty;
    tail++;

    //千万记得用初始位置进行最大值和状态值的标记
    book[startx][starty] = 1;
    max = getnum(startx,starty);
    mx = startx;
    my = starty;

    //###
    // printf("%d", getnum(5,3));

    while(head<tail)
    {
        for(k=0; k<4; k++)
        {
            tx = que[head].x + next[k][0];
            ty = que[head].y + next[k][1];

            if(tx<0 || tx>n-1 || ty<0 || ty>m-1)
                continue;

            if(a[tx][ty] == '.' && book[tx][ty] == 0)
            {
                book[tx][ty] = 1;
                que[tail].x = tx;
                que[tail].y = ty;
                tail++;

                
                sum = getnum(tx, ty);
                // 为何不能不直接如下这么写???
                // if(getnum(tx,ty) > max)
                if(sum > max)
                {
                    max = sum;
                    mx = tx;
                    my = ty;
                }
            }
        }
        head++;
    }

    printf("Place the bomb in (%d,%d), down %d monsters\n", mx, my, max);
    
    getchar();getchar();
    return 0;
}