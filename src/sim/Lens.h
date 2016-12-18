#pragma once

#include <QVector>

#include "Maze.h"
#include "MazeGraphic.h"
#include "Mouse.h"
#include "MouseGraphic.h"
#include "TriangleGraphic.h"
#include "TriangleTexture.h"

namespace mms {

/**
 * This class represents the model as perceived by the mouse
 */
class Lens {

public:

    Lens(const Maze* maze, const Mouse* mouse);

    // TODO: MACK - we shouldn't have to expose these
    MazeGraphic* getMazeGraphic();
    MouseGraphic* getMouseGraphic();

    // TODO: MACK - rename this
    void initTileGraphicText(int numRows, int numCols);

    // TODO: MACK - const???
    // Return pointers to constant buffers, for rendering maps
    QVector<TriangleGraphic>* getGraphicCpuBuffer();
    QVector<TriangleTexture>* getTextureCpuBuffer();

private:

    // TODO: MACK - do any of these actually need to be heap-allocated?

    // CPU-side buffers and the interface to modify them
    QVector<TriangleGraphic> m_graphicCpuBuffer;
    QVector<TriangleTexture> m_textureCpuBuffer;
    BufferInterface* m_bufferInterface;

    // The model and graphic objects
    MazeGraphic* m_mazeGraphic;
    MouseGraphic* m_mouseGraphic;
};

} // namespace mms
