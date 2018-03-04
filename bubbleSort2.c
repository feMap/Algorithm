#include <stdio.h>

struct student
{
    char name[12];
    int score;
};

int main(){
    struct student a[100], t;
    int i,j,n;
    scanf("%d", &n);

    for(i=1;i<=n;i++){
        scanf("%s %d", a[i].name, &a[i].score);
    }

    for(i=1;i<n;i++){
        for(j=1;j<=n-i;j++){
            if(a[j].score > a[j+1].score){
                t = a[j]; a[j]=a[j+1]; a[j+1] = t;
            }
        }
    }

    for(i=1;i<=n;i++){
        printf("%s %d\n", a[i].name, a[i].score);
    }

    getchar();getchar();
    return 0;
}