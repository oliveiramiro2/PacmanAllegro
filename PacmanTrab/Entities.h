#ifndef ENTITIES_H_INCLUDED
#define ENTITIES_H_INCLUDED

class Entities{
public:
    void setPosX(float value);
    void setPosY(float value);
    void setPositionMove(int value);
    int getPositionMove();
    float getPosX();
    float getPosY();
private:
    float posX, posY;
    int positionMove;
};

#endif // ENTITIES_H_INCLUDED
