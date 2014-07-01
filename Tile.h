#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Tile : public sf::Drawable, public sf::Transformable
{
    public:
        Tile(int width, int height);

        void setTexture(int IDTile, int ID);
        bool Colision(sf::Vector2f *worldPos);
    protected:
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
        {
            states.transform *= getTransform();
            states.texture = &textureTileset;

            target.draw(vertices, states);
        }

        sf::Vertex* tile;
        sf::VertexArray vertices;
        sf::Texture textureTileset;
};

#endif // TILE_H
