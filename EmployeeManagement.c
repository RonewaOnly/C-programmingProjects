#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Creating a structure of Employee
struct employee
{
    /* data */
    char name[45];
    long int code;
    char designation[90];
    int exp;
    int age;
};
int num;
const int max =200;
void showMenu();

//An array of Employee to store the data in the form of the Structure
//of the Array
struct employee emp[230]; 

//A function for the given datatype
void build(){
    printf("Build The Table: \n");
    printf("Maximum Entries can be: %d",num);
    printf("Enter the number of entries required: ");
    scanf("%d",num);

    if(num > 20){
        printf("Maximum number of Entries are 20\n");
        num = 20;
    }
    printf("Enter the following data: \n");

    for(int i =0;i < num;i++){
        printf("Name: ");
        scanf("%s",emp[i].name);
        printf("Employee ID: ");
        scanf("%d",emp[i].code);
        printf("Designation: ");
        scanf("%s",emp[i].designation);
        printf("Experience:  ");
        scanf("%d",&emp[i].exp);
        printf("Age");
        scanf("%d",&emp[i].age);
    }
    showMenu();
}

//A function to insert the data into given data type
void insert() {
    if(num < max){
        int i = num;
        num++;

        printf("Enter the information of the Employee Name: \n");
        scanf("%s",emp[i].name);
        printf("Enter Employee ID: \n");
        scanf("%d",emp[i].code);
        printf("Enter the Designation: \n");
        scanf("%s",emp[i].designation);
        printf("Enter Employee Experience: \n");
        scanf("%d", &emp[i].exp);
        printf("Enter Employee Age: \n");
        scanf("%d", &emp[i].age);
    }else{
        printf("\nNo Space left in Database.\n");
    }
    showMenu();
}
//A function to delete a record at the index
void deleteIndex(int i){
    for (int j = i; j < num - 1; j++) {
        emp[j] = emp[j + 1];

        /*emp[j].name = emp[j + 1].name;
        emp[j].code = emp[j + 1].code;
        emp[j].designation= emp[j + 1].designation;
        emp[j].exp = emp[j + 1].exp;
        emp[j].age = emp[j + 1].age;*/
    }
}

//Function to delete a record
void deleteRecord(){
    printf("Enter the Employee ID to delete record: \n");
    int code;
    scanf("%d",&code);
    for(int i =0; i < num; i++){
        if(emp[i].code == code){
            deleteIndex(i);
            num--;
            break;
        }

    }
    showMenu();
}
void searchRecord(){
    printf("Enter the Employee ID to search record: ");
    int code;
    scanf("%d",code);

    for(int i =0; i < num;i++){
        //when data is found
        if(emp[i].code == code){
            printf("Name: %s\t",emp[i].name,"\n");
            printf("Employee ID: %d\n",emp[i].code);
            printf("Designation: %d\n",emp[i].designation);
            printf("Experience in Years: %.2f\n",emp[i].exp);
            printf("Age: %d\n",emp[i].age);
            break;
        }
    }
    showMenu();
}

//The Menu function
void showMenu() {
    printf("----------------------\n"
            "Employee\n"
            "Management System\n"
            "----------------------\n"
    );
    printf("\nAvailable Options: \n"
            "1. Build Table.\n"
            "2. Insert New Entry.\n"
            "3. Delete Entry.\n"
            "4. Search a Record.\n"
            "5. Exit.\n"
    );
    int option;

    printf("Enter your choice: \t");
    scanf("%d",option);

    switch (option)
    {
    case 1:
        build();
        break;
    case 2: 
        insert();
        break;
    case 3:
        deleteRecord();
        break;
    case 4:
        searchRecord();
    case 5:
        exit(0);

    default:
        printf("Expected Options: 1/2/3/4/5");
        showMenu();
    }
}

//Main function to run the program
int main(){
    showMenu();
    return 0;
}
