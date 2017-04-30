#include "game.hpp"
#include<iostream>

void Game::defaultTile(unsigned int space, int* table)
{
    //making blank table
    while(space--)
    {
        *(table+space)=0;
    }
}
//making hint to player
bool Game::columnHint(const std::string& tileset,sf::Vector2u tileSize, const int* r, unsigned int width, unsigned int height)
{

    //load tileset texture
    if(!c_tileset.loadFromFile(tileset))
        return false;

    //resize vertex array to fit window size
    c_vertices.setPrimitiveType(sf::Quads);
    c_vertices.resize(width*height*4);

    //populate the vertex array, with one quad per tile
    for(unsigned int i=0;i<width;++i)
        for(unsigned int j=0;j<height;++j)
        {
            const int sx=((width+1)/2)*tileSize.x;

            //get current tile number
            int tileNumber=*(r+i+j*width);

            //find its position in the tileset texture
            int tu=tileNumber%(c_tileset.getSize().x/tileSize.x);
            int tv=tileNumber/(c_tileset.getSize().x/tileSize.x);

            //get pointer to current tile's quad
            sf::Vertex* quad=&c_vertices[(i+j*width)*4];

            //define 4 corner
            quad[0].position=sf::Vector2f(i*tileSize.x+sx,j*tileSize.y);
            quad[1].position=sf::Vector2f((i+1)*tileSize.x+sx,j*tileSize.y);
            quad[2].position=sf::Vector2f((i+1)*tileSize.x+sx,(j+1)*tileSize.y);
            quad[3].position=sf::Vector2f(i*tileSize.x+sx,(j+1)*tileSize.y);

            //define its 4 texture coordinates
            quad[0].texCoords=sf::Vector2f(tu*tileSize.x,tv*tileSize.y);
            quad[1].texCoords=sf::Vector2f((tu+1)*tileSize.x,tv*tileSize.y);
            quad[2].texCoords=sf::Vector2f((tu+1)*tileSize.x,(tv+1)*tileSize.y);
            quad[3].texCoords=sf::Vector2f(tu*tileSize.x,(tv+1)*tileSize.y);
        }
        return true;
}
bool Game::rowHint(const std::string& tileset,sf::Vector2u tileSize, const int* c, unsigned int width, unsigned int height)
{
    //load tileset texture
    if(!r_tileset.loadFromFile(tileset))
        return false;

    //resize vertex array to fit window size
    r_vertices.setPrimitiveType(sf::Quads);
    r_vertices.resize(width*height*4);

    //populate the vertex array, with one quad per tile
    for(unsigned int i=0;i<width;++i)
        for(unsigned int j=0;j<height;++j)
        {
            const int sy=((height+1)/2)*tileSize.y;

            //get current tile number
            int tileNumber=*(c+i+j*width);

            //find its position in the tileset texture
            int tu=tileNumber%(r_tileset.getSize().x/tileSize.x);
            int tv=tileNumber/(r_tileset.getSize().x/tileSize.x);

            //get pointer to current tile's quad
            sf::Vertex* quad=&r_vertices[(i+j*width)*4];

            //define 4 corner
            quad[0].position=sf::Vector2f(i*tileSize.x,j*tileSize.y+sy);
            quad[1].position=sf::Vector2f((i+1)*tileSize.x,j*tileSize.y+sy);
            quad[2].position=sf::Vector2f((i+1)*tileSize.x,(j+1)*tileSize.y+sy);
            quad[3].position=sf::Vector2f(i*tileSize.x,(j+1)*tileSize.y+sy);

            //define its 4 texture coordinates
            quad[0].texCoords=sf::Vector2f(tu*tileSize.x,tv*tileSize.y);
            quad[1].texCoords=sf::Vector2f((tu+1)*tileSize.x,tv*tileSize.y);
            quad[2].texCoords=sf::Vector2f((tu+1)*tileSize.x,(tv+1)*tileSize.y);
            quad[3].texCoords=sf::Vector2f(tu*tileSize.x,(tv+1)*tileSize.y);
        }
        return true;
}

bool Game::load(const std::string& tileset,sf::Vector2u tileSize,const int* table, unsigned int width)
{
    //load tileset texture
    if(!m_tileset.loadFromFile(tileset))
        return false;

    //resize vertex array to fit window size
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width*width*4);

    //populate the vertex array, with one quad per tile
    for(unsigned int i=0;i<width;++i)
        for(unsigned int j=0;j<width;++j)
        {
            const int sx=((width+1)/2)*tileSize.x;
            const int sy=((width+1)/2)*tileSize.y;

            //get current tile number
            int tileNumber=*(table+i+j*width);

            //find its position in the tileset texture
            int tu=tileNumber%(m_tileset.getSize().x/tileSize.x);
            int tv=tileNumber/(m_tileset.getSize().x/tileSize.x);

            //get pointer to current tile's quad
            sf::Vertex* quad=&m_vertices[(i+j*width)*4];

            //define 4 corner
            quad[0].position=sf::Vector2f(i*tileSize.x+sx,j*tileSize.y+sy);
            quad[1].position=sf::Vector2f((i+1)*tileSize.x+sx,j*tileSize.y+sy);
            quad[2].position=sf::Vector2f((i+1)*tileSize.x+sx,(j+1)*tileSize.y+sy);
            quad[3].position=sf::Vector2f(i*tileSize.x+sx,(j+1)*tileSize.y+sy);

            //define its 4 texture coordinates
            quad[0].texCoords=sf::Vector2f(tu*tileSize.x,tv*tileSize.y);
            quad[1].texCoords=sf::Vector2f((tu+1)*tileSize.x,tv*tileSize.y);
            quad[2].texCoords=sf::Vector2f((tu+1)*tileSize.x,(tv+1)*tileSize.y);
            quad[3].texCoords=sf::Vector2f(tu*tileSize.x,(tv+1)*tileSize.y);
        }
        return true;
}
void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
        //apply transform
        states.transform*=getTransform();

        //apply tileset texture
        states.texture=&m_tileset;
        //draw vertex array
        target.draw(m_vertices,states);

        states.texture=&r_tileset;
        target.draw(r_vertices,states);

        states.texture=&c_tileset;
        target.draw(c_vertices,states);
}
