#include "Mtmchkin.h"
#include <fstream>
using namespace std;

//constructor of game class
Mtmchkin::Mtmchkin(const string &fileName)
{
    ifstream file(fileName);
    if (file.is_open()) {
        string line;
        while (getline(file, line)){
            m_deck.pushBack(Card(line));
        }
        file.close();
    }
    else{
        throw DeckFileNotFound;
    }
    printEnterTeamSizeMessage();
    int size;
    for (cin >> size; size < 2 || size > 6 ; cin >> size) {
        printInvalidTeamSize();
    }
    for (int i = 0; i < size; ++i) {
        printInsertPlayerMessage();
        string nameAndType,name,type;
        for (cin >> name, cin >> type; type != NINJA && type != HEALER && type != WARRIOR ; cin >> name, cin >> type) {
            printInvalidClass();
        }
    }

}
