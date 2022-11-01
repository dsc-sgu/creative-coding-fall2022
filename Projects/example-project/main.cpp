#include <raylib-ext.hpp>

int main()
{
    const int screen_width = 640;
    const int screen_height = 480;

    InitWindow(screen_width, screen_height, "Creative Coding: Welcome!");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        {
            ClearBackground(BLACK);
            int font_size = 30;
            std::string msg = "Welcome, Creative Coders!";
            int x = (screen_width - MeasureText(msg, font_size)) / 2;
            int y = (screen_height - font_size) / 2;
            DrawText(msg, x, y, font_size, WHITE);
        }
        EndDrawing();
    }
    CloseWindow();

    return 0;
}
