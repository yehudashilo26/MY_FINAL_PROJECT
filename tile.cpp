#include "tile.h"
#include "monopoly.h"

Tile::Tile(size_t id, const std::string &name, const std::string &type, const std::string &details) : id(id), name(name), type(type), details(details) {};

Buyable::Buyable(size_t id, const std::string &name, const std::string &type, const std::string &details, int price) : Tile(id, name, type, details), price(price), owner(nullptr) {};

int Buyable::getPrice() const
{
    return price;
}

Player *Buyable::getOwner() const
{
    return owner;
}

Property::Property(size_t id, const std::string &name, const std::string &type, const std::string &details, int group, int price, int rent, int houseRent, int hotelRent, int houseCost) : Buyable(id, name, type, details, price), group(group), rent(rent), houseRent(houseRent), hotelRent(hotelRent), houseCost(houseCost)
{
    this->details = "Group: " + std::to_string(group) + "\n" + "Rent: " + std::to_string(rent) + "\n" + "House Cost: " + std::to_string(houseCost) + "\n" + "Hotel Cost: " + std::to_string(houseCost * 4 + 100) + "\n" + "Rent with 1 House: " + std::to_string(houseRent) + "\n" + "Rent with 2 Houses: " + std::to_string(houseRent * 2) + "\n" + "Rent with 3 Houses: " + std::to_string(houseRent * 4) + "\n" + "Rent with 4 Houses: " + std::to_string(houseRent * 8) + "\n" + "Rent with Hotel: " + std::to_string(hotelRent);
};

int Property::getRent() const
{
    return rent;
}

int Property::getHouses() const
{
    return houses;
}

bool Property::hasHotel() const
{
    return hotel;
}

int Property::getGroup() const
{
    return group;
};

void Property::landOn(Monopoly &game, Player *player)
{
    if (owner == nullptr || owner == player)
    {
        return;
    }
    else
    {
        game.payPlayer(*player, *owner, rent);
    }
}

void Property::addHouse()
{
    houses++;
    if (houses == 1)
    {
        rent = houseRent;
    }
    else
    {
        rent = rent * 2;
    }
}

void Property::addHotel()
{
    hotel = true;
    rent = hotelRent;
}

int Property::getHouseCost() const{
    return houseCost;
}

Go::Go(size_t id, const std::string &name, const std::string &type, const std::string &details) : Tile(id, name, type, details) {};

void Go::landOn(Monopoly &game, Player *player)
{

}

Jail::Jail(size_t id, const std::string &name, const std::string &type, const std::string &details) : Tile(id, name, type, details) {};

void Jail::landOn(Monopoly &game, Player *player)
{
    // nothing happens
}

FreeParking::FreeParking(size_t id, const std::string &name, const std::string &type, const std::string &details) : Tile(id, name, type, details) {};

void FreeParking::landOn(Monopoly &game, Player *player)
{
    game.endTurn(*player);
}

GoToJail::GoToJail(size_t id, const std::string &name, const std::string &type, const std::string &details) : Tile(id, name, type, details) {};

void GoToJail::landOn(Monopoly &game, Player *player)
{
    game.moveToJail(*player);
}

Chance::Chance(size_t id, const std::string &name, const std::string &type, const std::string &details) : Tile(id, name, type, details) {};

void Chance::landOn(Monopoly &game, Player *player)
{
    // game.drawChanceCard(player); need to uncomment when done checking
}

CommunityChest::CommunityChest(size_t id, const std::string &name, const std::string &type, const std::string &details) : Tile(id, name, type, details) {};

void CommunityChest::landOn(Monopoly &game, Player *player)
{
}

Railroad::Railroad(size_t id, const std::string &name, const std::string &type, const std::string &details, int price, int rent) : Buyable(id, name, type, details, price), rent(rent) {};

void Railroad::landOn(Monopoly &game, Player *player)
{
}

Utility::Utility(size_t id, const std::string &name, const std::string &type, const std::string &details, int price) : Buyable(id, name, type, details, price) {};

void Utility::landOn(Monopoly &game, Player *player)
{
}

IncomeTax::IncomeTax(size_t id, const std::string &name, const std::string &type, const std::string &details, int tax) : Tile(id, name, type, details), tax(tax) {};

void IncomeTax::landOn(Monopoly &game, Player *player)
{
}

LuxuryTax::LuxuryTax(size_t id, const std::string &name, const std::string &type, const std::string &details, int tax) : Tile(id, name, type, details), tax(tax) {};

void LuxuryTax::landOn(Monopoly &game, Player *player)
{
}
