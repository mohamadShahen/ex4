
#include "../Mtmchkin.h"

const int MAX_ROUNDS = 100;

int main() {
    try{
        Mtmchkin game("deck.txt");
        while (game.getNumberOfRounds() < MAX_ROUNDS && !game.isGameOver())
        {
            game.playRound();
            game.printLeaderBoard();
        }
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}
