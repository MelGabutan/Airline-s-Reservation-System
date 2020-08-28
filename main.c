#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "airline.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	// Local Declarations
		
		// Integers
		
			int airlineCapacity = 10;
			int sectionChoice;
			int seatNumber;
			
		// Arrays
			
			int airlinePassengers[airlineCapacity];
			
	//	Statements
	
		// Initialize Passenger Seats to 0
		
			initSeats(airlinePassengers, airlineCapacity);
			
		// Do-While Loop
		
		do 
		{
			system("cls");
				
			// Capacity Check
			
				if(airlinePassengers[airlineCapacity / 2 - 1] == 1 && airlinePassengers[airlineCapacity - 1] == 1)
				{
					system("cls");
					
					createBox(5, 8, 42, 75);
					
					gotoxy(43, 6);
						printf("Airlines is at maximum capacity");
			
					Exit();
					return;
				}
		
				else
				{
					// Welcoming Address
				
						createBox(1, 11, 39, 81);
						gotoxy(45, 2);
							printf("Welcome to MGM Airlines!");
							
						displaySeats(airlinePassengers, airlineCapacity);
			
					// Section Choice Prompt
						gotoxy(40,8);
							printf("Press 1 for First Class");
							
						gotoxy(40,9);
							printf("Press 2 for Economy Class: ");
							scanf("%d", &sectionChoice);	
		
					// Assign Seats
						
						while(sectionChoice != 1 && sectionChoice != 2)
						{	
							createBox(16, 18, 44, 68);
							
							gotoxy(63, 17);
								printf("    ");
								
							gotoxy(45, 17);
								printf("Input valid choice: ");
								scanf("%d", &sectionChoice);
						}
							
						seatNumber = assignSeat(airlinePassengers, airlineCapacity, sectionChoice);
						
						if(seatNumber != -1)
						{
							system("cls");	
							boardPass(seatNumber);
							getche();
						}
						
						else
						{
							system("cls");
							
							createBox(5, 8, 42, 75);
							
							gotoxy(54, 6);
								printf("Affirmative");
							
							Exit();
							return;
						}
				}		
		
		}while(sectionChoice != 0);			
	return 0;
}
