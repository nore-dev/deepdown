#ifndef _LEVEL_HPP_
#define _LEVEL_HPP_

#include "raylib.h"
#include <stdint.h>

enum Block
{
    Empty,
    Fragile,
    HasGem,
    Wall,
    Ground,
    Platform,
};

static const uint8_t SECTION_WIDTH = 13;
static const uint8_t SECTION_HEIGHT = 28;
static const uint8_t SECTION_COUNT = 1;

static const uint8_t BLOCK_SIZE = 40;

class Level
{
public:
    Level();

    void draw();

    Block getBlock(int x, int y);
    void setBlock(int x, int y, Block block);

    Rectangle getRect(int x, int y);

private:
    Block m_Map[SECTION_HEIGHT * SECTION_COUNT][SECTION_WIDTH] = {Empty};
};

#endif
