#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "raylib.h"
#include <stdint.h>

class Player
{
public:
    Player();

    void update();
    void draw();

private:
    Rectangle m_Rect = {40, 40, 30, 50};

    uint8_t m_Health = 6;
    uint8_t m_MaxHealt = 6;

    float m_Velocity = 10;

    bool m_Jumped = false;
};

#endif