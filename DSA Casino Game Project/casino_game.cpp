#include<bits/stdc++.h>
#include <iostream>
#include <string> 
#include <cstdlib> // Needed to use random numbers
#include <ctime>
using namespace std;
 
void drawLine(int n, char symbol);
void rules();
 
int main()
{
    string playerName;
    int amount; // store player balance amount
    int bettingAmount; 
    int guess;
    int dice; // store computer generated number
    char choice;
 
    srand(time(0)); // random number generator

    cout << "\n";
    cout << "\n\t\t\t  *******************\n";
    cout << "\n\t\t\t        =============================================";
    cout << "\n\t\t\t        =                                           =";
    cout << "\n\t\t\t        =                    WELCOME                =";
    cout << "\n\t\t\t        =                      TO                   =";
    cout << "\n\t\t\t        =                    CASINO                 =";
    cout << "\n\t\t\t        =                                           =";
    cout << "\n\t\t\t        =============================================";
    cout << "\n\t\t\t  *******************";
   
 
    cout << "\n\nEnter Your Name : ";
    getline(cin, playerName);
 
    cout << "\n\nHow much amount you want to deposit to play game ? : Rs.";
    cin >> amount;
    
    do
    {
        system("cls"); // clear output screen
        rules();
        cout << "\n\nYour current balance is Rs. " << amount << "\n";
		
		// Get player's betting amount
        do
        {
            cout <<playerName<<", enter money to bet : Rs.";
            cin >> bettingAmount;
            if(bettingAmount > amount)
                cout << "Your betting amount is more than your current balance\n"
                       <<"\nRe-enter amount \n ";
        }while(bettingAmount > amount);
 
		//Through This  Get player's guessed numbers
        do
        {
            cout << "Guess your number to bet between 1 to 10 :";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout << "Please enter number between 1 to 10\n"
                    <<"\nRe-enter number\n\n ";
        }while(guess <= 0 || guess > 10);
 
        dice = rand()%10 + 1; // hold the randomly generated number between 1 and 10
    
        if(dice == guess)
        {
            cout << "\n\nGood Luck !! You won Rs." << bettingAmount * 10;
            amount = amount + bettingAmount * 10;
        }
        else
        {
            cout << "\n\nBad Luck  !! You lost Rs. "<< bettingAmount <<"\n";
            amount = amount - bettingAmount;
        }
 
        cout << "\nThe winning number was : " << dice <<"\n";
        cout << "\n"<<playerName<<", You have Rs. " << amount << "\n";
        if(amount == 0)
        {
            cout << "You lost your all money . Good bye See you Soon";
            break;
        }
        cout << "\n\nDo you want to play again (y/n) ? ";		
        cin >> choice;
    }
	while(choice=='Y'|| choice=='y');
    
    cout << "\n\n\n";
    drawLine(100,'=');
    cout << "\n\n THANKS . Your final balance is Rs. " << amount << "\n";
    drawLine(100,'=');
 
    return 0;
}
 
void drawLine(int n, char symbol)
{
    for(int i=0; i<n; i++)
        cout << symbol;
    cout << "\n" ;
}
 
void rules()
{
    system("cls");
    cout << "\n\n";
    drawLine(100,'-');
    cout << "\t\t GAME RULES \n";
    drawLine(100,'-');
    cout << "\t1. Choose any number between 1 to 10\n";
    cout << "\t2. If you win then you will get 10 times of money you bet\n";
    cout << "\t3. If you bet on wrong number then you will lose amount you bet\n";
    cout << "\t4. You can quite game at any time\n\n";
    drawLine(100,'-');
}