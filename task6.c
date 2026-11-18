
#include <stdio.h>
int function(int index, int vehicles, int remaining, int exitChoice[]){
    if (index == vehicles)
    {
        return remaining;
    }
    if (exitChoice[index] == 1)
    {
        remaining--;

        printf("Vehicle %d exited.\n", index + 1);
        printf("Remaining Vehicles: %d\n", remaining);
    }
    return function(index + 1, vehicles, remaining, exitChoice);
}

int main(){
    int vehicles;
    int exitChoice[100];
    int remaining;
    int totalexit;

    printf("Enter the number of vehicles:\n");
    scanf("%d", &vehicles);

    for (int i = 0; i < vehicles; i++){
        printf("Vehicle %d: Press 1 for exit, 0 for stay:\n", i + 1);
        scanf("%d", &exitChoice[i]);
    }
    remaining = function(0, vehicles, vehicles, exitChoice);

    totalexit = vehicles - remaining;

    printf("\nTotal Exited Vehicles: %d", totalexit);
    printf("\nRemaining Vehicles: %d", remaining);

    if (remaining == 0){
        printf("\nParking area is empty.");
    }
    else{
        printf("\nParking area is not empty.");
    }

    return 0;
}
