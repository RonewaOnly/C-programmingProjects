#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Creating a structure for a Library
struct library
{
    /* data */
    char book_name[120];
    char author[90];
    int pages;
    float price;
};

//Main function
int main() {
    //creating a instance of the library struct
    struct library lib[100];

    char ar_nam[30],bk_num[30];

    //Keep the track of the number of books available in the library
    int i,input,count;

    i = input = count = 0;

    while(input != 5){
        printf("\n\n******* Welcome to the Library *******\n");
        printf("\n\n1. Add book information. \n");
        printf("\n\n2. Display book information. \n");
        printf("\n\n3. List all books of given author. \n");
        printf("\n\n4. List the count of books in the library.\n \n");
        printf("\n\n5. Exit");

        printf("\n\nEnter one of the above: ");
        scanf("%d",&input);

        switch (input)
        {
         //Add books
        case 1:
            printf("Enter book name:- ");
            scanf("%s",lib[i].book_name);

            printf("Enter author name:- ");
            scanf("%s",lib[i].author);

            printf("Enter pages:- ");
            scanf("%d",&lib[i].pages);

            printf("Enter price:- ");
            scanf("%f", &lib[i].price);
            count++;

            break;

        //Printing book information
        case 2:
            printf("You have entered the following information: \n");
            for(i =0;i < count;i++){
                printf("Book name:- %s",lib[i].book_name);
                printf("\nAuthor:- %s", lib[i].author);
                printf("\nPages:- %d", lib[i].pages);
                printf("\nPrice:- R%.2f\n", lib[i].price);
            }
            break;

        //Taking the author name as input
        case 3:
            printf("Enter author name: ");
            scanf("%s",ar_nam);
            for(i =0; i<count;i++){
                if(strcmp(ar_nam,lib[i].author) == 0){
                    printf("%s %s %d %f",lib[i].book_name,
                            lib[i].author,
                            lib[i].pages,
                            lib[i].price);
                }
            }
            break;

        //Printing total count
        case 4:
            printf("\n No of books in library: %d",count);
            break;

        case 5:
            exit(0);
        }
    }
    return 0;
}