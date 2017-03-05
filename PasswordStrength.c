/***************************************************************************
	Name: Ryan Pencak
	Date: Nov. 7, 2014
	Program: CIA.c
	Description: Determines valid usernames and passwords
***************************************************************************/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

//Initialize functions
int alphabet(char name[]);
int passRequire(char pass[]);
int passCont(char pass[],char name[]);

int main(void)
{
	//Initialize variables
	char exit[5] = "exit";
	char name[5] = {0};
	char pass[13] = {0};
	int endProgram = 0; 


	//Loop through username and password prompts until EXIT is entered as the username
	do
	{
		
		//Prompt user for a username and scan the string into a character array
		printf("Input a username. Input EXIT to end program.\n");
		scanf("%s",name);
		
		if (passCont(exit,name) == 1)
		{
			endProgram = 1;
		}

		if (endProgram == 0)
		{
			//Prompt user for a password and scan the string into a character array
			printf("Input a password for this username.\n");
			scanf("%s",pass);

			//Determine whether the inputed username is exactly four characters and relay an error message if it is not
			if (strlen(name) != 4)
			{
				printf("The username must be exactly four characters long.\n");
			}
	
			//Determine whether the password is between six and twelve characters and relay an error message if it is not
			if ((strlen(pass) < 6) || (strlen(pass) > 12))
			{
				printf("The password must be between six and twelve characters.\n");
			}

			//If the value of function alphabet called on name is equal to 1 print an error message
			if (alphabet(name) == 1)
			{
				printf("The username must contain only alphabetic characters (a-z and A-Z)\n");
			}

			//If the value of function passRequire called on pass is not equal to one print an error message
			if ((passRequire(pass)) != 1)
			{
				printf("The password must have at least one capital letter (A-Z) and one number (0-9).\n");
			}	

			//If the value of function passCont called on pass and name is equal to one print an error message
			if ((passCont(pass,name)) == 1)
			{
				printf("The password may not contain the username, case insensitive.\n");
			}	

			printf("\n");
		}
	}
	while(endProgram == 0);

	return 0;
}

/***************************************************************************
	Name: alphabet
	Input: char name[]
	Output: integer
***************************************************************************/
int alphabet(char name[])
{
	//Initialize variables
	int value = 0;
	int i = 0;

	//Loop through the character array name
	for (i=0; i<strlen(name); i++)
	{
		//If the character at position i in array name is not an alphabetic character set value to 1
		if (name[i] < 65 || (name[i] > 90 && name[i] < 97) || name[i] > 122)
		{
			value = 1;
		}
	}

	return value;
}
/***************************************************************************
	Name: passRequire
	Input: char pass[]
	Output: integer
***************************************************************************/
int passRequire(char pass[])
{
	//Initialize variables
	int finalVal = 0;
	int value1 = 0;
	int value2 = 0;
	int i = 0;

	//Loop through the character array pass
	for (i=0; i<strlen(pass); i++)
	{
		//If the character at position i in array pass is a capital letter set value1 to 1
		if (pass[i] > 64 && pass[i] < 91)
		{
			value1 = 1;
		}
		//If the character at position i in array pass is a number set value2 to 1
		if (pass[i] > 47 && pass[i] < 58)
		{
			value2 = 1;
		}
		//If value1 is 1 and value2 is 1 set returnVal to 1
		if (value1 == 1 && value2 == 1)
		{
			finalVal = 1;
		}
	}

	return finalVal;
}
/***************************************************************************
	Name: passCont
	Input: char pass[], char name[]
	Output: integer
***************************************************************************/
int passCont(char pass[],char name[])
{
	//Initialize variables
	int returnVal = 0;
	int i = 0;
	int j = 0;
	int x = 0;

	//Loop through the pass array and make all values upper case
	for (j=0; j<strlen(pass); j++)
	{
		pass[j] = toupper(pass[j]);
	}
	//Loop through the name array and make all values upper case
	for (x=0; x<strlen(name); x++)
	{
		name[x] = toupper(name[x]);
	}

	//Loop through the character array pass
	for (i=0; i<strlen(pass); i++)
	{
		//Determines if there are 4 characters in array pass after position i
		if ((strlen(pass) - i) >= 4)
		{
			//Determines if the value of position i in pass is equal to position 0 in name
			if (pass[i] == name[0])
			{
				//Determines if the value of position i+1 in pass is equal to position 1 in name
				if (pass[i+1] == name[1])
				{
					//Determines if the value of position i+2 in pass is equal to position 2 in name
					if (pass[i+2] == name[2])
					{
						//Determines if the value of position i+3 in pass is equal to position 3 in name
						if (pass[i+3] == name[3])
						{
							returnVal = 1;
						}
					}
				}
			}
		}
	}

	return returnVal;
}
