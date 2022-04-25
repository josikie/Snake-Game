#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)) {
  PlaceFood();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food, food2);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count, food2.GetCount(), food.GetCount());
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.foodBody.x = x;
      food.foodBody.y = y;
      // set the color food to yellow as food
      food.SetColor(TheColor::yellow);
      return;
    }
  }
}

void Game::PlacePoison(){
  int x, y;
  while(true){
    x = random_w(engine);
    y = random_h(engine);

    if(!snake.SnakeCell(x,y)){
      food2.foodBody.x = x;
      food2.foodBody.y = y;
      
      // set the poison food color to red
      food2.SetColor(TheColor::red);
      return;
    }
  }
}

void Game::Update() {
  if (!snake.alive) return;

  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.foodBody.x == new_x && food.foodBody.y == new_y) {
    PlaceFood();

    // check the color, and print to the terminal whether snake eat food or poison
    food.PrintToTheTerminal(food.CheckTheColor());

    // count
    food.Count();

    // increase the score
    score++;
    
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;

  }

  // check if there is poison over here
  if(food2.foodBody.x == new_x && food2.foodBody.y == new_y){
    PlacePoison();

    // check the color, and print to the terminal whether snake eat food or poison
    food2.PrintToTheTerminal(food2.CheckTheColor());

    // count 
    food2.Count();

    // check if the foods have been eated atleast 1, if foods that has been eated more than 0, decrease the count 
    if(food.GetCount() > 0){
      food.ReduceCount();
    }

    // check if the score more than 
    if(score > 0){
      score--;
    }

    // if the poisons that have been eated more than foods that have been eated, the snake is dead
    if(food2.GetCount() > food.GetCount()){
      std::cout << "Sorry, the snake is dead, you eated poisons more than the foods, stay safe from poisons. Try again! \n";
      snake.alive = false;
    }
  }
}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }

// GetCountFood1() get the number of foods that have been eated by snake
int Game::GetCountFood1() { return food.GetCount(); }
// GetCountFood2() get the number of poisons that have been eated by snake
int Game::GetCountFood2() { return food2.GetCount(); }