#include "Collision.h"
using namespace sf;
Collision::Collision(RectangleShape& body):
    body(body)
{
}

Collision::~Collision()
{
    //dtor
}
 bool Collision::CheckCollision(Collision& other,Vector2f& direction){

    Vector2f otherPosition = other.GetPosition();
    Vector2f otherHalfSize = other.GetHalfSize();
    Vector2f thisPosition = GetPosition();
    Vector2f thisHalfSize = GetHalfSize();
    float deltax= otherPosition.x - thisPosition.x;
    float deltay= otherPosition.y - thisPosition.y;

    float intersectx=abs(deltax) - (otherHalfSize.x + thisHalfSize.x);
    float intersecty=abs(deltay) - (otherHalfSize.y + thisHalfSize.y);

    if(intersectx < 0.0f && intersecty < 0.0f)
    {

    if(intersectx > intersecty)
    {
            if(deltax >0.0f){
                direction.x=1.0f;
                direction.y=0.0f;
            }
            else{
                direction.x=-1.0f;
                direction.y=0.0f;
            }
        }
        else
        {
            if(deltay >0.0f){
                direction.x=0.0f;
                direction.y=1.0f;
            }
            else{
                direction.x=0.0f;
                direction.y=-1.0f;
            }
        }
        return true;
    }
    return false;
}
