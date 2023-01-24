#include <iostream>
#include <cstdlib>
#include <ctime>

class Game{

    private: 
        int maxNumber;
        int playerGuess;
        int randomNumber;
        int numOfGuesses;
        Game();
        void printGameResult();
    
    public: 
        Game(int);
        ~Game();
        void play();
};

Game::Game(int maxNumber) : maxNumber(maxNumber), numOfGuesses(0){
    srand(time(0));
    randomNumber = rand() % maxNumber + 1;
    std::cout << " constructor luotu maximi luvulla " << maxNumber << std::endl;
}

void Game::play(){
    while (true) {
        std::cout << "Guess a number between 1 - " << maxNumber << ": ";
        std::cin >> playerGuess;
        numOfGuesses++;
        if (playerGuess == randomNumber) {
            std::cout << "correct guess" << std::endl;
            break;
        }
        else if (playerGuess < randomNumber){
            std::cout << "the number is higher than " << playerGuess << std::endl;
        }
         else {
            std::cout << "the number is lower than " << playerGuess << std::endl;
        }
    }
    printGameResult();
}

void Game::printGameResult() {
    std::cout << "The correct number was: " << randomNumber << std::endl;
    if (numOfGuesses <= 10) {
        std::cout << "It took you " << numOfGuesses << " attempts to guess the correct number. good!" << std::endl;
    }
    else if (numOfGuesses <= 20) {
        std::cout << "It took you " << numOfGuesses << " attempts to guess the correct number. try harder! " << std::endl;
    }
    else {
        std::cout << "It took you " << numOfGuesses << " attempts to guess the correct number. just terrible! " << std::endl;
    }
}


Game::~Game() {
    std::cout << "--DEBUG---Object Game deleted-----" << std::endl;
}