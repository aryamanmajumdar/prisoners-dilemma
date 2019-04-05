#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define TURNS 10
#define TRIALS 4

FILE *theFile;
FILE *theOtherFile;

char playerOne[10];
char playerTwo[10];

char scoreOne;
char scoreTwo;

int sumOne = 0;
int sumTwo = 0;

void game(int numberOfTurns)
{

    if (numberOfTurns > 0)
    {
        printf("%s, choose C or D \n", playerOne);
        scanf("%s", &scoreOne);
        printf("\n");
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n");


        printf("%s, choose C or D \n", playerTwo);
        scanf("%s", &scoreTwo);
        printf("\n");
        system("cls");


        if (((scoreOne == 'C') || (scoreOne == 'c')) && ((scoreTwo == 'C') || (scoreTwo == 'c')))
        {
            fprintf(theFile, "%d \n", 3);
            fprintf(theOtherFile, "%d \n", 3);
            printf("%s gets %d, %s gets %d. \n", playerOne, 3, playerTwo, 3);
            printf("\n\n\n\n\n\n\n\n");
            sumOne = sumOne + 3;
            sumTwo = sumTwo + 3;
        }


        else if (((scoreOne == 'C')||(scoreOne == 'c')) && ((scoreTwo == 'd')||(scoreTwo == 'D')))
        {
            fprintf(theFile, "%d \n", 0);
            fprintf(theOtherFile, "%d \n", 5);
            printf("%s gets %d, %s gets %d. \n", playerOne, 0, playerTwo, 5);
            printf("\n\n\n\n\n\n\n\n");
            sumOne = sumOne + 0;
            sumTwo = sumTwo + 5;
        }

        else if (((scoreTwo == 'c') || (scoreTwo == 'C')) && ((scoreOne == 'd')||(scoreOne == 'D')))
        {
            fprintf(theFile, "%d \n", 5);
            fprintf(theOtherFile, "%d \n", 0);
            printf("%s gets %d, %s gets %d. \n", playerOne, 5, playerTwo, 0);
            printf("\n\n\n\n\n\n\n\n");
            sumOne = sumOne + 5;
            sumTwo = sumTwo + 0;
        }

        else if (((scoreOne == 'd')||(scoreOne == 'D')) && ((scoreTwo == 'd')||(scoreTwo == 'D')))
        {
            fprintf(theFile, "%d \n", 1);
            fprintf(theOtherFile, "%d \n", 1);
            printf("%s gets %d, %s gets %d. \n", playerOne, 1, playerTwo, 1);
            printf("\n\n\n\n\n\n\n\n");
            sumOne = sumOne + 1;
            sumTwo = sumTwo + 1;
        }

        else
        {
            printf("That's not an option, unfortunately. \n");
            printf("\n\n\n\n\n\n\n\n");
            game(numberOfTurns);
        }

        game(numberOfTurns - 1);
    }
    else
    {
        if (sumOne > sumTwo)
        {
            printf("%s, you win! You got %d points. \n", playerOne, sumOne);
            printf("%s, you get %d points.", playerTwo, sumTwo);
        }

        else if (sumTwo > sumOne)
        {
            printf("%s, you win! You got %d points. \n", playerTwo, sumTwo);
            printf("%s, you get %d points.", playerOne, sumOne);
        }

        else printf("It's a tie. You guys aren't much fun. \n");
    }


}


 /*   char endEnter
    scanf("%c", &endEnter);
    if (endEnter != '\n')
    {

    } */

int main()
{
    printf("Welcome to the nooks and crannies of CS110.\n");
    printf("You and this other person have come across a stash of 60 dollars.\n");
    printf("Unfortunately, COW security has claimed it.\n");
    printf("HOWEVER, they're willing to cut a deal!\n");
    printf("You get to keep it if you play a game.\n");
    printf("The game allows you to split the money between the two of you.\n\n");
    printf("The game will go for ten turns.\n");
    printf("Each turn, you get to choose two options.\n");
    printf("Each of you can choose to cooperate with the other (C).\n");
    printf("Or defect (D).\n\n");
    printf("If you both choose D, you each get 2 dollars.\n");
    printf("If you both choose C, you each get 3 dollars.\n\n");
    printf("However, if you choose C and the other guy chooses D,\nyou get 1 and he gets 4.\n\n");
    printf("But the other way is also true.\nIf you choose D and the other guy chooses C, you get 4 and he gets 1.\n");
    printf("Let's begin.\n\n");
    printf("When ready, press enter.\n");

    char enter;
    scanf("%c", &enter);
    if (enter == '\n')
    {
        system("cls");
    }

    printf("Enter player 1's name \n");
    scanf("%s", &playerOne);
    printf("\n");


    printf("Enter player 2's name \n");
    scanf("%s", &playerTwo);
    printf("\n\n\n\n");


    int i = 0;
    while ((((playerOne + i)*) != '\0') || (((playerTwo + i)*) != '\0'))
    {
        i++;
    }
    if (((playerOne + i)* == '\0') && ((playerTwo + i)* == '\0'))
    {
        if (for (int x = 0; x < i; x++)
            {
                (playerOne + i)* == (playerTwo + i)*;

            })
        {
            strcat(playerOne, "A");
            strcat(playerTwo, "B");
        }

    }

    if (playerOne == playerTwo)
    {
        char suffixA[5];
        char suffixB[5];
        strcpy(suffixA, "A");
        strcpy(suffixB, "B");
        strcat(playerOne, suffixA);
        strcat(playerTwo, suffixB);
    }
    printf("%s \n %s \n", playerOne, playerTwo);
    if ((theFile = fopen(playerOne, "r+")) == NULL)
    {
        theFile = fopen(playerOne, "w");
        fprintf(theFile, "--%s--\n\n", playerOne);
    }
    else
    {
        theFile = fopen(playerOne, "a");
    }
    fprintf(theFile, "vs. %s\n", playerTwo);


    if ((theOtherFile = fopen(playerTwo, "r+"))  == NULL)
    {
        theOtherFile = fopen(playerTwo, "w");
        fprintf(theOtherFile, "--%s--\n\n", playerTwo);
    }
    else
    {
        theOtherFile = fopen(playerTwo, "a");
    }
    fprintf(theOtherFile, "vs. %s\n", playerOne);

    game(TURNS);

    fclose(theFile);
    fclose(theOtherFile);


}



