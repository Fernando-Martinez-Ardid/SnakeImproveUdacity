#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
//New
#include <string>

#include "SDL.h"
#include "snake.h"

//New
struct Score;

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  void Render(Snake const snake, SDL_Point const &food, const std::vector<Score>& leaderboard); //Add last part
  void UpdateWindowTitle(int score, int fps);
  void RenderDirectText(const char* text, int x, int y);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;

  //New

  int text_width{0};
  int text_height{0};
};

#endif