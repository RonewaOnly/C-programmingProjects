#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//This variable keeps track of number of the students
int i =0;

//Structure to store the student
struct studentinfo{
    char fname[50];
    char lname[50];
    int roll;
    float cgpa;
    int cid[10];
}st[55];

//The function to add the students

void add_student(){
    printf("Add the Student's Details\n");
    printf("---------------------------\n");
    printf("Enter the firstname of student: \n");
    scanf("%s",&st[i].fname);
    printf("Enter the lastname of studnet:\n");
    scanf("%s",&st[i].lname);
    printf("Enter the Roll Number of student:\n");
    scanf("%d",&st[i].roll);
    printf("Enter the CGPA you obtained\n");
    scanf("%f",&st[i].cgpa);
    printf("Enter the course ID of each course: \n");
    for(int j =0; j < 5;j++){
        scanf("%d",&st[i].cid[j]);
    }
    i = i + 1;
}

//This function finds the student by the roll number
void find_rl(){
    int x;
    printf("Enter the roll number of the student: \n");
    scanf("%d", &x);

    for(int j =1; j <= i;j++){
        if(x == st[i].roll){
            printf("The Students Details are: \n");
            printf("The Firstname is %s\n",st[i].fname);
            printf("The Lastname is %s\n",st[i].lname);
            printf("The CGPA is %f\n",st[i].cgpa);
            printf("Enter the course ID of each course\n");
        }
        for(int j =0; j < 5;j++){
            printf("The course ID are %d\n",st[i].cid[j]);
        }
        break;
    }
}
//This function finds the student by the firstname
void find_fn(){
    char a[50];
    printf("Enter the Firstname of the student: \n");
    scanf("%s",a);
    int c = 0;

    for(int j =1;j <= i;j++){
        if(!strcmp(st[j].fname,a)){
            printf("The Students Details are: \n");
            printf("The Firstname is :%s\n",st[i].fname);
            printf("The Lastname is :%s\n",st[i].lname);
            printf("The roll number is :%d",st[i].roll);
            printf("The CGPA is: %f\n",st[i].cgpa);
            printf("Enter the course ID of each course: \n");

            for(int j =0; j < 5; j++){
                printf("The course ID are: %d\n",st[i].cid[j]);
            }
            c = 1;
        }
        else    
            printf("The Firstname not Found\n");
    }
}

//This function finds the students enrolled in a particular course
void find_c(){
    int id;
    printf("Enter the course ID: \n");
    scanf("%d",&id);
    int c = 0;

    for(int j = 1;j <=i;j++){
        for(int d =0; d< 5;d++){
            if(id == st[j].cid[d]){
                printf("The Students Details are: \n");
                printf("The firstname is: %s\n",st[i].fname);
                printf("The lastname is: %s\n",st[i].lname);
                printf("Roll Number:%d\n",st[j].roll);
                printf("The CGPA is: %f\n",st[i].cgpa);

                c = 1;
                break;
            }
            else
                printf("The firstname not found\n");
        }
    }   
}
// Function to print the total
// number of students
void tot_s()
{
    printf("The total number of Student is %d\n",i);
    printf("\n you can have a max of 50 students\n");
    printf("you can have %d more students\n",50 - i);
}
//This function is used to delete a student by the roll number
void del_s(){
    int a;
    printf("Enter the Roll number which you want to delete: \n");
    scanf("%d",&a);
    for(int j =1; j <=1; j++){
        if(a == st[j].roll){
            for(int k = j;k < 49;k++)
                st[k] = st[k+1];
            i--;
            
        }
    }
    printf("The Roll Number is removed Successfully.\n");
}
//This function is used to update a students data
void up_s(){
    printf("Enter the roll number to update the entry: ");
    long int x;
    scanf("%ld", &x);
    for(int j =0;j<i;j++){
        if(st[j].roll == x){
            printf("1. Firstname\n"
                    "2. Lastname\n"
                    "3. roll no\n"
                    "4. CGPA\n"
                    "5. course\n"
                    );
            int z;
            scanf("%d",&z);
            switch (z) {
            case 1:
                printf("Enter the new firstname: \n");
                scanf("%s",st[j].fname);
                break;
            case 2:
                printf("Enter the new lastname: \n");
                scanf("%s",st[j].lname);
                break;
            case 3:
                printf("Enter the new roll number: \n");
                scanf("%d",&st[j].roll);
                break;
            case 4:
                printf("Enter the new CGPA: \n");
                scanf("%f",&st[j].cgpa);
                break;
            case 5:
                printf("Enter the new course: \n");
                scanf("%d%d%d%d%d",&st[j].cid[0],
                &st[j].cid[1],
                &st[j].cid[2],
                &st[j].cid[3],
                &st[j].cid[4]);
                break;
            }
            printf("Updated successfully");
        }
    }
}

//Main function
int main(){
    int choice,count;
    while(i = 1){
        printf("The Task that you want to perform\n");
        printf("1. Add the Student Details\n");
        printf("2. Find the Student Details by roll number\n");
        printf("3. Find the Student Details by firstname\n");
        printf("4. Find the Student Details by Course Id\n");
        printf("5. Find the Total number of Students\n");
        printf("6. Delete the Students Details by Roll Number\n");
        printf("7. Update the Students Details by Roll Number\n");
        printf("8. To Exit\n");
        printf("Enter your choice to find the task:\n");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            add_student();
            break;
        case 2:
            find_rl();
            break;
        case 3:
            find_fn();
            break;
        case 4:
            find_c();
            break;
        case 5:
            tot_s();
            break;
        case 6:
            del_s();
            break;
        case 7:
            up_s();
            break;
        case 8:
            exit(0);
            break;
        }
    }
}