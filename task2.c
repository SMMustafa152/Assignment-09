#include <stdio.h>
long reverseDigit(long n){
    if(n==0) return 0;
    printf("%ld",n%10);
    return reverseDigit(n/10);
}

int main(){
    long n;
    printf("Enter number:\n");
    scanf("%ld",&n);
    
    reverseDigit(n);
    return 0;
}
