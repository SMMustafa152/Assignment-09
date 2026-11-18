#include <stdio.h>
int main(){
    FILE *fp;
    int choice, id, search, found;
    char title[50], author[30];

    do{
        printf("\n1. Add book\n2. Display books\n3. Search by ID\n4. Delete file\n0. Exit\nChoice: ");
        scanf("%d", &choice);

        if(choice==1){
            fp = fopen("library.txt", "a");
            printf("Book ID: ");
            scanf("%d", &id);
            printf("Book title: ");
            scanf(" %49[^\n]", title);
            printf("Author name: ");
            scanf(" %29[^\n]", author);
            fprintf(fp, "%d|%s|%s\n", id, title, author);
            fclose(fp);
        }
        else if(choice==2){
            fp = fopen("library.txt", "r");
            if(fp==NULL){
                printf("no records found\n");
            }else{
                while(fscanf(fp, "%d|%49[^|]|%29[^\n]", &id, title, author)==3){
                    printf("ID: %d  Title: %s  Author: %s\n", id, title, author);
                }
                fclose(fp);
            }
        }
        else if(choice==3){
            fp = fopen("library.txt", "r");
            if(fp==NULL){
                printf("No records found.\n");
            }else{
                printf("enter id to search a book:\n");
                scanf("%d", &search);
                found = 0;
                while(fscanf(fp, "%d|%49[^|]|%29[^\n]", &id, title, author)==3){
                    if(id==search){
                        printf("Found! ID: %d  Title: %s  Author: %s\n", id, title, author);
                        found = 1;
                    }
                }
                if(found==0){
                    printf("book not found.\n");
                }
                fclose(fp);
            }
        }
        else if(choice==4){
            if(remove("library.txt")==0){
                printf("file deleted.\n");
            }else{
                printf("no file to delete.\n");
            }
        }
    }while(choice!=0);

    return 0;
}