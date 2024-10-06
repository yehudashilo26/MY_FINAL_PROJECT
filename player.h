#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
public:
    Player();
    Player(const std::string &name,size_t id);
    Player(const std::string &name,size_t id,int balance);

    int getID() const {return id;}
    std::string getName() const { return name; }
    int getBalance() const { return balance; }
    int getPosition() const { return position; }
    bool isInJail() const { return inJail; }
    int getTurnsInJail() const { return turnsInJail; }
    bool isBankrupt() const { return balance<0; }

    friend class Monopoly;

private:
    int id;
    std::string name;
    int balance;
    int position;
    bool inJail;
    int turnsInJail;

    void setName(const std::string &name);
    void addToBalance(int amount) { balance += amount; }
    void subtractFromBalance(int amount) { balance -= amount; }
    void setPosition(int position);
    void setBalance(int balance);
    void setInJail(bool inJail) { this->inJail = inJail; }
    void setTurnsInJail(int turnsInJail) { this->turnsInJail = turnsInJail; }
};

#endif // PLAYER_H
