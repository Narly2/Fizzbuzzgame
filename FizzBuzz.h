#pragma once

#include <string>
#include <vector>
#include "Players.h"
#include <thread>
#include <mutex>


class FizzBuzz
{
    public:
        FizzBuzz(int numPlayers, int div1, int div2,const std::string& word1, const std::string& word2,const std::vector<Players>& players);

        void play();
        void start(); // start threads
        void join();  // Wait final threads

        ~FizzBuzz();

    protected:

    private:
        int numPlayers;
        int div1;
        int div2;
        std::string word1;
        std::string word2;
        std::vector<Players> players;


        std::vector<std::string> messages;  // message queue
        std::mutex mtx;                     // Mutual exclusion
        bool done = false;

        std::thread logicThread;            //Threads
        std::thread printThread;

};

