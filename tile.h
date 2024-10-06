#ifndef TILE_H
#define TILE_H

#include "player.h"
#include <string>

class Monopoly; // forward declaration.

class Tile
{
public:
    Tile(size_t id, const std::string &name, const std::string &type, const std::string &details);

    size_t getId() const { return id; }
    const std::string &getName() const { return name; }
    const std::string &getType() const { return type; }
    const std::string &getDetails() const { return details; }
    virtual void landOn(Monopoly &game, Player *player) = 0;

protected:
    Monopoly *game;
    size_t id;
    std::string name;
    std::string type;
    std::string details;

    friend class Monopoly;
};

class Buyable : public Tile
{
public:
    Buyable(size_t id, const std::string &name, const std::string &type, const std::string &details, int price);

    int getPrice() const;
    Player *getOwner() const;
    virtual void landOn(Monopoly &game, Player *player) = 0;

protected:
    int price;
    Player *owner;

    void setOwner(Player *owner) { this->owner = owner; }

    friend class Monopoly;
};

class Property : public Buyable
{
public:
    Property(size_t id, const std::string &name, const std::string &type, const std::string &details, int group, int price, int rent, int houseRent, int hotelRent, int houseCost);
    int getRent() const;
    int getGroup() const;
    int getHouses() const;
    int getHouseRent() const;
    int getHotelRent() const;
    int getHouseCost() const;
    bool hasHotel() const;
    void landOn(Monopoly &game, Player *player) override;

protected:
    int group;
    int rent;
    int houseRent;
    int hotelRent;
    int houseCost;
    int houses;
    bool hotel;

    void setOwner(Player *owner) { this->owner = owner; }
    void addHouse();
    void addHotel();
        
    friend class Monopoly;
};

class Go : public Tile
{
public:
    Go(size_t id, const std::string &name, const std::string &type, const std::string &details);

protected:
    void landOn(Monopoly &game, Player *player) override;
};

class Jail : public Tile
{
public:
    Jail(size_t id, const std::string &name, const std::string &type, const std::string &details);

protected:
    void landOn(Monopoly &game, Player *player) override;
};

class FreeParking : public Tile
{
public:
    FreeParking(size_t id, const std::string &name, const std::string &type, const std::string &details);

protected:
    void landOn(Monopoly &game, Player *player) override;
};

class GoToJail : public Tile
{
public:
    GoToJail(size_t id, const std::string &name, const std::string &type, const std::string &details);

protected:
    void landOn(Monopoly &game, Player *player) override;
};

class IncomeTax : public Tile
{
private:
    int tax;

protected:
    void landOn(Monopoly &game, Player *player) override;

public:
    IncomeTax(size_t id, const std::string &name, const std::string &type, const std::string &details, int tax);
    int getTax() const;
};

class LuxuryTax : public Tile
{
private:
    int tax;

protected:
    void landOn(Monopoly &game, Player *player) override;

public:
    LuxuryTax(size_t id, const std::string &name, const std::string &type, const std::string &details, int tax);

    int getTax() const;
};

class Railroad : public Buyable
{

public:
    Railroad(size_t id, const std::string &name, const std::string &type, const std::string &details, int price, int rent);
    int getRent() const;

protected:
    int rent;
    void landOn(Monopoly &game, Player *player) override;
};

class Utility : public Buyable
{
public:
    Utility(size_t id, const std::string &name, const std::string &type, const std::string &details, int price);

protected:
    void landOn(Monopoly &game, Player *player) override;
};

class CommunityChest : public Tile
{
protected:
    void landOn(Monopoly &game, Player *player) override;

public:
    CommunityChest(size_t id, const std::string &name, const std::string &type, const std::string &details);
};

class Chance : public Tile
{
protected:
    void landOn(Monopoly &game, Player *player) override;

public:
    Chance(size_t id, const std::string &name, const std::string &type, const std::string &details);
};

#endif // TILE_H
