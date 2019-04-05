#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define TURNS 10    //The number of turns  the game will have.
#define TRIALS 4    //The number of trials, set for Part 3 (the experiment) but never really used so far.

/*---------------------------------------------------------------------------------
  ---------------------------------------------------------------------------------
  The Prisoner's Dilemma Program
  Aryaman Majumdar and Mirkamil Mijit,
  2nd May, 2016

  This program simulates the repetitive prisoner's dilemma,
  or in our case, the recursive prisoner's dilemma.

  There are essentially four constructed functions:
  gameMulti, which holds code for a game between two human players,
  gameAl, which is a game between a human player and our first computer player Al,
  gameHAL, which is a game between a human player and our second computer player HAL,
  choose, which lets the user choose between single- and multi-player and between
  Al and HAL.

  In main, we print the instructions to stdout and simply run the choose function.
  This allows the user to choose between gameMulti, gameAl and gameHAL.

  Unfortunately, the program is not Mac-compatible. This is because of use of
  the system function. We've indicated the points where we use it later
  in the code as well. Please try running it on a Windows machine.
  If that's any problem, we'll send you a modified version that works on a Mac as
  well.

  No existing code was used. Everything in this program was done by us.
  ---------------------------------------------------------------------------------
  -------------------------------------------------------------------------------*/

FILE *theFile;           //File to save player1's scores
FILE *theOtherFile;      //File to save either player2's or AI's scores

char playerOne[10];      //Char array to store player1's name
char playerTwo[10];      //Char array to store player2's name

char scoreOne;           //Variable to store score each player's score each turn
char scoreTwo;

int sumOne = 0;          //Variables for the sum of points of each player
int sumTwo = 0;

char scores[10];         //Array to store scores of player when playing against computer.

/*----------------------------------------------------------------
  The gameMulti function is for a game between two human players.
  It takes an input parameter numberOfTurns, which specifies the
  number of turns in the game.

  Our program inputs numberOfTurns == TURNS i.e. 10.

  The function uses a recursive method to run for the specified
  number of turns.
----------------------------------------------------------------*/
void gameMulti(int numberOfTurns)
{

/* The seed/termination for the recursion. */
    if (numberOfTurns > 0)
    {
        if (numberOfTurns == TURNS)
        {
/* If numberOfTurns == TURNS i.e.
   if it's the first turn,
   the function asks for the two players' names
   and saves them in the corresponding arrays. */

            printf("Enter player 1's name \n");
            scanf("%s", &playerOne);
            printf("\n");


            printf("Enter player 2's name \n");
            scanf("%s", &playerTwo);
            printf("\n\n\n\n");


/* Files to store the players' scores are made. */
            if ((theFile = fopen(playerOne, "r+")) == NULL)       //If playerOne's file doesn't exist, make it
            {
                theFile = fopen(playerOne, "w");
                fprintf(theFile, "--%s--\n\n", playerOne);
            }
            else
            {
                theFile = fopen(playerOne, "a");                  //If the file exists, append it.
            }
            fprintf(theFile, "vs. %s\n", playerTwo);


            if ((theOtherFile = fopen(playerTwo, "r+"))  == NULL) //If playerTwo's file doesn't exist, make it
            {
                theOtherFile = fopen(playerTwo, "w");
                fprintf(theOtherFile, "--%s--\n\n", playerTwo);
            }
            else                                                  //If the file exists, append it.
            {
                theOtherFile = fopen(playerTwo, "a");
            }
            fprintf(theOtherFile, "vs. %s\n", playerOne);
        }

/*We then prompt the players for their choices (C or D). */
        printf("%s, choose C or D \n", playerOne);
        scanf("%s", &scoreOne);
        printf("\n");
        system("cls");          //The system function to clear the terminal.
                                //IMP: This is why the program will not run on a Mac.
        printf("\n\n\n\n\n\n\n\n\n");


        printf("%s, choose C or D \n", playerTwo);
        scanf("%s", &scoreTwo);
        printf("\n");
        system("cls");          //Again, the system function to clear the terminal/
                                //This is why the program won't run on a Mac.


/*The points are allotted based on the players' choices.
  If both choose C, both get 3.
  If both choose D, both get 1.
  If one chooses C and the other D, they get 0 and 5 respectively.

  I made the if-statement such that the players would get their scores
  independent of the case of their input. Don't know why I didn't just use
  a library function. */
        if (((scoreOne == 'C') || (scoreOne == 'c')) && ((scoreTwo == 'C') || (scoreTwo == 'c')))
        {
            fprintf(theFile, "%d \n", 3);
            fprintf(theOtherFile, "%d \n", 3);
            printf("%s gets %d, %s gets %d. \n", playerOne, 3, playerTwo, 3);
            printf("\n\n\n\n\n\n\n\n");
            sumOne = sumOne + 3; //Each turn, points are added to sumOne to get playerOne's cumulative.
            sumTwo = sumTwo + 3; //sumTwo, which does the same for playerTwo.

            gameMulti(numberOfTurns - 1);
        }


        else if (((scoreOne == 'C')||(scoreOne == 'c')) && ((scoreTwo == 'd')||(scoreTwo == 'D')))
        {
            fprintf(theFile, "%d \n", 0);
            fprintf(theOtherFile, "%d \n", 5);
            printf("%s gets %d, %s gets %d. \n", playerOne, 0, playerTwo, 5);
            printf("\n\n\n\n\n\n\n\n");
            sumOne = sumOne + 0;
            sumTwo = sumTwo + 5;

            gameMulti(numberOfTurns - 1);
        }

        else if (((scoreTwo == 'c') || (scoreTwo == 'C')) && ((scoreOne == 'd')||(scoreOne == 'D')))
        {
            fprintf(theFile, "%d \n", 5);
            fprintf(theOtherFile, "%d \n", 0);
            printf("%s gets %d, %s gets %d. \n", playerOne, 5, playerTwo, 0);
            printf("\n\n\n\n\n\n\n\n");
            sumOne = sumOne + 5;
            sumTwo = sumTwo + 0;

            gameMulti(numberOfTurns - 1);
        }

        else if (((scoreOne == 'd')||(scoreOne == 'D')) && ((scoreTwo == 'd')||(scoreTwo == 'D')))
        {
            fprintf(theFile, "%d \n", 1);
            fprintf(theOtherFile, "%d \n", 1);
            printf("%s gets %d, %s gets %d. \n", playerOne, 1, playerTwo, 1);
            printf("\n\n\n\n\n\n\n\n");
            sumOne = sumOne + 1;
            sumTwo = sumTwo + 1;

            gameMulti(numberOfTurns - 1);
        }

        else
        {
            printf("That's not an option, unfortunately. \n");
            printf("\n\n\n\n\n\n\n\n");
            gameMulti(numberOfTurns);
        }

    }

/* Once numberOfTurns == 0, execute the following else-block,
   which prints statements declaring the winner based on the players'
   total scores. */
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

        else
        {
            printf("It's a tie. You guys aren't much fun. \n");
            printf("You both got %d.", sumOne);
        }
    }

    fclose(theFile);
    fclose(theOtherFile);
}

/*----------------------------------------------------------------
  The gameAl function is for a game between a human player
  and our first computer player, Al.
  It takes an input parameter numberOfTurns, which specifies the
  number of turns in the game.

  The function uses a recursive method to run for the specified
  number of turns. As before, we start with
  numberOfTurns == TURNS i.e. 10.
----------------------------------------------------------------*/
void gameAl(int numberOfTurns)
{
    char playerAI[] = "Al";  //Name the computer player Al

/* Set the seed/terminating value for the recursion. */
    if (numberOfTurns > 0)
    {

/* If it's the first turn, the player is prompted for their name,
   which is stored in a char array/string. */
        if (numberOfTurns == TURNS)
        {
            printf("Enter your name \n");
            scanf("%s", &playerOne);
            printf("\n\n\n\n\n\n");


/* Files are made for the player and Al to store their scores. */
            if ((theFile = fopen(playerOne, "r+")) == NULL)      //If the player's file doesn't exist, make it.
            {
                theFile = fopen(playerOne, "w");
                fprintf(theFile, "--%s--\n\n", playerOne);
            }
            else                                                 //If it does exist, append it.
            {
                theFile = fopen(playerOne, "a");
            }
            fprintf(theFile, "vs. %s\n", playerAI);


            if ((theOtherFile = fopen(playerAI, "r+"))  == NULL) //If Al's file doesn't exist, make it.
            {
                theOtherFile = fopen(playerAI, "w");
                fprintf(theOtherFile, "--%s--\n\n", playerAI);
            }
            else                                                 //If it exists, append it.
            {
                theOtherFile = fopen(playerAI, "a");
            }
            fprintf(theOtherFile, "vs. %s\n", playerOne);

/* Prompt the player for his/her choice. */
            printf("%s, choose C or D \n", playerOne);
            scanf("%s", &scoreOne);

/* Store the player's choice as the ith element
   in the array 'scores', where i is the turn number - 1.
   Eg: If it's the first turn, i = 0.
       If it's the second turn, i = 1.
   Alternatively, i is TURNS - numberOfTurns.

   The 'scores' array is something that Al draws
   from to make his choice in the next turn. */
            scores[TURNS - numberOfTurns] = scoreOne;
            printf("\n");
            system("cls");

/* If it's the first turn, i.e.
   numberOfTurns == TURNS,
   Al chooses C. */
            scoreTwo = 'C';
            printf("Al chose C. \n");

        }

/* If it's not the first turn... */
        else
        {

/* Prompt the player for his/her choice. */
            printf("%s, choose C or D \n", playerOne);
            scanf("%s", &scoreOne);

/* Store the player's choice as the ith element
   in the array 'scores', where i is the turn number - 1.
   Eg: If it's the first turn, i = 0.
       If it's the second turn, i = 1.
   Alternatively, i is TURNS - numberOfTurns.

   The 'scores' array is something that Al draws
   from to make his choice in the next turn. */
            scores[TURNS - numberOfTurns] = scoreOne;
            printf("\n");
            system("cls");

/* In all turns but the first,
   Al chooses what the player chose
   in the previous turn.

   He does this by choosing the ith element
   from the 'scores' array, where i is now
   TURNS - (numberOfTurns + 1).
   NOTE: i is not TURNS - numberOfTurns as before,
   because numberOfTurns in this turn is one less
   than numberOfTurns the previous turn. */

            scoreTwo = scores[TURNS - (numberOfTurns + 1)];
            printf("Al chose %c. \n", scores[TURNS - (numberOfTurns + 1)]);
        }


/* The points are allotted based on the player's and Al's choices.

  If both choose C, both get 3.
  If both choose D, both get 1.
  If one chooses C and the other D, they get 0 and 5 respectively. */
        if (((scoreOne == 'C') || (scoreOne == 'c')) && ((scoreTwo == 'C') || (scoreTwo == 'c')))
        {
            fprintf(theFile, "%d \n", 3);
            fprintf(theOtherFile, "%d \n", 3);
            printf("%s gets %d, %s gets %d. \n", playerOne, 3, playerAI, 3);
            printf("\n\n\n\n\n\n\n\n");
            sumOne = sumOne + 3;  //Each turn, points are added to sumOne to get the player's cumulative.
            sumTwo = sumTwo + 3;  //sumTwo does the same for Al.

            gameAl(numberOfTurns - 1);
        }


        else if (((scoreOne == 'C')||(scoreOne == 'c')) && ((scoreTwo == 'd')||(scoreTwo == 'D')))
        {
            fprintf(theFile, "%d \n", 0);
            fprintf(theOtherFile, "%d \n", 5);
            printf("%s gets %d, %s gets %d. \n", playerOne, 0, playerAI, 5);
            printf("\n\n\n\n\n\n\n\n");
            sumOne = sumOne + 0;
            sumTwo = sumTwo + 5;

            gameAl(numberOfTurns - 1);
        }

        else if (((scoreTwo == 'c') || (scoreTwo == 'C')) && ((scoreOne == 'd')||(scoreOne == 'D')))
        {
            fprintf(theFile, "%d \n", 5);
            fprintf(theOtherFile, "%d \n", 0);
            printf("%s gets %d, %s gets %d. \n", playerOne, 5, playerAI, 0);
            printf("\n\n\n\n\n\n\n\n");
            sumOne = sumOne + 5;
            sumTwo = sumTwo + 0;

            gameAl(numberOfTurns - 1);
        }

        else if (((scoreOne == 'd')||(scoreOne == 'D')) && ((scoreTwo == 'd')||(scoreTwo == 'D')))
        {
            fprintf(theFile, "%d \n", 1);
            fprintf(theOtherFile, "%d \n", 1);
            printf("%s gets %d, %s gets %d. \n", playerOne, 1, playerAI, 1);
            printf("\n\n\n\n\n\n\n\n");
            sumOne = sumOne + 1;
            sumTwo = sumTwo + 1;

            gameAl(numberOfTurns - 1);
        }

        else
        {
            printf("That's not an option, unfortunately. \n");
            printf("\n\n\n\n\n\n\n\n");
            gameAl(numberOfTurns);
        }
    }

/* Once numberOfTurns == 0, execute the following else-block,
   which prints statements declaring the winner based on the players'
   total scores.

   There's no way Al can win, but I wrote a winning statement for him anyway. */
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

    fclose(theFile);
    fclose(theOtherFile);
}

/*----------------------------------------------------------------
  The gameAl function is for a game between a human player
  and our first computer player, Al.
  It takes an input parameter numberOfTurns, which specifies the
  number of turns in the game.

  The function uses a recursive method to run for the specified
  number of turns. As before, we start with
  numberOfTurns == TURNS i.e. 10.
----------------------------------------------------------------*/
void gameHAL(int numberOfTurns)
{

    char playerAI[] = "HAL";

/* Set the seed/terminating value for the recursion. */
    if (numberOfTurns > 0)
    {

/* If it's the first turn, the player is prompted for their name,
   which is stored in a char array/string. */
        if (numberOfTurns == TURNS)
        {
            printf("Enter your name \n");
            scanf("%s", &playerOne);
            printf("\n\n\n\n\n\n");


/* Files are made for the player and Al to store their scores. */
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
        }

/* Prompt the player for his/her choice. */
        printf("%s, choose C or D \n", playerOne);
        scanf("%s", &scoreOne);

/* Store the player's choice as the ith element
   in the array 'scores', where i is the turn number - 1.
   Eg: If it's the first turn, i = 0.
       If it's the second turn, i = 1.
   Alternatively, i is TURNS - numberOfTurns.

   The 'scores' array is something that HAL draws
   from to make his choice in the next turn. */
        scores[TURNS - numberOfTurns] = scoreOne;
        printf("\n");
        system("cls");

/* If it's the first turn, i.e.
   numberOfTurns == TURNS,
   HAL chooses C. */
        if (numberOfTurns == TURNS)
        {
            scoreTwo = 'C';
            printf("%s chose C. \n", playerAI);
        }

/* If it's the last turn, i.e.
   numberOfTurns == 1,
   HAL chooses D. */
        else if (numberOfTurns == 1)
        {
            scoreTwo = 'D';
            printf("%s chose D. \n", playerAI);
        }

/* In any other turn,
   HAL chooses what the player chose
   in the previous turn.

   He does this by choosing the ith element
   from the 'scores' array, where i is now
   TURNS - (numberOfTurns + 1).
   NOTE: i is not TURNS - numberOfTurns as before,
   because numberOfTurns in this turn is one less
   than numberOfTurns the previous turn. */
        else
        {
            scoreTwo = scores[TURNS - (numberOfTurns + 1)];
            printf("%s chose %c. \n", playerAI, scores[TURNS - (numberOfTurns + 1)]);
        }

/* The points are allotted based on the player's and HAL's choices.

  If both choose C, both get 3.
  If both choose D, both get 1.
  If one chooses C and the other D, they get 0 and 5 respectively. */
        if (((scoreOne == 'C') || (scoreOne == 'c')) && ((scoreTwo == 'C') || (scoreTwo == 'c')))
        {
            fprintf(theFile, "%d \n", 3);
            fprintf(theOtherFile, "%d \n", 3);
            printf("%s gets %d, %s gets %d. \n", playerOne, 3, playerAI, 3);
            printf("\n\n\n\n\n\n\n\n");
            sumOne = sumOne + 3;  //Each turn, points are added to sumOne to get the player's cumulative.
            sumTwo = sumTwo + 3;  //sumTwo does the same for HAL.

            gameHAL(numberOfTurns - 1);
        }


        else if (((scoreOne == 'C')||(scoreOne == 'c')) && ((scoreTwo == 'd')||(scoreTwo == 'D')))
        {
            fprintf(theFile, "%d \n", 0);
            fprintf(theOtherFile, "%d \n", 5);
            printf("%s gets %d, %s gets %d. \n", playerOne, 0, playerAI, 5);
            printf("\n\n\n\n\n\n\n\n");
            sumOne = sumOne + 0;
            sumTwo = sumTwo + 5;

            gameHAL(numberOfTurns - 1);
        }

        else if (((scoreTwo == 'c') || (scoreTwo == 'C')) && ((scoreOne == 'd')||(scoreOne == 'D')))
        {
            fprintf(theFile, "%d \n", 5);
            fprintf(theOtherFile, "%d \n", 0);
            printf("%s gets %d, %s gets %d. \n", playerOne, 5, playerAI, 0);
            printf("\n\n\n\n\n\n\n\n");
            sumOne = sumOne + 5;
            sumTwo = sumTwo + 0;

            gameHAL(numberOfTurns - 1);
        }

        else if (((scoreOne == 'd')||(scoreOne == 'D')) && ((scoreTwo == 'd')||(scoreTwo == 'D')))
        {
            fprintf(theFile, "%d \n", 1);
            fprintf(theOtherFile, "%d \n", 1);
            printf("%s gets %d, %s gets %d. \n", playerOne, 1, playerAI, 1);
            printf("\n\n\n\n\n\n\n\n");
            sumOne = sumOne + 1;
            sumTwo = sumTwo + 1;

            gameHAL(numberOfTurns - 1);
        }

        else
        {
            printf("That's not an option, unfortunately. \n");
            printf("\n\n\n\n\n\n\n\n");
            gameHAL(numberOfTurns);
        }

    }

/* Once numberOfTurns == 0, execute the following else-block,
   which prints statements declaring the winner based on the players'
   total scores. */
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

    fclose(theFile);
    fclose(theOtherFile);
}

/*-----------------------------------------------------------------
  The choose function allows the player to choose between
  single player (against the computer) and multiplayer.

  If the player chooses single-player, it
  also lets the player choose between the two computer players.
-----------------------------------------------------------------*/
void choose()
    {
        char choice;

/* Print statements prompting the player to choose between single- and multi-player. */
        printf("For multiplayer, type 1 \n");
        printf("For single player (against computer), type 2\n");

/* If the player inputs '1', run the gameMulti function. */
        scanf("%c", &choice);
        if (choice == '1')
        {
            gameMulti(TURNS);
        }

/* If the player inputs '2', ask the player if he/she wants
   to play Al or HAL. */
        else if (choice == '2')
        {
            char opponent;
            printf("Pick who you want to play against \n");
            printf("Al \t HAL \n\n");
            printf("Type A or H\n");

            scanf("%s", &opponent);

/* If the player inputs 'A', run gameAl so he/she
   plays against Al. */
            if ((opponent == 'A') || (opponent == 'a'))
            {
                gameAl(TURNS);
            }

/* If the player inputs 'B', run gameHAL so he/she
   plays against HAL. */
            else if ((opponent == 'H') || (opponent == 'h'))
            {
                gameHAL(TURNS);
            }

/* If the player inputs anything else
   besides A or H for the 'Al or HAL' choice,
   tell him/her it's an invalid entry
   and run the choose function again. */
            else
            {
                printf("Invalid entry.\n");
                system("cls");
                choose();
            }
        }

/* If the player inputs anything else
   besides '1' or '2' for the
   'single-player or multi-player' choice,
   tell him/her it's an invalid entry
   and run the choose function again. */
        else
        {
            printf("Invalid option.\n");
            system("cls");
            choose();
        }
    }




int main()
{

/* Print statements to introduce the player to the game. */
    printf("Welcome to the nooks and crannies of CS110.\n");
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

/* If the player inputs the '\n' character,
   clear the terminal window and run the
   choose function.

   The choose function decides which game to run--
   gameMulti,
   gameAl,
   gameHAL
   --based on the player's input.  */
    char enter;
    scanf("%c", &enter);
    if (enter == '\n')
    {
        system("cls");
        choose();
    }

}

/*---- END ----*/



