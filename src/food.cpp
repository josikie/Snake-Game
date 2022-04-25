#include "food.h"
#include <iostream>

// CheckTheColor() check the food's color, whether is red or yellow then return the message
std::string Food::CheckTheColor(){
    if(_theColor == TheColor::yellow){
        _message = "Good! Snake eat the food! The food increases, the score increases";
    }else{
        _message = "Oops! Snake eat the poison! The food decreases, the score decreases";
    }
    return _message;
}

void Food::PrintToTheTerminal(std::string message) const{
    std::cout << message << "\n";
}

// SetColor() is void, but has parameter TheColor, 
// SetColor() take TheColor to assign it to private member variable _theColor.
void Food::SetColor(TheColor theColor){
    _theColor = theColor;
}

// Count() increase _count by one when it's called (usually called when the snake ate the food).
void Food::Count(){
    _count++;
}

// GetCount() return _count (how many food that the snake ate)
int Food::GetCount(){
    return _count;
}

// ReduceCount() decrease _count by one
void Food::ReduceCount(){
    _count--;
}