#ifndef PLAYSPACE_HPP
#define PLAYSPACE_HPP

#include<ctime>
#include<cstdlib>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include"game.hpp"
#include"checkCheck.hpp"
#include"counter.hpp"
#include"leaderboard.hpp"
//displaying time
#include<string>
#include<sstream>
#include<iomanip>

namespace patch
{
    template<typename T>std::string to_string(const T& n)
    {
        std::ostringstream stm;
        stm<<n;
        return stm.str();
    }
}

void wait()
{
    sf::Clock clock;
    sf::Time time;
    time=clock.getElapsedTime();
    while(time.asSeconds()!=1)
        time=clock.getElapsedTime();
}

int randCol(){
    int x=rand()%256;
    return x;
}

struct col{
    int R=randCol();
    int G=randCol();
    int B=randCol();
};

void playSpace(const int* ans)
{
    extern int x;
    bool draw=true;
    bool start=false;

    int min_elapsed;
    int sec_elapsed;

    sf::Clock clock;
    sf::Time elapsed=clock.restart();

    sf::Font font;
    font.loadFromFile("times.ttf");
    sf::Text dis_time;
    dis_time.setFont(font);
    dis_time.setCharacterSize(30);

    //waiting 3 secs befor game begin


    srand(time(0));
    int* playSpace = new int[x*x];
    const int screen=(x+(x+1)/2)*32;
    sf::RenderWindow window(sf::VideoMode(screen,screen),"Picross");

    int windowWidthpos=sf::VideoMode::getDesktopMode().width/2-screen/2;
    int windowHeightpos=sf::VideoMode::getDesktopMode().height/2-screen/2;

    window.setPosition(sf::Vector2i(windowWidthpos,windowHeightpos));

    Game* table = new Game;
    table->defaultTile(x*x,playSpace);

    row(ans,x,table);
    column(ans,x,table);

    if(!table->load("tileset.png",sf::Vector2u(32,32),playSpace,x))
        return;

    col color;

    while(window.isOpen())
    {
        //get bounds
        sf::FloatRect bounds=dis_time.getLocalBounds();

        if(draw)
            elapsed=clock.getElapsedTime();

        sf::Event event;
        while(window.pollEvent(event))
        {
            window.setKeyRepeatEnabled(false);
            sf::Vector2i position=sf::Mouse::getPosition(window);

            //get precise position of mouse in the screen to use with playSpace
            int tileWidth=window.getSize().x/((3*x+1)/2);
            int tileHeight=window.getSize().y/((3*x+1)/2);
            int u=(position.x-((x+1)/2)*tileWidth)/tileWidth;
            int v=(position.y-((x+1)/2)*tileHeight)/tileHeight;
            //

            if(event.type==sf::Event::Closed)
            {
                window.close();
                delete[] playSpace;
            }

            if(event.type==sf::Event::Resized)
            {
                window.setSize(sf::Vector2u(window.getSize().x,window.getSize().y));
            }

            //press Z and LMB to fill tile
            if(draw&&start)
            {
                //update  time

                if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        //prevent to stop working
                        if(u>=0&&v>=0&&u<x&&v<x)
                        {
                            *(playSpace+(u+v*x))=1;
                            if(!table->load("tileset.png",sf::Vector2u(32,32),playSpace,x))
                                return;
                        }
                    }
                //press X and LMB to cross(mark that we don't need this tile) tile
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        //prevent to stop working
                        if(u>=0&&v>=0&&u<x&&v<x)
                        {
                            *(playSpace+(u+v*x))=2;
                            if(!table->load("tileset.png",sf::Vector2u(32,32),playSpace,x))
                                return;
                        }
                    }
                //press C and LMB to clear tile
                if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))
                    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
                    {
                        //prevent to stop working
                        if(u>=0&&v>=0&&u<x&&v<x)
                        {
                            *(playSpace+(u+v*x))=0;
                            if(!table->load("tileset.png",sf::Vector2u(32,32),playSpace,x))
                                return;
                        }
                    }
            }
        }
        //clear space and draw table
        window.clear(sf::Color(color.R,color.G,color.B));
        if(draw)
            window.draw(*table);

        //draw time
        int nm_elapsed=elapsed.asSeconds()/60;
        int ns_elapsed=(int)elapsed.asSeconds()%60;

        if(start&&draw)
        {
            dis_time.setString(((nm_elapsed>9)?patch::to_string(nm_elapsed):"0"+patch::to_string(nm_elapsed))+":"+((ns_elapsed>9)?patch::to_string(ns_elapsed):"0"+patch::to_string(ns_elapsed)));
        }
        else
        {
            dis_time.setString(patch::to_string(3-ns_elapsed));
            if(ns_elapsed==3)
            {
                clock.restart();
                start=true;
            }
        }

        if(checkMain(ans, playSpace, x))
        {
            draw=false;
        }

        if(!draw)
        {
            color.R=0;
            color.G=0;
            color.B=0;

            min_elapsed=nm_elapsed;
            sec_elapsed=ns_elapsed;
            dis_time.setString("You complete\nthis PICROSS!\n\nClose this window to record your score");
        }
        if(bounds.width>window.getSize().x)
        {
            dis_time.setScale(window.getSize().x/bounds.width,window.getSize().x/bounds.width);
        }

        window.draw(dis_time);

        //displaying all stuffs
        window.display();
    }

    if(!draw)
        if(setScore(min_elapsed*60+sec_elapsed,x))
        {
            std::cout << "You set new high score\n";
        }
}
#endif
