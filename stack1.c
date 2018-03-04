//回文数
#include <stdio.h>
#include <string.h>

int main(){
    char a[101],s[101];
    int i,len,mid,next,top;

    gets(a);
    len = strlen(a);
    mid = len/2 - 1;

    //这里的mid值是以字符串的序号为参考，包含0点，但是在栈中缺失从1开始的
    //printf("%d", mid);

    top = 0;
    for(i=0;i<=mid;i++)
        s[++top] = a[i];

    if(len%2 == 0)
        next = mid+1;
    else
        next = mid+2;

    for(i=next;i<=len-1;i++)
    {
        if(a[i] != s[top])
            break;
        top--;
    }

    if(top == 0)
        printf("YES");
    else
        printf("NO");

    getchar();getchar();
    return 0;
}