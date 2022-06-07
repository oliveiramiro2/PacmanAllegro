#ifndef ENTITIES_H_INCLUDED
#define ENTITIES_H_INCLUDED

class Entities{
public:
    void setPosX(int value);
    void setPosY(int value);
    void setPositionMove(int value);
    int getPositionMove();
    int getPosX();
    int getPosY();
private:
    int posX, posY;
    int positionMove;
};

#endif // ENTITIES_H_INCLUDED
