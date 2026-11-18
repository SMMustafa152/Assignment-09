#include <stdio.h>
typedef struct employee{
    int id;
    char name[30];
    float salary;
}employee;
    
   employee arr[3];


int main(){
    int i=0;
    
    while(i<3){
       
     printf("\nEnter the ID:");
     scanf("%d",&arr[i].id);
     printf("\nEnter name:");
     scanf(" %29[^\n]",&arr[i].name);
     printf("\nEnter salary:");
     scanf("%f",&arr[i].salary);
        
     if(arr[i].salary <50000){
        arr[i].salary+=arr[i].salary*0.10;
     }
     i++;
    }
    printf("\n---Updated Salaries---\n");
    for(i=0;i<3;i++){
        printf("%-3d %-14s %.2f\n",arr[i].id,arr[i].name,arr[i].salary );
    }
    
    



return 0;
}