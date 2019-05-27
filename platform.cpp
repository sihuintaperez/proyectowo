#include "platform.h"
using namespace sf;
using namespace std;
platform::platform(Texture* texture,Vector2f size,Vector2f position)
{
    body.setSize(size);
    body.setOrigin(size / 2.0f);
    body.setTexture(texture);
    body.setPosition(position);

}

platform::~platform()
{
    //dtor
}
void platform::Draw(RenderWindow& window)
{
    window.draw(body);
}
