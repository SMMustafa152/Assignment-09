#include <stdio.h>
struct Book{
    int id;
    char title[50];
    float price;
};

struct Book arr[3];


int main(){
    int maxindex=0;
    for(int i=0;i<3;i++){
        printf("enter id:\n");
        scanf("%d",&arr[i].id);
        printf("enter title:\n");
       scanf(" %49[^\n]",arr[i].title);
        printf("enter price:\n");
        scanf("%f",&arr[i].price);

        if(i==0 || arr[i].price > arr[maxindex].price){
            maxindex=i;
        }
    }
    printf("\n---Book List---\n");


        printf("ID   TIttle            Price");
        printf("\n");
        for(int j=0;j<3;j++){
            printf("%-3d %-20s Rs.%.2f\n",arr[j].id,arr[j].title,arr[j].price);
            
        }
        printf("\n Most expensive:%s (Rs. %.2f)\n",arr[maxindex].title,arr[maxindex].price);

    


return 0;
}