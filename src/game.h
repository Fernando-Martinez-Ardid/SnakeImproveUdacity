#ifndef GAME_H
#define GAME_H

#include <random>
//New
#include <vector>
#include <string>

#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"

//New
struct Score {
  std::string playerName;
  int score;
};

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer, std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;

  //New
  void SaveLeaderboardToFile(const std::string &filename);
  void LoadLeaderboardFromFile(const std::string &filename);
 private:
  //New
  std::vector<Score> leaderboard;
  
  Snake snake;
  SDL_Point food;

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood();
  void Update();
  //New
  void UpdateLeaderboard(const std::string &playerName, int playerScore);
};

#endif