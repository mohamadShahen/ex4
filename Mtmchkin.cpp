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
        throw DeckFileNotFound();
    }
    printEnterTeamSizeMessage();
    int size;
    for (cin >> size; size < 2 || size > 6 ; cin >> size) {
        printInvalidTeamSize();
    }
    for (int i = 0; i < size; ++i) {
        printInsertPlayerMessage();
        string nameAndType,name,type;
//        int j = 0;
//        for (cin >> name; name[j] != NULL ; ++j) {
//            if(name[j] < 'a' || name[j] > 'z'){
//                j = 0;
//                printInvalidName();
//                cin >> name;
//            }
//        }
//        for (cin >> type; type != NINJA && type != HEALER && type != WARRIOR ; cin >> type) {
//            printInvalidClass();
//        }
        if (type == NINJA) {
            m_team.pushBack(dynamic_cast <Player>(Ninja(name)));
        }
        if (type == WARRIOR) {
            m_team.pushBack(Warrior(name));
        }
        if (type == HEALER) {
            m_team.pushBack(Healer(name));
        }
    }

}
