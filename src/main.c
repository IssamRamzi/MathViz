#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "raylib.h"
#include "constants.h"

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
    for (int i = 0; i < _graph->columns; i++) // dessine le graphe
    {
        for (int j = 0; j < _graph->rows; j++)
        {
            DrawRectangleLines(i * _graph->step, j * _graph->step, _graph->step, _graph->step, BLACK);
        }
    }
    Vector2 mainLineXStart = {0,WINDOW_HEIGHT /2};
    Vector2 mainLineXEnd = {WINDOW_WIDTH,WINDOW_HEIGHT /2};

    Vector2 mainLineYStart = {WINDOW_WIDTH /2,0};
    Vector2 mainLineYEnd = {WINDOW_WIDTH / 2,WINDOW_HEIGHT};

    Vector2 i_start = {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2};
    Vector2 i_end = {WINDOW_WIDTH / 2 + _graph->step, WINDOW_HEIGHT / 2};

    Vector2 j_start = {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2};
    Vector2 j_end = {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 - _graph->step};

    DrawText("-->\n J ",WINDOW_WIDTH / 2 - 35,WINDOW_HEIGHT / 2 - 50,20,GREEN);
    DrawText("-->\n I ",WINDOW_WIDTH / 2 + 30,WINDOW_HEIGHT / 2 - 40,20,GREEN);

    DrawLineEx(mainLineXStart, mainLineXEnd, 4, BLACK); // Dessine la ligne (0) X
    DrawLineEx(mainLineYStart, mainLineYEnd, 4, BLACK); // Dessine la ligne (0) Y

    DrawLineEx(i_start, i_end, 4, GREEN); // Dessine le vecteur I
    DrawLineEx(j_start, j_end, 4, GREEN); // Dessine le vecteur J
    DrawCircle(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 10, RED); // Dessine le point (0,0)
    DrawText("(0,0)", WINDOW_WIDTH / 2 + 10, WINDOW_HEIGHT / 2 + 5, 20, RED); // Dessine le text (0,0)
}

void describeGraph(graph *_graph)
{
    printf("\nGraph : [columns] %d ,[rows] %d \n", _graph->columns, _graph->rows);
}

// ? ---------------------------------------------------------------------------------------- ? //


#define BUFFER_SIZE 1024
char *getMathFunctionInput()
{
    char *string = malloc(BUFFER_SIZE);
    if (string == NULL)
    {
        printf("Memory allocation failed!");
        exit(EXIT_FAILURE);
    }
    printf("\nEnter your math function: ");
    fgets(string, 1024, stdin);
    // ENlever le retour a la ligne et mettre '\0' a la place
    if (string[strlen(string) - 1] == '\n')
        string[strlen(string) - 1] = '\0';
    printf("\n");
    return string;
}






// ! ---------------------------------------------------------------------------------------- ! //

int main(int argc, char const *argv[])
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(60);
    system("clear");

    graph *_graph = createGraph(10, 10);
    describeGraph(_graph);

    char *userInput = getMathFunctionInput();
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        renderGraph(_graph);

        EndDrawing();
    }

    printf("\n\n");
    CloseWindow();
    free(_graph);
    free(userInput);
    return 0;
}
