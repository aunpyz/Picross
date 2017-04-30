#ifndef GAME_HPP
#define GAME_HPP

#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<string>

class Game :public sf::Drawable, public sf::Transformable
{
public:
    void defaultTile(unsigned int, int*);
    bool load(const std::string&, sf::Vector2u, const int*, unsigned int);
    bool rowHint(const std::string&, sf::Vector2u, const int*, unsigned int, unsigned int);
    bool columnHint(const std::string&, sf::Vector2u, const int*, unsigned int, unsigned int);
private:
    virtual void draw(sf::RenderTarget&, sf::RenderStates)const;
    sf::VertexArray m_vertices;
    sf::VertexArray c_vertices;
    sf::VertexArray r_vertices;
    sf::Texture m_tileset;
    sf::Texture c_tileset;
    sf::Texture r_tileset;
};
#endif
