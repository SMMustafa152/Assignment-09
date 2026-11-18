#include <stdio.h>
int totalCalories(int n){
    if(n==0) return 0;
    return (n*5)+totalCalories(n-1);
}

int main(){
    int n;
    printf("enter the number of steps:\n");
    scanf("%d",&n);
    
    printf("total calories burned:%d",totalCalories(n));


return 0;
}