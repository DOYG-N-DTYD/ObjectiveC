//
//  main.c
//  Start
//
//  Created by Miroslaw Zborowski on 23/12/2025.
//
//  float, double, char, int, long int, uint
//  bool
//  struct, pointer
//  if/else, ternary
//  functions
//  while, for

//  SHORTCUTS
//  windows + /     comment lines of codes
//  ctrl + I        select first lines of code and then format

// w b w b w b    w b w b w b
// V V V V V V || V V V V V V
//
// ^ ^ ^ ^ ^ ^ || ^ ^ ^ ^ ^ ^
// b w b w b w    b w b w b w

#include <stdio.h>
#include <raylib.h>

#define amountTriangles 24  // 6+6 top 6+6 bottom

typedef struct Triangle{
    Vector2 v1;
    Vector2 v2;
    Vector2 v3;
    Color c1; // balck or yellow (for yellow define A opacity)
} Triangle;

const int screenWidth = 800;
const int screenHeight = 450;
const char gameName[] = "Short nards";

Triangle createTriangle(float v1_x, float v1_y,float v2_x, float v2_y,float v3_x, float v3_y){
    Triangle triangle;
    triangle.v1.x = v1_x;
    triangle.v1.y = v1_y;
    triangle.v2.x = v2_x;
    triangle.v2.y = v2_y;
    triangle.v3.x = v3_x;
    triangle.v3.y = v3_y;
    return triangle;
}

Triangle *initArrayOfTraingles(Triangle *AllBoardTriangles){
    
    // upper first triangle
    float Vector1_X = 1.0;
    float Vector1_Y = 1.0;
    float Vector2_X = 25.0;
    float Vector2_Y = 150.0;
    float Vector3_X = 50.0;
    float Vector3_Y = 0.0;
    for (int i = 0; i < 12; i++){
        AllBoardTriangles[i] = createTriangle(Vector1_X, Vector1_Y, Vector2_X, Vector2_Y,Vector3_X,Vector3_Y);
        AllBoardTriangles[i].c1 = YELLOW;
        Vector1_X += 50.0;
        Vector2_X += 50.0;
        Vector3_X += 50.0;
        if(i % 2 == 0) AllBoardTriangles[i].c1 = YELLOW; else
            AllBoardTriangles[i].c1 = BLACK;
    }
    
    Vector1_X = 0.0;
    Vector1_Y = 450;//(float)screenHeight;
    Vector2_X = 50.0;
    Vector2_Y = 450;//(float)screenHeight - 150.0;
    Vector3_X = 25.0;
    Vector3_Y = 300.0;
    for (int i = 12; i < 24; i++){
        AllBoardTriangles[i] = createTriangle(Vector3_X,Vector3_Y,Vector2_X, Vector2_Y,Vector1_X, Vector1_Y);
        AllBoardTriangles[i].c1 = BLACK;
        Vector1_X += 50.0;
        Vector2_X += 50.0;
        Vector3_X += 50.0;
        if(i % 2 == 0) AllBoardTriangles[i].c1 = BLACK; else
            AllBoardTriangles[i].c1 = YELLOW;
    }
    return AllBoardTriangles;
}

void drawBoard(Triangle *AllBoardTriangles){
    for (int i = 0; i<12; i++) {
        DrawTriangle(AllBoardTriangles[i].v1, AllBoardTriangles[i].v2, AllBoardTriangles[i].v3, AllBoardTriangles[i].c1);
    }
    for (int i = 12; i<24; i++) {
        DrawTriangle(AllBoardTriangles[i].v3, AllBoardTriangles[i].v2, AllBoardTriangles[i].v1, AllBoardTriangles[i].c1);
    }
}

void testRaylib(){
    
    InitWindow(screenWidth, screenHeight, gameName);
    struct Triangle AllBoardTriangles[amountTriangles]; // init all triangles as structures in array of structures
    struct Triangle *p_AllBoardTriangles = &AllBoardTriangles; // get pointer 1 structure in array
    
    p_AllBoardTriangles = initArrayOfTraingles(p_AllBoardTriangles);
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        //DrawText("Welcome to raylib!", 190, 200, 20, LIGHTGRAY);
        drawBoard(p_AllBoardTriangles);
        EndDrawing();
    }
    CloseWindow();
}

int main(int argc, const char * argv[]) {
    testRaylib();
    return 0;
}
