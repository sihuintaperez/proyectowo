#ifndef CHARACTER_H
#define CHARACTER_H
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collision.h"
class Character
{
    public:
        Character(Texture* texture, Vector2u imageCount, float switchTime, float speed,float jumpheight);
        Character();
        ~Character();
        void Update(float deltaTime);
        void Draw(RenderWindow& window);

        void onCollision(Vector2f direction);

        Vector2f GetPosition() {return body.getPosition();}

        Collision GetCollision(){return Collision(body); }


    private:
        RectangleShape body;
        Animation animation;
        unsigned int row;
        float speed;
        bool faceRight;

        Vector2f velocity;
        bool canjump;
        float jumpheight;

};

class Player : virtual public Character
{
    public:
        Player(Texture* texture, Vector2u imageCount, float switchTime, float speed,float jumpheight);
    private:
        RectangleShape body;
        Animation animation;
        unsigned int row;
        float speed;
        bool faceRight;


};

#endif // CHARACTER_H
