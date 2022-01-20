#include "Player.hpp"

Player::Player()
{
    TraceLog(LOG_DEBUG, "GAME: Player created!");
}

void Player::draw()
{
    DrawRectangleRec(m_Rect, RAYWHITE);
}

void Player::update()
{
}