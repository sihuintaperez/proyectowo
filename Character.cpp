#include "Character.h"
#include "Collision.h"

Character::Character(Texture* texture, Vector2u imageCount, float switchTime, float speed,float jumpheight):
    animation(texture, imageCount, switchTime)
{
    this->speed = speed;
    this->jumpheight=jumpheight;
    row = 0;
    faceRight= true;
    body.setSize(Vector2f(100.0f, 150.0f));
    body.setPosition(100.0f, -100.0f);
    body.setTexture(texture);
}

Player::Player(Texture* texture, Vector2u imageCount, float switchTime, float speed,float jumpheight):
    animation(texture, imageCount, switchTime), Character(texture, imageCount, switchTime, speed,jumpheight)
{
    this->speed = speed;
    row = 0;
    faceRight= true;
    body.setSize(Vector2f(100.0f, 150.0f));
    body.setPosition(-400.0f, 50.0f);
    body.setTexture(texture);
}

Character::~Character()
{
    //dtor
}

void Character::Update(float deltaTime)
{
    velocity.x=0.0f;

    if(Keyboard::isKeyPressed(Keyboard::A))
        velocity.x -= speed;

    if(Keyboard::isKeyPressed(Keyboard::D))
        velocity.x += speed;

    if(Keyboard::isKeyPressed(Keyboard::Space) && canjump)
    {
        velocity.y=-sqrtf(2.0f * 100.0f * jumpheight);
    }

    velocity.y +=100.0f * deltaTime;


    if(velocity.x == 0.0f)
    {
        row = 0;
    }
    else
    {
        row = 3;
        if(velocity.x > 0.0f)
            faceRight = true;
        else
            faceRight = false;
    }

    animation.Update(row, deltaTime, faceRight);
    body.setTextureRect(animation.uvRect);
    body.move(velocity * deltaTime);
}

void Character::Draw(RenderWindow& window)
{
    window.draw(body);
}
void Character::onCollision(Vector2f direction)
{
    if(direction.x < 0.0f)
    {
        velocity.x=0.0f;
    }
    else if (direction.x >0.0f)
    {
        velocity.x=0.0f;
    }
    if(direction.y >0.0f)
    {
        velocity.y=0.0f;
        canjump=true;
    }
    else if (direction.y >0.0f)
    {
        velocity.y=0.0f;
    }
}
