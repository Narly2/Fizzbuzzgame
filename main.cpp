/*
 FizzBuzz Game
 This program simulates a FizzBuzz game.
 Rules:
 1. For numbers from 1 to n:
    - Print "Fizz!" if the number is divisible by 3.
    - Print "Buzz!" if the number is divisible by 5.
    - Print "FizzBuzz!" if the number is divisible by both 3 and 5.
    - Otherwise, print the number itself.

 This program has two option, first one, players and number divisors are preset
 and the second option, user can enter the names of players and divisors numbers.
  The program uses multithreading for separate game logic and display.
  */


#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "FizzBuzz.h"
#include "Players.h"


using namespace std;

int main()
{
    int numPlayers = 4, numDiv1 = 3, numDiv2 = 5, optionGame=1;  //Set the number of players and divisor numbers
    string word1 = "fizz", word2 ="buzz", namePlayer;            // set especial words

    vector<Players> defaultPlayers{Players("Abdul"),Players("Bart"), Players("Claudia"), Players("Divya")};
    vector<Players> customPlayers;

    cout<< "** Welcome to the FizzBuzz Game! **\n\n"
        << "In this game, four players take turns counting numbers out loud from 1 to 100.\n"
        << "So the turns repeat and each player continues\n"
        << "- You'll see 'Fizz' for numbers divisible by 3.\n"
        << "- You'll see 'Buzz' for numbers divisible by 5.\n"
        << "- And 'FizzBuzz' for numbers divisible by both 3 and 5.\n\n"
        << "You can also customize the names and divisors to create your own version!\n\n"
        << "Please choose an option:\n"
        << "1. Preset game with four default players\n"
        << "2. Custom game; enter your own divisor numbers and player names\n\n";


    cin >> optionGame;

    if (optionGame == 1){


        FizzBuzz Game (numPlayers, numDiv1, numDiv2, word1, word2, defaultPlayers);
        Game.start();   // start thread
        Game.join();    // wait for each thread to finished
    }
    else if (optionGame == 2){

        cout<< "Please enter the first divisor (it must be an integer):";

        while (!(cin >> numDiv1)) {                                 //cin must be of type numDiv1, otherwise it generates an error with return 0
            cout << "Invalid input. Enter an integer: ";
            cin.clear();                                            //clear the buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');    //Ignore everything in cin up to the new line
        }

        cout<< "Please enter the second divisor (it must be an integer):";

        while (!(cin >> numDiv2)) {
            cout << "Invalid input. Enter an integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }


        cout << "Enter the names followed by the enter key, to finish type END: "<<endl;



        while(true){

            cout<< "Name: ";
            cin>> namePlayer;

            if(namePlayer == "END"||namePlayer == "End"||namePlayer == "end")
                break;


            customPlayers.push_back(Players(namePlayer));               // Fill the vector names with copy of temporal object
        }
        if (customPlayers.empty()){

            cout<< "No players registered. The preset game will be used.\n";
            customPlayers=defaultPlayers;
        }
        numPlayers=customPlayers.size();                                //calculate size of vector

        FizzBuzz Game(numPlayers, numDiv1, numDiv2, word1, word2, customPlayers); //create Game object
        Game.start();
        Game.join();

        }
    else {
        cout << "Invalid option. Closing the game.\n";

    }
    return 0;
}
