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

void Player::update(Level &level)
{

    Vector2 oldPosition = getPosition();

    if (IsKeyDown(KEY_A))
        m_Rect.x -= m_Velocity * GetFrameTime();

    if (IsKeyDown(KEY_D))
        m_Rect.x += m_Velocity * GetFrameTime();

    m_HandleCollision(oldPosition, level);

    oldPosition = getPosition();

    m_Rect.y += 5;

    m_HandleCollision(oldPosition, level);
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

void Player::m_HandleCollision(Vector2 &oldPosition, Level &level)
{
    // TODO: Find a better way
    int x = m_Rect.x / BLOCK_SIZE;
    int y = m_Rect.y / BLOCK_SIZE;

    for (int yo = -1; yo < 2; yo++)
    {
        for (int xo = -1; xo < 2; xo++)
        {
            if (level.getBlock(x + xo, y + yo) && CheckCollisionRecs(m_Rect, level.getRect(x + xo, y + yo)))
            {
                m_SetPosition(oldPosition);
                oldPosition = getPosition();

                TraceLog(LOG_DEBUG, "Colllision Detected");
                return;
            }
        }
    }
}
