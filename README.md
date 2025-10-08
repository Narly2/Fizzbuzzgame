FizzBuzz Game in C++

A multithreaded FizzBuzz game implemented in C++ with customizable player names divisor numbers.

Description
This project implements a FizzBuzz game with enhancements for multiple players and message display.

- For numbers from 1 to n (default n=100):
  - Prints "Fizz!" if divisible by 3
  - Prints "Buzz!" if divisible by 5
  - Prints "FizzBuzz!" if divisible by both 3 and 5
  - Prints the number otherwise
- Supports any number of players (up to n) with custom names
- Messages are safely handled using a thread-safe queue

 Features
- Multithreaded: separate threads for game logic and message printing
- Mutex protection for shared resources
- Easy to extend for more complex rules or custom words
- Uses modern C++ practices

 Installation
1. Clone the repository:
2. git clone https://github.com/TuUsuario/FizzBuzzProject.git
2. Open the project in Code::Blocks or any C++ IDE.
3. Build the project (make sure you have C++11 or later enabled).
4. Run the executable.

How to Play
1. Launch the game.
2. Choose a option game.
3. Option 1. is a default game, option 2. Enter each divisor number and player’s name.
4. The game will print each turn following FizzBuzz rules.


