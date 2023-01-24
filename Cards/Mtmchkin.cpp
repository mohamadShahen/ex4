#include "Mtmchkin.h"
#include <fstream>

using namespace std;

void rotate(shared_ptr<Player>* leaderboard, int source, int dest)
{
    if (source == dest){
        return;
    }
    if (source < dest) {
        for (int i = source; i < dest; ++i) {
            leaderboard[i].swap(leaderboard[i + 1]);
        }
    }
    if (source > dest) {
        for (int i = source; i > dest; --i) {
            leaderboard[i].swap(leaderboard[i - 1]);
        }
    }
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
    string size;
    for (cin >> size; !((size[0] - '0') >= MIN_PLAYERS && (size[0] - '0') <= MAX_PLAYERS) || size.length() > 1 ; cin >> size) {
        printInvalidTeamSize();
    }
    leaderboard = new shared_ptr<Player>[size[0] - '0'];
    for (int i = 0; i < size[0] - '0'; ++i) {
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
        if (lineNum < MIN_CARDS)
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
    m_size = m_team.size();
}

void Mtmchkin::playRound()
{
    int first = 0, last = m_team.size() - 1;
    for (int i = 0; i < m_size; ++i){
        if (m_leaderboard[i]->getLevel() == LAST_LEVEL)
        {
            ++first;
            ++last;
        }
    }
    printRoundStartMessage(m_rounds + 1);
    for (int i = 0; i < m_team.size(); ++i) {
        printTurnStartMessage(m_team.front()->getName());
        m_deck.front()->applyEncounter(*(m_team.front()));
        if (m_team.front()->isKnockedOut()) {
            rotate(m_leaderboard, (getPlayerRank(m_team.front())), last);
            m_team.popFront();
            --last;
            --i;
        } else if (m_team.front()->getLevel() == LAST_LEVEL) {
            rotate(m_leaderboard, getPlayerRank(m_team.front()), first);
            m_team.popFront();
            ++first;
            --i;
        } else if (!m_team.front()->isKnockedOut() && m_team.front()->getLevel() <= LAST_LEVEL) {
            m_team.pushBack(m_team.front());
            m_team.popFront();
        }
        m_deck.pushBack(m_deck.front());
        m_deck.popFront();
    }
    if (isGameOver()){
        printGameEndMessage();
        return;
    }
    m_rounds++;
}

bool Mtmchkin::isGameOver() const
{
    if(m_team.size() == 0){
        return true;
    }
    return false;
}

int Mtmchkin::getNumberOfRounds() const
{
    return m_rounds;
}

int Mtmchkin::getPlayerRank(const shared_ptr<Player> wanted) const
{
    for (int i = 0; i < m_size ; ++i) {
        if (m_leaderboard[i]->getName() == wanted->getName() && m_leaderboard[i]->getType() == wanted->getType()){
            return i;
        }
    }
    throw std::invalid_argument("invalid argument");
}



void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    for (int i = 0; i < m_size ; ++i) {
        printPlayerLeaderBoard(getPlayerRank(m_leaderboard[i]) + 1, *m_leaderboard[i]);
    }
}
