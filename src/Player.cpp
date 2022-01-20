#include "Player.hpp"

Player::Player()
{
    TraceLog(LOG_DEBUG, "GAME: Player created!");
}

Rectangle Player::getRect()
{
    return m_Rect;
}

void Player::draw()
{
    DrawRectangleRec(m_Rect, RAYWHITE);
}

void Player::update()
{
    float oldPosition = m_Rect.x;

    if (IsKeyDown(KEY_A))
        m_Rect.x -= m_Velocity * GetFrameTime();

    if (IsKeyDown(KEY_D))
        m_Rect.x += m_Velocity * GetFrameTime();

    oldPosition = m_Rect.y;

    if (IsKeyDown(KEY_W))
        m_Rect.y -= m_Velocity * GetFrameTime();

    if (IsKeyDown(KEY_S))
        m_Rect.y += m_Velocity * GetFrameTime();
}

Vector2 Player::getPosition()
{
    return {m_Rect.x, m_Rect.y};
}

void Player::m_SetPosition(Vector2 pos)
{
    m_Rect.x = pos.x;
    m_Rect.y = pos.y;
}
