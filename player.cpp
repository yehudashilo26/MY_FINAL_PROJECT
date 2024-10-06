#include "player.h"

Player::Player(){};
Player::Player(const std::string &name,size_t id) : name(name),id(id),balance(0),position(0),inJail(false),turnsInJail(0) {}
Player::Player(const std::string &name, size_t id, int balance): name(name),id(id), balance(balance),position(0),inJail(false),turnsInJail(0){}

void Player::setPosition(int position)
{
    this->position = position;
}

void Player::setBalance(int balance)
{
    this->balance = balance;
}

