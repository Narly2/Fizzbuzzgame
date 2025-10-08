#include "FizzBuzz.h"
#include <iostream>
#include "Players.h"
#include <chrono>


using namespace std;

FizzBuzz::FizzBuzz(int numPlayers, int div1, int div2,const std::string& word1, const std::string& word2,const std::vector<Players>& players)
    : numPlayers(numPlayers), div1(div1), div2(div2),word1(word1), word2(word2), players(players){
    //constructor
}

void FizzBuzz::play() {
    int n=100;                          //Indicates how far the count is made

    for(int i=1;i<=n;i++){

            Players currentPlayer = players[(i - 1) % numPlayers];  //calculates the player's turn
            string message = currentPlayer.getName() + " says ";

            if(i % div1 == 0 && i % div2 == 0){

                    message += word1 + word2 + "!";
            }
            else if (i%div1 == 0){

                    message += word1 + "!";
            }
            else if (i%div2 == 0){

                    message += word2+ "!";
            }
            else{
                    message +=to_string(i);

            }


        {
            lock_guard<mutex> lock(mtx);        // protect access to the shared list
            messages.push_back(message);
        }

        this_thread::sleep_for(chrono::milliseconds(100));   // add a delay
    }


    {
        lock_guard<mutex> lock(mtx);
        done = true;                    // indicates that it has finished
    }
}

// ------------------ thread controls ------------------
void FizzBuzz::start() {
    logicThread = thread(&FizzBuzz::play, this);

    // thread that prints messages on screen
    printThread = thread([this]() {
        while (true) {
            {
                lock_guard<mutex> lock(mtx);
                if (!messages.empty()) {                    //Lock the mutex,print the first message, remove it doesn't repeat.
                    cout << messages.front() << endl;
                    messages.erase(messages.begin());
                }
                else if (done) {
                    break;                                  // finished if there are not messages
                                   }
            }
            this_thread::sleep_for(chrono::milliseconds(200));
        }
    });
}

void FizzBuzz::join() {
    if (logicThread.joinable()) logicThread.join();
    if (printThread.joinable()) printThread.join();         // wait for each thread to finished
}



FizzBuzz::~FizzBuzz()
{
    //destructor
}
