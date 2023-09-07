#include <time.h>

/*
Defining global variables
*/
int hits = 0, misses = 0; //Setting variables for calculating hits and misses
int randNum1 = 0, randNum2 = 0, randNum3 = 0, randNum4 = 0; //Setting random variables

/*
Declaring a functi	on
*/
char menu();
void checking (int checkedInput, int locationOfInput);
void randomNumber();
void numInput();
void checking (int checkedInput, int locationOfInput);
void paintings();

int main()
{
	char choise = ' '; //Setting variables
	
	/*
	Record it in the main function, so that the function menu and function randomNumber
	wiil be able to use it or set it each function
	*/
	
	srand(time(NULL)); 
	
	do
	{
		choise = menu(); //Function call
		if (choise == 'n')
		{
			break;
		}
	}while(choise == 'y'); //As long as the user wants to continue
	
	printf("\nBye Bye!\n\n");
	
	system("PAUSE");
	return(0);
}

/*
The purpose of the function is to display the menu, get user's input, the answer to the question 'Do you want to continue?'
And returns it to main function. The function does not accept parameters.	
*/
char menu()
{
	int level = 0, repetitions = 0, i = 0; //Setting variables
	char choise = ' '; //Setting variables
	int flag = 1; //Flag symbolizes If a user was able to guess the number or not
	
	printf("\nWelcome to \"Cows & Bullseyes\"!!!\n\n");
	printf("A secret password was chosen to protect the credit card of Pancratiu,\n the descendant of Antiochus.\nYour mission is to stop Pancratius by revealing his secret password.\n\n");
	printf("The rules are as follows:\n");
	printf("1. In each round you try to guess the secret password (4 distinct digits)\n");
	printf("2. After every guess you'll receive two hints about the password\n");
	printf("   HITS:   The number of digits in your guess which were exactly right.\n");
	printf("   MISSES: The number of digits in your guess which belongs to\n");
	printf("   the password but were miss-placed.\n");
	printf("3. If you'll fail to guess the password after a certain number of rounds\n");
	printf("   Pancratius will buy all the gifts for Hanukkah!!!\n\n");
	printf("Please choose the game level:\n");
	printf("1 - Easy (20 rounds)\n");
	printf("2 - Moderate (15 rounds)\n");
	printf("3 - Hard (10 rounds)\n");
	printf("4 - Crazy (random number of rounds 5-25)\n");
	printf("Make a choice:");
	scanf("%d", &level); //Getting input of user's choise
	do
	{		
		switch(level)
		{
			case 1:
				repetitions = 20;
				break;
			case 2:
				repetitions = 15;
				break;
			case 3:
				repetitions = 10;
				break;
			case 4:
				repetitions = rand() % 20 + 5;
				break;
			default:
				printf("Make a choice:");
				scanf("%d", &level); //Getting input of user's choise
		}
	}while ((level < 1) || (level > 4));
	
	randomNumber(); //Call to the function that calculates a random number
	
	for (i = 0; i < repetitions; i++)
	{
		printf("Write your guess (only 1-6, no ENTER is needed)");
		if (level != 4)
		{
			printf(" [%d guesses left]\n", repetitions - i);
		}
		else
		{
			printf("\n");
		}
		numInput(); //function call
		if (hits == 4)
		{
			hits = 0; //Reset variables, the user can guess again
			misses = 0; //Reset variables, the user can guess again
			printf("\n    4 HITS YOU WON!!!\n");
			printf("It took you only %d guesses, you are a professional code breaker!\n", i + 1);
			flag = 0;
			
			printf("	    __     		  __        \n");
			printf("  	___( o)>		<(o )___  \n");
			printf("  	\\ <_. )		 	 ( ._> /   \n");
			printf("   	 `---' 			  `---'		\n\n");
			
			system("COLOR 47");
			break;
		}
		else
		{
			printf("\nYou got    %d HITS    %d MISSES.\n", hits, misses);
			hits = 0; //Reset variables, the user can guess again
			misses = 0; //Reset variables, the user can guess again
		} 
	}
	
	if (flag)
	{
		printf("\n\nOOOOHHHH!!! Pancratius won and bought all of Hanukkah's gifts.\n");
		printf("Nothing left for you...\n");
		printf("The secret password was %d%d%d%d\n\n", randNum1, randNum2, randNum3, randNum4);
		
		system("COLOR 80");
		paintings(); //function call
	}
	
	do
	{
		printf("\nWould you like to play again? (y/n):"); //A request from the user that he will bring his choise
		getchar(); //clear enter
		scanf("%c", &choise); //Getting input
	}while(!((choise == 'n') || (choise == 'y'))); //Check to see if the input is right
	
	system("COLOR 0F");
	
	return (choise); //Return variable to the main function
}
/*
The purpose of this function is to make use of lottery numbers that will pin Antiochus.
The function is a void function and it does not get values.
*/
void randomNumber()
{
	randNum1 = rand() % 6 + 1; //Lottery the first number
	do
	{
		randNum2 = rand() % 6 + 1; //Lottery the second number
	}while(randNum1 == randNum2); //If the second number is the number of first choose the number again.
	
	do
	{
		randNum3 = rand() % 6 + 1; //Lottery the third number
	}while((randNum1 == randNum3) || (randNum2 == randNum3)); //If the third number is equal to one of the previous numbers, select the number again.
	
	do
	{
		randNum4 = rand() % 6 + 1; //Lottery the fourth number
	}while((randNum1 == randNum4) || (randNum2 == randNum4) || (randNum3 == randNum4)); //If the fourth number is equal to one of the previous numbers, select the number again.
}

/*
The purpose of this function is to accept user input as a character,
convert it to an integer, and call the checking function to check whether the user is able to guess the number or not.
The function is a function that gets values, is void function.
*/
void numInput()
{
	//Setting up constant variables, these variables indicate the location of the digit input
	const int INPUT_PLACE1 = 1, INPUT_PLACE2 = 2, INPUT_PLACE3 = 3, INPUT_PLACE4 = 4;
	
	//Defining temporary variables to contain within them the input before his conversion.
	int tmp1 = ' ', tmp2 = ' ', tmp3 = ' ', tmp4 = ' '; 
	
	//Setting variables that contain within them the input after his conversion.
	int InputNum1 = 0, InputNum2 = 0, InputNum3 = 0, InputNum4 = 0;
	
	int flag = 1; //Flag symbolizing the integrity input
	
	while(flag)
	{
		tmp1 = getch(); //Receive input variable
		putch(tmp1); //Returns the variable input
		tmp2 = getch(); //Receive input variable
		putch(tmp2); //Returns the variable input
		tmp3 = getch(); //Receive input variable
		putch(tmp3); //Returns the variable input
		tmp4 = getch(); //Receive input variable
		putch(tmp4); //Returns the variable input
		
		InputNum1 = (int)tmp1 - '0'; //Converting from char to an integer
		InputNum2 = (int)tmp2 - '0'; //Converting from char to an integer
		InputNum3 = (int)tmp3 - '0'; //Converting from char to an integer
		InputNum4 = (int)tmp4 - '0'; //Converting from char to an integer
	
		if ((InputNum1 < 7) && (InputNum1 > 0) && (InputNum2 < 7) && (InputNum2 > 0) &&
			(InputNum3 < 7) && (InputNum3 > 0) && (InputNum4 < 7) && (InputNum4 > 0))
		{
			if ((InputNum1 == InputNum2) || (InputNum1 == InputNum3) || (InputNum3 == InputNum4) ||
				(InputNum2 == InputNum3) || (InputNum2 == InputNum4) || (InputNum3 == InputNum4))
			{
				printf("\nDon't foregt that each number should appear only once, fix your input!\n");
			}
			else
			{
				flag = 0;
			}
		}
		else
		{
			printf("\nOnly 1-6 are allowed, try again!\n");
		}
	}	
	
	checking(InputNum1, INPUT_PLACE1); //Call to the checking function to check the first number of input
	checking(InputNum2, INPUT_PLACE2); //Call to the checking function to check the second number of input
	checking(InputNum3, INPUT_PLACE3); //Call to the checking function to check the third number of input
	checking(InputNum4, INPUT_PLACE4); //Call to the checking function to check the forth number of input
}



/*
The purpose of the function is to check the input, ie whether it is compatible with a secret code.
The function is void function - that is, it returns no values.
And it takes two parameters, one parameter specifies the input number and the second parameter indicates the position of the digit.
*/
void checking (int checkedInput, int locationOfInput)
{
	//Setting up constant variables, these variables indicate the location of the digit random numbers
	const LOCAL_RANDOM1 = 1, LOCAL_RANDOM2 = 2, LOCAL_RANDOM3 = 3, LOCAL_RANDOM4 = 4;
	
	if (checkedInput == randNum1) //Test whether the input is equal to the number within the first digit of the secret code
	{
		if (locationOfInput == LOCAL_RANDOM1) //Test whether input digit position equivalent to the position of the first digit in the secret code
		{
			hits++; //If so, add to hits
		}
		else
		{
			misses++; //else, add to misses
		}
	}
	else 
	{	if (checkedInput == randNum2) //Test whether the input is equal to the number within the second digit of the secret code
		{
			if (locationOfInput == LOCAL_RANDOM2) //Test whether input digit position equivalent to the position of the second digit in the secret code
			{
				hits++; //If so, add to hits
			}
			else
			{
				misses++; //else, add to misses
			}
		}
		else 
		{	
			if (checkedInput == randNum3) //Test whether the input is equal to the number within the third digit of the secret code
			{
				if (locationOfInput == LOCAL_RANDOM3)  //Test whether input digit position equivalent to the position of the third digit in the secret code
				{
					hits++; //If so, add to hits
				}
				else
				{
					misses++; //else, add to misses
				}
			}
			else 
			{	
				if (checkedInput == randNum4)  //Test whether the input is equal to the number within the fourth digit of the secret code
				{
					if (locationOfInput == LOCAL_RANDOM4) //Test whether input digit position equivalent to the position of the fourth digit in the secret code
					{
						hits++; //If so, add to hits
					}
					else
					{
						misses++; //else, add to misses
					}
				}
				
			}
		}
	}
}




void paintings()
{
	printf("                     ,.\n");
	printf("                   ,_> `.   ,';\n");
	printf("               ,-`'      `'   '`'._\n");
	printf("            ,,-) ---._   |   .---''`-),.\n");
	printf("          ,'      `.  \\  ;  //   _,'     `,\n");
	printf("       ,--' ____       \\  '  ,'    ___  `-,\n");
	printf("      _>   //--. `-.              .-'.--\\   \\__\n");
	printf("     '-,  (    `.  `.,`~ \\~'-. ,' ,'    )    _\\\n");
	printf("     _<    \\     \\ ,'  ') )   `. //     //    <,.\n");
	printf("  ,-'   _,  \\    ,'    ( //      `.    /        `-,\n");
	printf("  `-.,-'     `.,'       `         `.,'  `\\    ,-'\n");
	printf("   ,'       _  /   ,,,      ,,,     \\     `-. `-._\n");
	printf("  /-,     ,'  ;   ' _ \\   /  _ `     ; `.     `(`-\\\n");
	printf("   /-,        ;    (o)      (o)      ;          `'`,\n");
	printf(" ,~-'  ,-'    \\     '        `      /     \\      <_\n");
	printf(" /-. ,'        \\                   /       \\     ,-'\n");
	printf("   '`,     ,'   `-/             \\-' `.      `-. <\n");
	printf("    /_    /      /   (_     _)   \\    \\          `,\n");
	printf("      `-._;  ,' |  .::.`-.-' :..  |       `-.    _\\\n");
	printf("        _/       \\  `:: ,^. :.:' / `.        \\,-'\n");
	printf("      '`.   ,-'  /`-..-'-.-`-..-'\\            `-.\n");
	printf("        >_ /     ;  (\\/( ' )\\/)  ;     `-.    _<\n");
	printf("        ,-'      `.  \\`-^^^-'/  ,'        \\ _<\n");
	printf("         `-,  ,'   `. `/\"""""' ,'   `-.   <`'\n");
	printf("           ')        `._.,,_.'        \\ ,-'\n");
	printf("            '._        '`'`'   \\       <\n");
	printf("               >   ,'       ,   `-.   <`'\n");
	printf("                `,/          \\      ,-`\n");
	printf("                 `,   ,' |   /     /\n");
	printf("                  '; /   ;        (\n");
	printf("                   _)|   `       (\n");
	printf("                   `')         .-'\n");
	printf("                     <_   \\   /\n");
	printf("                      \\   /\\(\n");
	printf("                        `;/  `\n");
}
