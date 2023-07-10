#include "Map.h"
#include "game.hpp"
#include <fstream>
#include <iostream>

Map::Map() {}
Map::~Map(){}

void Map::LoadMap(std::string path, int sizeX, int sizeY)
{
    char tile;
    std::fstream mapFile;
    mapFile.open(path);

    std::cout << "File opened!" << std::endl;
    for (int y = 0; y < sizeY; y++)
    {
        for (int x = 0; x < sizeX; x++)
        {
            mapFile.get(tile);
            if (atoi(&tile) != 0)
            {
                if (atoi(&tile) == 3 || atoi(&tile) == 4)
                Game::AddTile(atoi(&tile), x*32, y*32);
                else
                Game::AddCollideTile(atoi(&tile), x*32, y*32, "Tile");
            }
            mapFile.ignore();
        }
        std::cout << "line readed!" << std::endl;
    }

    mapFile.close();
    std::cout << "File closed!" << std::endl;
}