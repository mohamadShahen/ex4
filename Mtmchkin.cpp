#include "Mtmchkin.h"
#include <fstream>

using namespace std;

void rotate(shared_ptr<Player>* leaderboard, int source, int dest);

void swapPtr(shared_ptr<Player> one, shared_ptr<Player> two)
{
    shared_ptr<Player> temp = one;
    one = two;
    two = temp;
}

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
    throw std::invalid_argument("invalid argument");
}

void insertPlayers(Queue<shared_ptr<Player>>& team, shared_ptr<Player>*& leaderboard)
{
    printEnterTeamSizeMessage();
    char size;
    for (cin >> size; !((size - '0') >= 2 && (size - '0') <= 6) ; cin >> size) {
        printInvalidTeamSize();
    }
    leaderboard = new shared_ptr<Player>[size];
    for (int i = 0; i < size - '0'; ++i) {
        printInsertPlayerMessage();
        string name,type;
        for (cin >> name,cin >> type;;cin >> name,cin >> type)
        {
            bool check = true;
            for (int j = 0; name[j] ; ++j) {
                if (!(name[j] >= 'a' && name[j] <= 'z') && !(name[j] >= 'A' && name[j] <= 'Z')) {
                    check = false;
                    printInvalidName();
                    break;
               }
            }
            if(check == false){
                continue;
            }
            if (type != NINJA && type != HEALER && type != WARRIOR){
                printInvalidClass();
                continue;
            }
            break;
        }
        team.pushBack(createPlayer(name,type));
        leaderboard[i] = team.back();
    }
}

shared_ptr<Card> createCard(const std::string& type)
{
    if (type == GREMLIN) {
        return shared_ptr<Card>(new Gremlin());
    }
    if (type == WITCH){
        return shared_ptr<Card>(new Witch());
    }
    if (type == DRAGON){
        return shared_ptr<Card>(new Dragon());
    }
    if (type == TREASURE){
        return shared_ptr<Card> (new Treasure());
    }
    if (type == MERCHANT){
        return shared_ptr<Card> (new Merchant());
    }
    if (type == WELL){
        return shared_ptr<Card>(new Well());
    }
    if (type == BARFIGHT){
        return shared_ptr<Card>(new Barfight());
    }
    if (type == MANA){
        return shared_ptr<Card>(new Mana());
    }
    throw std::invalid_argument("invalid argument");
}

void insertCards(Queue<shared_ptr<Card>>& deck, const string& fileName)
{
    ifstream file(fileName);
    if (file.is_open())
    {
        string line;
        int lineNum = 0;
        while (getline(file, line))
        {
            lineNum++;
            if(line != MANA  && line != MERCHANT  && line != BARFIGHT && line != DRAGON &&
                line != GREMLIN && line != TREASURE && line != WELL && line != WITCH)
            {
                throw DeckFileFormatError("Deck File Error: File format error in line ",lineNum);
            }
            deck.pushBack(createCard(line));
        }
        file.close();
        if (lineNum < MINIMUM_CARDS_NUMBER)
        {
            throw DeckFileInvalidSize("Deck File Error: Deck size is invalid");
        }
    }
    else
    {
        throw DeckFileNotFound("Deck File Error: File not found");
    }

}

//constructor of game class
Mtmchkin::Mtmchkin(const string& fileName)
{
    printStartGameMessage();
    insertCards(m_deck,fileName);
    insertPlayers(m_team,m_leaderboard);
}

void Mtmchkin::playRound()
{

    int first = 0, last = m_team.size();
    printRoundStartMessage(m_rounds + 1);
    for (shared_ptr<Player> player : m_team) {
        if(!(player->isKnockedOut()) && player->getLevel() < LAST_LEVEL) {
            printTurnStartMessage(player->getName());
            m_deck.front()->applyEncounter(*player);

            if (player->isKnockedOut()) {
                rotate(m_leaderboard, (getPlayerRank(player)), last);
                --last;
            }
            if (player->getLevel() == LAST_LEVEL){
                rotate(m_leaderboard, getPlayerRank(player), first);
                ++first;
            }

            m_deck.pushBack(m_deck.front());
            m_deck.popFront();
        }
    }
    if (isGameOver()){
        printGameEndMessage();
    }
    m_rounds++;
}

bool Mtmchkin::isGameOver() const
{
    for (shared_ptr<Player> player : m_team){
        if(!(player->isKnockedOut()) && player->getLevel() < LAST_LEVEL){
            return false;
        }
    }
    return true;
}
int Mtmchkin::getNumberOfRounds() const
{
    return m_rounds;
}
int Mtmchkin::getPlayerRank(const shared_ptr<Player> wanted) const
{
    int i = 0;
    for (shared_ptr<Player> player : m_team) {
        if (player->getName() == wanted->getName() && player->getType() == wanted->getType()){ // here is the part where 2 players with the same name and class should be checked
            return i;
        }
        i++;
    }
    throw std::invalid_argument("invalid argument");
    //not sure whether there should be an exception here for if the player entered exists in the team
}



void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    for (shared_ptr<Player> player : m_team) {
        printPlayerLeaderBoard(getPlayerRank(player) + 1, *player); ///gotta get rid of the 1
    }
}

void rotate(shared_ptr<Player>* leaderboard, int source, int dest)
{
    if (source == dest){
        return;
    }
    if (source < dest) {
        for (int i = source; i < dest; ++i) {
            leaderboard[source].swap(leaderboard[source + 1]);
        }
    }
    if (source > dest) {
        for (int i = source; i > dest; --i) {
            leaderboard[source].swap(leaderboard[source - 1]);
        }
    }
}