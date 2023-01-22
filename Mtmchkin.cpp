#include "Mtmchkin.h"
#include <fstream>

using namespace std;

shared_ptr<Player> createPlayer(const std::string& name, const std::string& type)
{
    if (type == NINJA){
        return shared_ptr<Player>(new Ninja(name));
    }
    if (type == HEALER){
        return shared_ptr<Player>(new Healer(name));
    }
    if (type == WARRIOR){
        return shared_ptr<Player>(new Warrior(name));
    }
}

void insertPlayers(Queue<shared_ptr<Player>>& team, shared_ptr<Player>* leaderboard)
{
    printEnterTeamSizeMessage();
    int size;
    for (cin >> size; size < 2 || size > 6 ; cin >> size) {
        printInvalidTeamSize();
    }
    leaderboard = new shared_ptr<Player>[size];
    for (int i = 0; i < size; ++i) {
        printInsertPlayerMessage();
        string name,type;
        for (cin >> name,cin >> type;;cin >> name,cin >> type)
        {
            for (int j = 0; i < name.length() ; ++j) {
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
        team.pushBack(createPlayer(name,type));
        *(leaderboard + i) = team.back();
    }
}

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
    insertPlayers(m_team,m_leaderboard);
}

void Mtmchkin::playRound()
{
    printRoundStartMessage(m_rounds);
    for (shared_ptr<Player> player : m_team) {
        printTurnStartMessage(player->getName());
        Card card = *(m_deck.begin());
        card.applyEncounter(*player);
        m_deck.pushBack(card);
        m_deck.popFront();
    }
    if (isGameOver()){
        printGameEndMessage();
    }
}

bool Mtmchkin::isGameOver() const
{
    for (shared_ptr<Player> player : m_team){
        if(!(player->isKnockedOut()) || player->getLevel() < LAST_LEVEL){
            return false;
        }
    }
    return true;
}
