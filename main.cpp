#include <iostream>
/////
#include "includes/raylib.h"
#include "includes/raymath.h"
#include "includes/rcamera.h"
///
#include "src/button.cpp"
#include "src/variables.hpp"
////
int main() {
  InitWindow(VARIABLES::screenWidth, VARIABLES::screenHeight, "Button Example");

  BUTTON myButton("Click Me!", {100, 100, 200, 50}, RED, 20);

  SetTargetFPS(60);

  // Main game loop
  while (!WindowShouldClose()) {
    // Update
    // Check if the button is clicked
    if (myButton.IsClicked()) {
      // Do something when the button is clicked
      // For example, print a message
      printf("Button Clicked!\n");
    }

    // Draw
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Draw the button
    myButton.Draw();

    EndDrawing();
  }

  // De-Initialization
  CloseWindow();

  return 0;
}