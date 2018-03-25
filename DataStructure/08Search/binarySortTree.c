// Binary tree defination
// typedef bool Status;

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

/*指针f指向T的双亲
- 如果查找成功，则p指针指向该数据元素节点，并返回TRUE值
- 否则指针p指向访问的最后一个节点，并返回FALSE值
*/
Status SearchBST(BiTree T, int key, BiTree f, BiTree *p)
{
    // 递归循环的终止条件
    // 如果没有查到对应的value值，则返回p指向的最后一个节点，为后面的插入做准备
    if(!T)
    {
        *p = f;
        return FALSE;
    }
    else if(T->data == key)
    {
        *p = T;
        return TRUE;
    }
    else if(T->data > key)
    {
        SearchBST(T->lchild, key, T, *p);
    }
    else
    {
        SearchBST(T->rchild, key, T, *p);
    }
}


/*当二叉树T中不存在关键词等于key的元素时，*/
/*插入key值并返回TRUE，否则返回FALSE*/
Status InsertBST(BiTree *T, int key)
{
    BiTree p, s;
    if(!SearchBST(*T, key, NULL, &p))
    {
        s = (BiTree)malloc(sizeof(BiTNode))
        s->data = key;
        s->lchild = NULL;
        s->rchild = NULL;

        if(!p)
        {
            // 这个T是指针的指针，主要是为了方便在初始化的时候直接&Tree，就不用拷贝整棵树了
            *T = s;
        }
        else if(p->data > key)
        {
            p->lchild = s;
        }
        else
        {
            p->rchild = s;
        }
    }
    
    else
    {
        return FALSE;
    }
}


int i;
int a[10] = {62, 88, 58, 47, 35, 73, 51, 99, 37, 93};
BiTree T = NULL;
for(i = 0; i < 10; i++)
{
    InsertBST(&T, a[i]);
}


/*若二叉排序树存在关键字等于key的数据元素时，则删除该数据元素节点*/
/*并返回TRUE, 否则返回FLASE*/
Status DeleteBST(BiTree *T, int key)
{
    // 指向根节点位置的点不一定为NULL，因此这里使用的是*T
    if(!*T)
    {
        return FALSE;
    }
    else
    {
        if((*T)->data == key ){
            Delete(T);
        }
        else if((*T)->data > key)
        {
            DeleteBST(&(*T)->lchild, key);
        }
        else
        {
            DeleteBST(&(*T)->rchild, key);
        }
    }
}

// 删除节点p
Status Delete(BiTree *p)
{
    BiTree q, s;
    if( (*p) -> rchild == NULL)
    {
        q = *p; *p = (*p)->lchild; free(q);
    }
    else if( (*p) -> lchild == NULL)
    {
        q = *p; *p = (*p)->rchild; free(q);
    }
    else
    {
        q = *p; s = (*p)->lchild;
        
        while(s->rchild)
        {
            q = s; s = s->rchild;
        }

        (*p)->data = s->data;
        // q = *p的情况出现在被删除节点的子节点无右子树
        if(q != *p)
        {
            // 不管最后的节点是否为空，都可以用这个等式
            q->rchild = s->lchild;
        }
        else
        {
            q->lchild = s->lchild;
        }
        free(s);
    }
}