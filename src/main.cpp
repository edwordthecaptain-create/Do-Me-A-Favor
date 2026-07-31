#include "raylib.h"

int main() {
    // ทดลองสร้างหน้าต่าง Raylib ง่ายๆ เพื่อให้โปรแกรมรันได้
    InitWindow(800, 450, "Do Me A Favor - Test Window");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello Raylib!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}