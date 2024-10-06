#include "tile.h"

Tile::Tile(Monopoly *game,size_t id, const std::string &name, const std::string &type, const std::string &details) : id(id), name(name), type(type), details(details) {};

Buyable::Buyable(Monopoly *game, size_t id, const std::string &name, const std::string &type, const std::string &details, int price) : Tile(game, id, name, type, details), price(price) ,owner(nullptr){};

int Buyable::getPrice() const
{
    return price;
}

Player *Buyable::getOwner() const
{
    return owner;
}

Property::Property(Monopoly *game, size_t id, const std::string &name, const std::string &type, const std::string &details, int group, int price, int rent, int houseRent,int hotelRent, int houseCost) : Buyable(game, id, name, type, details, price), group(group), rent(rent), houseRent(houseRent), hotelRent(hotelRent), houseCost(houseCost) {
    this->details = "Group: " + std::to_string(group) + "\n" + "Rent: " + std::to_string(rent) + "\n"+ "House Cost: " + std::to_string(houseCost) + "\n" + "Hotel Cost: " + std::to_string(houseCost*4+100) + "\n" + "Rent with 1 House: " + std::to_string(houseRent) + "\n" + "Rent with 2 Houses: " + std::to_string(houseRent*2) + "\n" + "Rent with 3 Houses: " + std::to_string(houseRent*4) + "\n" + "Rent with 4 Houses: " + std::to_string(houseRent*8) + "\n" + "Rent with Hotel: " + std::to_string(hotelRent);
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

int Property::getGroup() const{
    return group;
};

void Property::landOn(Monopoly &game,Player *player)
{}

Go::Go(Monopoly *game, size_t id, const std::string &name, const std::string &type, const std::string &details) : Tile(game, id, name, type, details) {};

void Go::landOn(Monopoly &game,Player *player)
{}

Jail::Jail(Monopoly *game, size_t id, const std::string &name, const std::string &type, const std::string &details) : Tile(game, id, name, type, details) {};

void Jail::landOn(Monopoly &game,Player *player)
{}

FreeParking::FreeParking(Monopoly *game, size_t id, const std::string &name, const std::string &type, const std::string &details) : Tile(game, id, name, type, details) {};

void FreeParking::landOn(Monopoly &game,Player *player)
{}

GoToJail::GoToJail(Monopoly *game, size_t id, const std::string &name, const std::string &type, const std::string &details) : Tile(game, id, name, type, details) {};

void GoToJail::landOn(Monopoly &game,Player *player)
{}

Chance::Chance(Monopoly *game, size_t id, const std::string &name, const std::string &type, const std::string &details) : Tile(game, id, name, type, details) {};

void Chance::landOn(Monopoly &game,Player *player)
{}

CommunityChest::CommunityChest(Monopoly *game, size_t id, const std::string &name, const std::string &type, const std::string &details) : Tile(game, id, name, type, details) {};

void CommunityChest::landOn(Monopoly &game,Player *player)
{}

Railroad::Railroad(Monopoly *game, size_t id, const std::string &name, const std::string &type, const std::string &details, int price, int rent) : Buyable(game, id, name, type, details, price), rent(rent) {};

void Railroad::landOn(Monopoly &game,Player *player)
{}

Utility::Utility(Monopoly *game, size_t id, const std::string &name, const std::string &type, const std::string &details, int price) : Buyable(game, id, name, type, details, price) {};

void Utility::landOn(Monopoly &game,Player *player)
{}

IncomeTax::IncomeTax(Monopoly *game, size_t id, const std::string &name, const std::string &type, const std::string &details, int tax) : Tile(game, id, name, type, details), tax(tax) {};

void IncomeTax::landOn(Monopoly &game,Player *player)
{}

LuxuryTax::LuxuryTax(Monopoly *game, size_t id, const std::string &name, const std::string &type, const std::string &details, int tax) : Tile(game, id, name, type, details), tax(tax) {};

void LuxuryTax::landOn(Monopoly &game,Player *player)
{}


