#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
  
struct queue  
{  
    int data[1000];  
    int head;  
    int tail;  
};  
  
struct stack  
{  
    int data[10];  
    int top;  
};  
  
int main(int argc, char const *argv[])  
{  
    struct queue q1, q2;  
    struct stack s;  
    int book[10];  
    int i, t;  
  
    q1.head = q1.tail = 0;  
    q2.head = q2.tail = 0;  
  
    s.top = -1;  
  
    for (i = 1; i <= 9; ++i)         /// 记录桌上有哪些牌，初始为空  
    {  
        book[i] = 0;  
    }  
  
  
    for (i = 0; i < 6; ++i)  
    {  
        scanf("%d", &q1.data[q1.tail++]);  
    }  
  
    for (i = 0; i < 6; ++i)  
    {  
        scanf("%d", &q2.data[q2.tail++]);  
    }  
  
    while(q1.head < q1.tail && q2.head < q2.tail)  
    {  
        t = q1.data[q1.head];       /// 第一个人出第一张牌 出队  
        if(0 == book[t])            /// 桌上没有这张牌 入栈  
        {  
            s.data[++s.top] = t;  
            book[t] = 1;        /// 并标记桌上已经有牌面为t的牌  
            q1.head++;  
        }  
        else  
        {  
            q1.data[q1.tail++] = t;         /// 赢牌  
            q1.head++;  
            while(s.data[s.top] != t)       /// 把相同的牌放到某人手中牌的末尾  
            {  
                book[s.data[s.top]] = 0;  
                q1.data[q1.tail++] = s.data[s.top--];  
            }  
        }  
  
        t = q2.data[q2.head];  
        if(0 == book[t])  
        {  
            s.data[++s.top] = t;  
            book[t] = 1;  
            q2.head++;  
        }  
        else  
        {  
            q2.data[q2.tail++] = t;  
            q2.head++;  
            while(s.data[s.top] != t)  
            {  
                book[s.data[s.top]] = 0;  
                q2.data[q2.tail++] = s.data[s.top--];  
            }  
        }  
    }  
  
    if(q2.head == q2.tail)                 /// 对手手中没有牌  
    {  
        printf("\nA win\n");  
        printf("A手中的纸牌: ");  
        for (i = q1.head; i < q1.tail; ++i)  
        {  
            printf("%d ", q1.data[i]);  
        }  
  
        if(s.top > -1)                       /// 输出桌上的牌  
        {  
            printf("\n桌上的牌: ");  
            for (i = 0; i <= s.top; ++i)  
            {  
                printf("%d ", s.data[i]);  
            }  
        }  
        else  
        {  
            printf("\n桌上已经没有纸牌了！");  
        }  
    }  
    else  
    {  
        printf("\nB win\n");  
        printf("B手中的纸牌: ");  
        for (i = q2.head; i < q2.tail; ++i)  
        {  
            printf("%d ", q2.data[i]);  
        }  
  
        if(s.top > -1)  
        {  
            printf("\n桌上的牌: ");  
            for (i = 0; i <= s.top; ++i)  
            {  
                printf("%d ", s.data[i]);  
            }  
        }  
        else  
        {  
            printf("\n桌上已经没有纸牌了！");  
        }  
    }  
    return 0;  
}  