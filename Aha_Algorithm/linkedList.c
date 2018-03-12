//链表介绍
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head, *p, *q, *t;
    int i, n, a;
    scanf("%d", &n);
    head = NULL;
    for(i=1; i<=n; i++)
    {
        scanf("%d", &a);
        //动态申请一个空间，用来存放一个节点，并用临时指针p指向这个节点
        p = (struct node *)malloc(sizeof(struct node));
        p->data = a;
        p->next = NULL;

        if(head == NULL)
            head = p;
        else
            q->next = p;
        // 主要是为了在尾部一直插入新的节点，保存p节点的备份
        // 这个q的含义其实是上一个节点的地址
        q = p;
    }

    t = head;
    while(t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }

    getchar();getchar();
    return 0;
}