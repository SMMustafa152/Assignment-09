#include <stdio.h>
int main(){
    FILE *fp;
    char name[50],status[15],line[100];
    int rollno,i,n,choice;
    do{
        printf("1.enter records\n2.Display records\n3.delete file\n0.exit\nchoice:\n");
        scanf("%d",&choice);
        if(choice==1){
            fp=fopen("attendance.txt","a");
            printf("how many students?\n:");
            scanf("%d",&n);
            
            for(i=0 ;i<n; i++){
                printf("Roll number, name , attendance status:");
                scanf("%d %s %s",&rollno,&name,&status);
                fprintf(fp,"%d %s %s\n",rollno,name,status);
            }
            fclose(fp);
        }
        else if(choice==2){
            fp=fopen("attendance.txt","r");
            if(fp==NULL){
                printf("No records found.\n");
            }else{
                while(fgets(line,sizeof(line),fp)!=NULL){
                    printf("%s",line);
                }
                fclose(fp);
            }
        
        }else if(choice==3){
            if(remove("attendance.txt")==0){
                printf("file deleted\n");
            }else{
                printf("no file to delete\n");
            }
        }
    }while(choice!=0);




        
        
        
return 0;
}