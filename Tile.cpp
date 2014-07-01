#include "Tile.h"

#define TILESIZE 64

Tile::Tile(int width, int height)
{
    if (!textureTileset.loadFromFile("Resources/Tileset.png"))
        std::cout << "Error Loading" << std::endl;

    vertices.setPrimitiveType(sf::Quads);
    vertices.resize(width * height * 4);

    for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < height; ++j)
        {
            tile = &vertices[(i + j * width) * 4];

            tile[0].position = sf::Vector2f(TILESIZE * i, TILESIZE * j);
            tile[1].position = sf::Vector2f(TILESIZE * (i + 1), TILESIZE * j);
            tile[2].position = sf::Vector2f(TILESIZE * (i + 1), TILESIZE * (j + 1));
            tile[3].position = sf::Vector2f(TILESIZE * i, TILESIZE * (j + 1));

            tile[0].texCoords = sf::Vector2f(128, 0);
            tile[1].texCoords = sf::Vector2f(192, 0);
            tile[2].texCoords = sf::Vector2f(192, 64);
            tile[3].texCoords = sf::Vector2f(128, 64);
        }
    }

}

void Tile::setTexture(int IDTile, int ID)
{
    int line = ID % 16;
    int column = ID / 16;

    ///Permet de voir à quoi l'ID correspond sur le TILESET
    //std::cout << "line : " << line << " | column : " << column << std::endl;

    vertices[4 * IDTile].texCoords = sf::Vector2f(line * TILESIZE, column * TILESIZE);
    vertices[(4 * IDTile) + 1].texCoords = sf::Vector2f((line + 1) * TILESIZE , column * TILESIZE);
    vertices[(4 * IDTile) + 2].texCoords = sf::Vector2f((line + 1) * TILESIZE, (column + 1) * TILESIZE);
    vertices[(4 * IDTile) + 3].texCoords = sf::Vector2f(line * TILESIZE, (column + 1) * TILESIZE);
}

bool Tile::Colision(sf::Vector2f *worldPos) // A revoir à cause de la caméra GUI
{
    sf::FloatRect boundingBox = vertices.getBounds();
    if (boundingBox.contains(worldPos->x, worldPos->y))
    {
        std::cout << "COLISION" << std::endl;
        return true;
    }
    else
    {
        std::cout << "NO COLISION" << std::endl;
    }
    return 0;
}

