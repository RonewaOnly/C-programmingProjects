//imports
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to implement the game
int game(char user, char computer){
    //When the user and computer have chosen the same thing choice.
    if(user == computer)
        return -1;

    //when the user chooses 'stone' and
    //computer chooses 'paper'
    if(user == 's' && computer == 'p')
        return 0;
        //when user chooses 'paper' and
        //computer chooses 'stone'
        else if(user == 'p' && computer == 's') return 1;

    //when user chooses 'stone' and
    //computer chooses is 'scissor'
    if(user == 's' && computer == 'z')
        return 1;

    //when user chooses 'stone' and
    //computer chooses 'scisstor'
    else if(user == 'z' && computer == 's')
        return 0;

    //when user chooses 'paper' and
    //computer chooses 'scissor'
    if(user == 'p' && computer == 'z')
        return 0;

    else if (user == 'z' && computer =='p')
        return 1;
}

//Main function
int main()
{
    //Stores the random numbers
    int n;

    char user,computer,results;


    //chooses the random number every time
    srand(time(NULL));

    //Making the random number less
    //than 100,divided it by 100
    n = rand() % 100;

    //using simple probability 100 is
    //roughly divided amoung stone,
    //paper,and scissor
    if(n < 33)
        //s is denoting Stone
        computer = 's';

    else if(n > 33 && n < 66)
        // p is denoting Paper
        computer = 'p';
    //z is denoting Scissor
    else
        computer = 'z';

    printf("\n\n\n\n\t\t\t\tEnter s for STONE,p for PAPER and z for Scissor\n\t\t\t\t\t\t\t");

    //asking for input from the user
    scanf("%c", &user);

    //calling Function to  start to play the game
    results = game(user,computer);

    if(results == -1){
        printf("\n\n\t\t\t\tGame Draw!\n");
    }else if(results == 1){
        printf("\n\n\t\t\t\tWow! You have won the game!\n");
    }else{
        printf("\n\n\t\t\t\tOh! You have lost the game!\n");
    }
        printf("\t\t\t\tYou choose: %c and Computer choose: %c\n",user,computer);
    return 0;
} 
