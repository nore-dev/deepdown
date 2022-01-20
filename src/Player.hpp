#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "raylib.h"
#include "Level.hpp"
#include <stdint.h>

class Player
{
public:
    Player();

    Rectangle getRect();

    void update(Level &level);
    void draw();

    Vector2 getPosition();

private:
    Rectangle m_Rect = {40, 40, 20, 30};

    uint8_t m_Health = 6;
    uint8_t m_MaxHealt = 6;

    float m_Velocity = 200;

    bool m_Jumped = false;

    void m_SetPosition(Vector2 pos);
    void m_HandleCollision(Vector2 &oldPosition, Level &level);
};

#endif