#include "Level.hpp"
#include <random>

Level::Level()
{
    // TODO: Delete
    for (int y = 5; y < SECTION_HEIGHT * SECTION_COUNT; y++)
    {
        for (int x = 0; x < SECTION_WIDTH; x++)
        {
            if (rand() % 5 == 1)
                setBlock(x, y, Ground);
        }
    }
}

void Level::draw()
{
    for (int y = 0; y < SECTION_HEIGHT * SECTION_COUNT; y++)
    {
        for (int x = 0; x < SECTION_WIDTH; x++)
        {
            if (getBlock(x, y) != Empty)
                DrawRectangleRec(getRect(x, y), BLUE);
        }
    }
}

Block Level::getBlock(int x, int y)
{
    return m_Map[y][x];
}

void Level::setBlock(int x, int y, Block block)
{
    m_Map[y][x] = block;
}

Rectangle Level::getRect(int x, int y)
{
    return {(float)x * BLOCK_SIZE, (float)y * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE};
}