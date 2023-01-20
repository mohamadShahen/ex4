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
        string name,type;
        for (cin >> name,cin >> type;;cin >> name,cin >> type)
        {
            for (int j = 0; name[j] != NULL ; ++j) {
                if (name[j] < 'a' || name[j] > 'z') {
                    printInvalidName();
                    continue;
                }
            }
            if (type != NINJA && type != HEALER && type != WARRIOR){
                printInvalidClass();
                continue;
            }
            break;
        }
        if (type == NINJA) {
            Ninja* ptr = new Ninja(name);
            m_team.pushBack(dynamic_cast <Player*> (ptr));
        }
        if (type == WARRIOR) {
            Warrior* ptr = new Warrior(name);
            m_team.pushBack(dynamic_cast <Player*> (ptr));
        }
        if (type == HEALER) {
            Healer* ptr = new Healer(name);
            m_team.pushBack(dynamic_cast <Player*> (ptr));
        }
    }
}
