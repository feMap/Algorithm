/*二叉树的二叉链表结点结构定义*/
typedef struct BiTNode
{
    int data;
    int bf;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

/*对p为根的二叉树进行右旋处理*/
void R_Rotate(BiTree *P)
{
    BiTree L;
    L = (*P)->lchild;
    (*P)->lchild = L->rchild;
    L->rchild = (*P);
    *P = L;
}

/*对p为根的二叉树进行左旋处理*/
void L_Rotate(BiTree *P)
{
    BiTree R;
    R = (*P)->rchild;
    (*P)->rchild = R->lchild;
    R->lchild = (*P);
    *P = R;
}

/*左平衡旋转处理*/
#define LH +1 /*左高*/
#define EH 0 /*等高*/
#define RH -1 /*右高*/
/*对指针T所指结点为根的二叉树做左平衡旋转处理*/
/*本算法结束时，指针T指向新的根节点*/
void LeftBalance(BiTree *T)
{
    BiTree L, Lr;
    L = (*T)->lchild;
    // Lr = L->rchild;
    // 关键的难点在于这个bf参数的判断和改变，真的是很难理解清楚
    switch(L->bf)
    {
        case LH:
            (*T)->bf = L->bf = EH;
            R_Rotate(T);
            break;

        case RH:
            Lr = L->rchild;
            switch(Lr->bf)
            {
                case LH:
                    (*T)->bf = RH;
                    L->bf = EH;
                    break;

                case EH:
                    (*T)->bf = L->bf=EH;
                    break;

                case RH:
                    (*T)->bf = EH;
                    L->bf = LH;
                    break;
            }
            Lr->bf = EH;
            L_Rotate(&(*T)->lchild);
            R_Rotate(T);
    }

}


Status InsertAVL(BiTree *T, int e, Status *taller)
{

}