

#include <stdio.h>  //for standard input output operation
#include<stdlib.h>

struct player{      
	char name[20];
	int score;
};

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };


void board()
{
	

    system("cls");  //clear the output screen of the programme
    printf("\n\n\tTic Tac Toe\n\n"); 	
    
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}




int main()
{	
  printf("BEFORE PLAYING, PLEASE CREATE A FILE NAMED tictactoe.txt AND WRITE \n\nFIRST PLAYER NAME 0 \nSECOND PLAYER NAME 0 \n\n");  //0 is score as no one has won at the begining of game
struct player p[2];    //for 2 variables of structure 'player'
int j;
for(j=0;j<2;j++)    // to take names of 2 players
{
	printf("Enter the name of the player %d:\n",j+1);
	fflush(stdin);    //clear the output buffer
	gets(p[j].name);  //string input from keyboard
}

	
	int player=1,i,choice;
    
    char mark;
    do
    {
        board();  //function declaration
       
       
        player = (player % 2) ? 1 : 2;   // take 1 if player % 2 is true. Else take 2 
        printf("Mark of 1st player(X)\t---\tMark of 2nd player(0)\n\n");
        printf("Enter the no. where you want to mark \n");
        if(player==1)
        {
        	printf("player %s turn: ",p[0].name);
		}
		else{
			printf("player %s turn: ",p[1].name);
		}

        
        scanf("%d", &choice);      // type no. from keyboard where you want to mark

        mark = (player == 1) ? 'X' : 'O';     //mark will be 'X' if player= player 1. Else '0' if player= player 2

        if (choice == 1 && square[1] == '1')
            square[1] = mark;
            
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;
            
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;
            
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
            
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
            
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
            
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
            
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
            
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;
            
        else
        {
            printf("Invalid move ");  //invalid move if 1>choice>9
 
        }
        
        i = checkwin();  //check winning condition

       player++;      //increment operator
    }
    
	while (i ==  - 1);
    
    board();
    
    if (i == 1)
	{
		if(player==2)     // winning condition for player 1
		{
			{
				printf("Winner ==> \a%s",p[0].name);  //print player 1 as winner
			}
		
			
		FILE *fptr;     //file pointer
		fptr=fopen("tictactoe.txt","r");  //open file in read mode
		struct player s[100];
		int i=0,count=0;
		while(!feof(fptr))     //end of loop if the condition is true
		{
			fscanf(fptr,"%s %d",s[i].name,&s[i].score);         //take name and score from  fptr file
			i++;
			count++;    //count increment by 1 for each loop
		}
		fclose(fptr);   //fptr file close
				fptr=fopen("tictactoe.txt","w");    //open file apple.txt in write mode
	    
	    for(i=0;i<count;i++)
	    {
	    	if(strcmp(p[0].name,s[i].name)==0)
	    	{
	    		fprintf(fptr,"%s %d\n",p[0].name,s[i].score+1);     //print name and updated score in fptr file
			}
			else{
				fprintf(fptr,"%s %d\n",s[i].name,s[i].score);
				
			}
		}
		fclose(fptr);
    
		}
		else{
			
		{
				printf("Winner ==> \a%s",p[1].name);
		}
			
      	FILE *fptr;
		fptr=fopen("tictactoe.txt","r");
		struct player a[100];
		int m=0,count=0;
		while(!feof(fptr))
		{
			fscanf(fptr,"%s %d",a[m].name,&a[m].score);
			m++;
			count++;
		}
		fclose(fptr);
				fptr=fopen("tictactoe.txt","w");
	    
	    for(m=0;m<count;m++)
	    {
	    	if(strcmp(p[1].name,a[m].name)==0)
	    	{
	    		fprintf(fptr,"%s %d\n",p[1].name,a[m].score+1);
			}
			else{
				fprintf(fptr,"%s %d\n",a[m].name,a[m].score);
				
			}
		}
		fclose(fptr);
		}
}

    else{
	
        printf("==>\aGame draw");    //in case of game draw
      
	}
    return 0;
}



/*********************************************

FUNCTION TO RETURN GAME STATUS
1 FOR GAME IS OVER WITH RESULT
-1 FOR GAME IS IN PROGRESS
O GAME IS OVER AND NO RESULT
 **********************************************/

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
        
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
        
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
        
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
        
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
        
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
        
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
        
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
        
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] 
        != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  - 1;
}




