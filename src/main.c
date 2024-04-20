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
    for (int i = 0; i < _graph->columns; i++)
    {
        for (int j = 0; j < _graph->rows; j++)
        {
            DrawRectangleLines(i * _graph->step, j * _graph->step, _graph->step, _graph->step, BLACK);
        }
    }
    Vector2 i_start = {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2};
    Vector2 i_end = {WINDOW_WIDTH / 2 + _graph->step, WINDOW_HEIGHT / 2};

    Vector2 j_start = {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2};
    Vector2 j_end = {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 - _graph->step};

    DrawText("-->\n J ",WINDOW_WIDTH / 2 - 35,WINDOW_HEIGHT / 2 - 50,20,GREEN);
    DrawText("-->\n I ",WINDOW_WIDTH / 2 + 30,WINDOW_HEIGHT / 2 - 40,20,GREEN);

    DrawLineEx(i_start, i_end, 4, GREEN);
    DrawLineEx(j_start, j_end, 4, GREEN);
    DrawCircle(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 10, RED);
    DrawText("(0,0)", WINDOW_WIDTH / 2 + 10, WINDOW_HEIGHT / 2 + 5, 20, RED);
}

void describeGraph(graph *_graph)
{
    printf("\nGraph : %d [columns], %d [rows]\n", _graph->columns, _graph->rows);
}

// ! ---------------------------------------------------------------------------------------- ! //

int main(int argc, char const *argv[])
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(60);
    system("clear");

    graph *_graph = createGraph(10, 10);
    describeGraph(_graph);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        renderGraph(_graph);

        EndDrawing();
    }

    printf("\n\n");
    CloseWindow();

    return 0;
}
