#include <stdio.h>
#include <stdlib.h>

#include "raylib.h"
#include "constants.h"
#include "headers/graph.h"

typedef struct
{
    int columns;
    int rows;
    int step;
} graph;

graph *createGraph(const int rows, const int cols)
{
    graph *_graph = malloc(sizeof(graph));
    _graph->columns = cols;
    _graph->rows = rows;
    _graph->step = WINDOW_WIDTH / cols;
    return _graph;
}

void renderGraph(graph *_graph)
{
    int centerX = (_graph->columns / 2) * _graph->step + _graph->step / 2; // x-coordinate of the center
    int centerY = (_graph->rows / 2) * _graph->step + _graph->step / 2;    // y-coordinate of the center

    for (int i = 0; i < _graph->columns; i++)
    {
        for (int j = 0; j < _graph->rows; j++)
        {
            DrawRectangleLines(i * _graph->step, j * _graph->step, _graph->step, _graph->step, BLACK);
        }
    }

    DrawCircle(centerX, centerY, _graph->step / 4, RED); // Draw a circle at the center
}


void describeGraph(graph *_graph)
{
    printf("\nGraph : %d [columns], %d [rows]", _graph->columns, _graph->rows);
}

// ! ---------------------------------------------------------------------------------------- ! //

int main(int argc, char const *argv[])
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(60);
    graph *_graph = createGraph(20, 20);

    BeginDrawing();

    EndDrawing();


    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        renderGraph(_graph);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
