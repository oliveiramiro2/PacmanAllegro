#ifndef ENTITIES_H_INCLUDED
#define ENTITIES_H_INCLUDED

class Entities{
public:
    void setPosX(float value);
    void setPosY(float value);
    float getPosX();
    float getPosY();
private:
    float posX, posY;
};

#endif // ENTITIES_H_INCLUDED
