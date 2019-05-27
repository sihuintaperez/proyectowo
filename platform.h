#ifndef PLATFORM_H
#define PLATFORM_H
#include<SFML/Graphics.hpp>
#include "Collision.h"
using namespace sf;
using namespace std;
class platform
{
    public:
        platform(Texture* texture,Vector2f size,Vector2f position);
        virtual ~platform();

        void Draw(RenderWindow& window);
        Collision getcollision(){return Collision(body);}

    private:
        RectangleShape body;
};

#endif // PLATFORM_H
