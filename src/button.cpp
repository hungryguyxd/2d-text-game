#include <../includes/raylib.h>

struct BUTTON {
  BUTTON(const char* text, Rectangle bounds, Color color, int fontSize)
      : text(text), bounds(bounds), color(color), fontSize(fontSize) {
    // Load the font
    font = LoadFontEx("path/to/your/font.ttf", fontSize, nullptr, 0);
  }

  ~BUTTON() {
    // Unload the font
    UnloadFont(font);
  }

  void Draw() {
    // Draw the button
    DrawRectangleRec(bounds, color);
    DrawTextEx(font, text, (Vector2){bounds.x + 10, bounds.y + 10}, fontSize, 1,
               BLACK);
  }

  bool IsClicked() {
    // Check if the button is clicked
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
      Vector2 mousePos = GetMousePosition();
      if (CheckCollisionPointRec(mousePos, bounds)) {
        return true;
      }
    }
    return false;
  }
  Rectangle bounds;  // Button's position and size
  Color color;       // Button's color
  const char* text;  // Button's text
  int fontSize;      // Font size for the button text
  Font font;         // Font used for the button text
};