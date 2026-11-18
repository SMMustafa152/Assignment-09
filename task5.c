#include <stdio.h>
float Caltotal(int products,float prices[]){
    if(products==0)  return 0;
    float sum=Caltotal(products-1,prices)+prices[products-1];
    return sum;
}
int main(){
    float prices[100];
    int products;
    printf("enter no of product:\n");
    scanf("%d",&products);

    for (int i=0;i<products;i++){
        printf("Product %d:",i+1);
        scanf("%f",&prices[i]);
    }
    float total;
    total=Caltotal(products,prices);

    float avg;
    avg=total/products;

    printf("\nTotal cost: Rs. %.2f", total);
    printf("\nAverage price: Rs. %.2f", avg);


return 0;
}