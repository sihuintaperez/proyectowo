#include <iostream>
#include <SFML/Graphics.hpp>
#include "Character.h"
#include "platform.h"
using namespace sf;
using namespace std;

static const float viewHeight = 600;
void ResizeView(const RenderWindow& window, View& view)
{
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(viewHeight * aspectRatio, viewHeight);
}

int main()
{
    RenderWindow window(VideoMode(1200, 600), "SFML works!", Style::Resize | Style::Close);
    View view(Vector2f(0.0f,0.0f), Vector2f(1200, 600));

    Texture player1Texture;
    player1Texture.loadFromFile("boy1.png");

    Player player1(&player1Texture, Vector2u(4,4), 0.3f, 600.0f,100.0f);

    float deltaTime = 0.0f;
    Clock clock;

    platform platform1(nullptr,Vector2f(1600.0f,10.0f),Vector2f(500.0f,-300.0f) );

    while (window.isOpen() )
    {

        deltaTime = clock.restart().asSeconds();
        Event evnt;
        while (window.pollEvent(evnt))
        {
            switch(evnt.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::Resized:
                ResizeView(window, view);
                break;
            }
        }

        player1.Update(deltaTime);


        Collision menber=player1.GetCollision();
        Vector2f direction;
        if(platform1.getcollision().CheckCollision(menber,direction))
        {
           player1.onCollision(direction);
        }
        /*
       if (Keyboard::isKeyPressed(Keyboard::Up)){player.move(0.f,-0.1f);}
       if (Keyboard::isKeyPressed(Keyboard::Down)){player.move(0.f,0.1f);}
       if (Keyboard::isKeyPressed(Keyboard::Left)){player.move(-0.1f,0.f);}
       if (Keyboard::isKeyPressed(Keyboard::Right)){player.move(0.1f,0.f);}
        */

        window.clear();
        window.setView(view);
        player1.Draw(window);
        platform1.Draw(window);
        window.display();
    }

    return 0;
}
