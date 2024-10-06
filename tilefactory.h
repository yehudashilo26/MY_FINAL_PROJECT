#ifndef TILEFACTORY_H
#define TILEFACTORY_H

#include "monopoly.h"
class TileFactory
{
private:
    TileFactory() = default;
    static std::unique_ptr<Tile> createTile(Monopoly *gm,const json &tile_data);
    friend class Monopoly;
};

#endif // TILEFACTORY_H
