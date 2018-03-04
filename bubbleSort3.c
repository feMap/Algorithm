//书ISBN
#include <stdio.h>
int main(){
    int a[101],n,i,j,t;
    scanf("%d", &n);
    for(i=1;i<=n;i++)
        scanf("%d", &a[i]);

    for(i=1;i<n;i++){
        for(j=1;j<=n-i;j++){
            if(a[j]>a[j+1]){
                t = a[j]; a[j] = a[j+1]; a[j+1] = t;
            }
        }
    }

    printf("%d", a[1]);

    for(i=2;i<=n;i++){
        if(a[i-1] != a[i])
            printf(" %d", a[i]);
    }

    getchar();getchar();
    return 0;
}