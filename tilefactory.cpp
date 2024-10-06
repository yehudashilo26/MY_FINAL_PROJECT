#include "tilefactory.h"
#include <iostream>

std::unique_ptr<Tile> TileFactory::createTile(Monopoly *monopoly, const json &tile_data)
{
    // Extract mandatory fields
    std::string type = tile_data["type"];
    int id = tile_data["id"];
    std::string name = tile_data["name"];

    // Extract optional fields like details, or default to an empty string
    std::string details = tile_data.contains("details") ? tile_data["details"] : "";

    if (type == "property")
    {
        // Parse property-specific data
        int group = tile_data["group"];
        int price = tile_data["price"];
        int rent = tile_data["rent"];
        int houseRent = tile_data["house_rent"];
        int houseCost = tile_data["house_cost"];
        int hotelRent = tile_data["hotel_rent"];
        return std::make_unique<Property>(monopoly, id, name, type, details, group, price, rent, houseRent, hotelRent, houseCost);
    }
    else if (type == "go")
    {
        return std::make_unique<Go>(monopoly, id, name, type, details);
    }
    else if (type == "jail")
    {
        return std::make_unique<Jail>(monopoly, id, name, type, details);
    }
    else if (type == "free_parking")
    {
        return std::make_unique<FreeParking>(monopoly, id, name, type, details);
    }
    else if (type == "go_to_jail")
    {
        return std::make_unique<GoToJail>(monopoly, id, name, type, details);
    }
    else if (type == "chance")
    {
        return std::make_unique<Chance>(monopoly, id, name, type, details);
    }
    else if (type == "community_chest")
    {
        return std::make_unique<CommunityChest>(monopoly, id, name, type, details);
    }
    else if (type == "railroad")
    {
        // Parse railroad-specific data
        int price = tile_data["price"];
        int rent = tile_data["rent"];
        return std::make_unique<Railroad>(monopoly, id, name, type, details, price, rent);
    }
    else if (type == "utility")
    {
        // Parse utility-specific data
        int price = tile_data["price"];
        return std::make_unique<Utility>(monopoly, id, name, type, details, price);
    }
    else if (type == "tax")
    {
        // Parse tax-specific data
        int price = tile_data["price"];
        return std::make_unique<IncomeTax>(monopoly, id, name, type, details, price);
    }
    else if (type == "luxury_tax")
    {
        // Parse luxury tax-specific data
        int price = tile_data["price"];
        return std::make_unique<LuxuryTax>(monopoly, id, name, type, details, price);
    }
    else
    {
        // Handle invalid or unrecognized tile types

        std::cout << "Error Creating Tile : Type " << type << " ID: " << id << " Name: " << name << std::endl;
        throw std::invalid_argument("Invalid tile type: " + type);
    }
}
