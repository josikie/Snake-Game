#ifndef FOOD_H
#define FOOD_H

#include <vector>
#include <memory>
#include "SDL.h"

//virtual class
class PrintTerminal{
  virtual void PrintToTheTerminal(std::string texts) const = 0;
};
// colors of the food
enum class TheColor {yellow, red};
class Food : PrintTerminal{
    public:

      //setter / getter
      std::string CheckTheColor();
      void SetColor(TheColor theColor);
      void Count();
      int GetCount();
      void ReduceCount();
      void PrintToTheTerminal(std::string texts) const;

      // variable for render
      SDL_Point foodBody;

    private:
      // _theColor is TheColor type for store color state of foods.
      TheColor _theColor;
      // _count is integer for store how many times snake ate the foods.
      int _count = 0;
      // _message is string for store text
      std::string _message;
};

#endif