#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define TURNS 10
#define TRIALS 4

FILE *theFile;
FILE *theOtherFile;

char playerOne[10];
char playerAI[] = "Al";

char scoreOne;
char scoreTwo;

int sumOne = 0;
int sumTwo = 0;

char scores[10];

void game(int numberOfTurns)
{

    if (numberOfTurns > 0)
    {
        printf("%s, choose C or D \n", playerOne);
        scanf("%s", &scoreOne);
        scores[TURNS - numberOfTurns] = scoreOne;
        printf("\n");
        system("cls");

        if (numberOfTurns == TURNS)
        {
            scoreTwo = 'C';
            printf("Al chose C. \n");
        }
        else
        {
            scoreTwo = scores[TURNS - (numberOfTurns + 1)];
            printf("Al chose %c. \n", scores[TURNS - (numberOfTurns + 1)]);
        }


        if (((scoreOne == 'C') || (scoreOne == 'c')) && ((scoreTwo == 'C') || (scoreTwo == 'c')))
        {
            fprintf(theFile, "%d \n", 3);
            fprintf(theOtherFile, "%d \n", 3);
            printf("%s gets %d, %s gets %d. \n", playerOne, 3, playerAI, 3);
            printf("\n\n\n\n\n\n\n\n");
            sumOne = sumOne + 3;
            sumTwo = sumTwo + 3;
        }


        else if (((scoreOne == 'C')||(scoreOne == 'c')) && ((scoreTwo == 'd')||(scoreTwo == 'D')))
        {
            fprintf(theFile, "%d \n", 0);
            fprintf(theOtherFile, "%d \n", 5);
            printf("%s gets %d, %s gets %d. \n", playerOne, 0, playerAI, 5);
            printf("\n\n\n\n\n\n\n\n");
            sumOne = sumOne + 0;
            sumTwo = sumTwo + 5;
        }

        else if (((scoreTwo == 'c') || (scoreTwo == 'C')) && ((scoreOne == 'd')||(scoreOne == 'D')))
        {
            fprintf(theFile, "%d \n", 5);
            fprintf(theOtherFile, "%d \n", 0);
            printf("%s gets %d, %s gets %d. \n", playerOne, 5, playerAI, 0);
            printf("\n\n\n\n\n\n\n\n");
            sumOne = sumOne + 5;
            sumTwo = sumTwo + 0;
        }

        else if (((scoreOne == 'd')||(scoreOne == 'D')) && ((scoreTwo == 'd')||(scoreTwo == 'D')))
        {
            fprintf(theFile, "%d \n", 1);
            fprintf(theOtherFile, "%d \n", 1);
            printf("%s gets %d, %s gets %d. \n", playerOne, 1, playerAI, 1);
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
            printf("%s got %d points. \n", playerAI, sumTwo);
        }

        else if (sumTwo > sumOne)
        {
            printf("Looks like %s wins with %d points!\n", playerAI, sumTwo);
            printf("%s, you get %d points.\n", playerOne, sumOne);
        }

        else
        {
        printf("It's a tie. Good game. \n");
        printf("You both got %d.\n", sumOne);
        }
    }

}


 /*   char endEnter
    scanf("%c", &endEnter);
    if (endEnter != '\n')
    {

    } */

int main()
{
 //   printf("Welcome to the nooks and crannies of CS110.\n");
    printf("You and this other person have come across a stash of 60 dollars.\n");
    printf("Unfortunately, COW security has claimed it.\n");
    printf("HOWEVER, they're willing to cut a deal!\n");
    printf("You get to keep it if you play a game.\n");
    printf("The game allows you to split the money between the two of you.\n\n");
    printf("Try to get as much money as possible!\n");
    printf("The game will go for ten turns.\n");
    printf("Each turn, you get to choose two options.\n");
    printf("Each of you can choose to cooperate with the other (C).\n");
    printf("Or defect (D).\n\n");
    printf("If you both choose D, you each get 1 dollar.\n");
    printf("If you both choose C, you each get 3 dollars.\n\n");
    printf("However, if you choose C and the other guy chooses D,\nyou get 0 and he gets 5.\n\n");
    printf("But the other way is also true.\nIf you choose D and the other guy chooses C, you get 5 and he gets 0.\n");
    printf("Let's begin.\n\n");
    printf("When ready, press enter.\n");

    char enter;
    scanf("%c", &enter);
    if (enter == '\n')
    {
        system("cls");
    }

    printf("Enter your name \n");
    scanf("%s", &playerOne);
    printf("\n\n\n\n\n\n");



    if ((theFile = fopen(playerOne, "r+")) == NULL)
    {
        theFile = fopen(playerOne, "w");
        fprintf(theFile, "--%s--\n\n", playerOne);
    }
    else
    {
        theFile = fopen(playerOne, "a");
    }
    fprintf(theFile, "vs. %s\n", playerAI);


    if ((theOtherFile = fopen(playerAI, "r+"))  == NULL)
    {
        theOtherFile = fopen(playerAI, "w");
        fprintf(theOtherFile, "--%s--\n\n", playerAI);
    }
    else
    {
        theOtherFile = fopen(playerAI, "a");
    }
    fprintf(theOtherFile, "vs. %s\n", playerOne);

    game(TURNS);

    fclose(theFile);
    fclose(theOtherFile);


}



