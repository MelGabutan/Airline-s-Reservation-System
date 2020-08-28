#include <stdio.h>
#include <windows.h>

void gotoxy(int row, int col)
{
	COORD position = {row, col};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
	return;
}

void createBox(int firstRow, int lastRow, int firstColumn, int lastColumn)
{
	// Local Declarations
	
		// Integers
		
			int i;
			
	// Statements
	
		// Create Box
		
			gotoxy(firstColumn - 1, firstRow);
				putchar(201);
		
			for(i = firstColumn; i < lastColumn; i++)
			{
				gotoxy(i, firstRow);
					putchar(205);
			}
			
			gotoxy(lastColumn, firstRow);
				putchar(187);
				
			for(i = firstRow + 1; i < lastRow; i++)
			{
				gotoxy(firstColumn - 1, i);
					putchar(186);
			}
			
			gotoxy(firstColumn - 1, lastRow);
				putchar(200);
				
			for(i = firstColumn; i < lastColumn; i++)
			{
				gotoxy(i, lastRow);
					putchar(205);
			}
			
			gotoxy(lastColumn, lastRow);
				putchar(188);
				
			for(i = firstRow + 1; i < lastRow; i++)
			{
				gotoxy(lastColumn, i);
					putchar(186);
			}
	return; 	
}

void initSeats(int seats[], int size)
{
	// Local Declarations
	
		int i;
	
	// Statements
	
		// Initialize Seats to 0
	
			for(i = 0; i < size; i++)
				seats[i] = 0;
		
	return;	
}

void displaySeats(int seats[], int size)
{
	// Local Declarations
	
		// Integers
		
			int i;
			
	// Statements
	
		// Display First Class Section
		
			gotoxy(40,5);
				printf("First Class Section: ");
		
			for(i = 0; i < size / 2; i++)
				printf("[%d] ", seats[i]);	
				
		// Display Economy Section
		
			gotoxy(40,6);
				printf("Economy Section: ");
		
			for(i = size / 2; i < size; i++)
				printf("[%d] ", seats[i]);			
				
	return;		
}

int assignSeat(int st[], int size, int seatType)
{
	// Local Declarations
	
		// Integers
		
			int seatNumber;
			int transferChoice;
	
	// Statements
	
		// assignFirstClass function
		
			if(seatType == 1)
			{
				seatNumber = assignFirstClass(st, size); 
					
				if(seatNumber == -1)
				{
					system("cls");
					
					createBox(7, 10, 29, 92);
					gotoxy(45,8);
						printf("First Class Section is full.");
					
					gotoxy(30,9);
						printf("Would you like to fly in Economy Section instead? (0 or 1): ");
						scanf("%d", &transferChoice);
						
					while(transferChoice != 1 && transferChoice != 0)
					{	
						createBox(16, 18, 44, 68);
						
						gotoxy(63, 17);
							printf("    ");
							
						gotoxy(45, 17);
							printf("Input valid choice: ");
							scanf("%d", &transferChoice);
					}
						
					if(transferChoice == 1)
						seatNumber = assignEconomy(st, size);
						
					else
						return -1;
				}
				
				else 
					return seatNumber;
			}
			
			else if(seatType == 2)
			{
				seatNumber = assignEconomy(st, size); 
					
				if(seatNumber == -1)
				{
					system("cls");
					
					createBox(7, 10, 27, 94);
					
					gotoxy(47, 8);
						printf("Economy Section is full.");
					
					gotoxy(28, 9);
						printf("Would you like to fly in First Class Section instead? Y(1)/N(0): ");
						scanf("%d", &transferChoice);
					
					while(transferChoice != 1 && transferChoice != 0)
						{	
							createBox(16, 18, 44, 68);
							
							gotoxy(63, 17);
								printf("    ");
								
							gotoxy(45, 17);
								printf("Input valid choice: ");
								scanf("%d", &transferChoice);
					}	
					
					if(transferChoice == 1)
						seatNumber = assignFirstClass(st, size);
						
					else if(transferChoice == 0)
						return -1;	
				}
				
				else 
					return seatNumber;
			}
	return seatNumber;																
}

int assignFirstClass(int seats[], int size)
{
	// Local Declarations
	
		// Static Integers
		
			static int seatIndex = 0;
	
	// Statements
	
		// Check availability
		
			if(seats[size / 2 - 1] == 1)
				return -1;
				
			else
			{
				seats[seatIndex] = 1;
				seatIndex++;
				return seatIndex;
			}	
}

int assignEconomy(int seats[], int size)
{
	// Local Declarations
	
		// Static Integers
		
			static int seatIndex = 5;
	
	// Statements
	
		// Check availability
		
			if(seats[size - 1] == 1)
				return -1;
				
			else
			{
				seats[seatIndex] = 1;
				seatIndex++;
				return seatIndex;
			}	
}

void boardPass(int seat) 
{
	// Boarding Pass Receipt
	
		createBox(6, 10, 48, 69);
		
		gotoxy(49, 7);
			printf("Boarding Pass");
		
		if(seat <= 4)
		{
			gotoxy(49, 8);
				printf("First Class Section");
		}
		
		else
		{
			gotoxy(49, 8);
				printf("Economy Section");
		}

		gotoxy(49, 9);
			printf("Seat #%d", seat);
	
	return;	
}

void Exit(void)
{
	// Goodbye Statement
		
		gotoxy(44, 7);
			printf("Next flight leaves in 3 hours");
			
	return;
}
