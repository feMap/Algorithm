#include <algorithm>
using namespace std;

struct node
{
    int v, height;
    node *lchild, *rchild;
};

// 生成一个新的节点，v为结点权值
node* newNode(int v)
{
    node* Node = new node;
    Node->v = v;
    Node->height = 1;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

int getHeight(node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    return root->height;
}

int getBalanceFactor(node* root)
{
    // 左树高度减去右树高度
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(node* root)
{
    root->height = max(getHeight(root->lchild), getHeight(root->rchild));
}

void search(node* root, int x)
{
    if(root == NULL)
    {
        printf("Search failed.\n");
        return;
    }

    if(x == root->data)
    {
        printf("%d\n", root->data);
    }
    else if(x < root->data)
    {
        search(root->lchild, x);
    }
    else
    {
        search(root->rchild, x);
    }
}

void L(node* &root)
{
    node* temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;

    updateHeight(root);
    updateHeight(temp);

    root = temp;
}

void R(node* &root)
{
    node* temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    getHeight(root);
    getHeight(temp);
    root = temp;
}

void insert(node* &root, int v)
{
    if(root == NULL)
    {
        root = newNode(v);
        return;
    }

    if(v < root->v)
    {
        insert(root->lchild, v);
        updateHeight(root);
        if(getBalanceFactor(root) == 2)
        {
            if(getBalanceFactor(root->lchild) == 1)
            {
                R(root);
            }
            else if(getBalanceFactor(root->rchild) == -1)
            {
                R(root->lchild);
                L(root);
            }
        }
        else
        {
            if(getBalanceFactor(root->lchild) == 1)
            {
                R(root->rchild);
                L(root);
            }
            else if(getBalanceFactor(root->rchild) == -1)
            {
                L(root);
            }
        }
    }

}


// AVL树的建立
node* Create(int data[], int n)
{
    node* root = NULL;
    for(int i = 0; i < n; i++)
    {
        insert(root, data[i]);
    }
    return root;
}