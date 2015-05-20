#pragma once

#include <glut.h>

#include "Tile.h"

// TODO: Incorrectly declared walls

namespace sim {

class TileGraphic {

public:
    TileGraphic(const Tile* tile);
    void draw() const;
    void setColor(const GLfloat* color);
    void declareWall(Direction direction, bool isWall);
    void undeclareWall(Direction direction);

private:
    const Tile* m_tile;
    const GLfloat* m_color;
    std::map<Direction, bool> m_declaredWalls;
};

} // namespace sim
