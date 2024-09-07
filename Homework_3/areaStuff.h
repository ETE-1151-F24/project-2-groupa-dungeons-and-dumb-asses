#ifndef AREASTUFF_H       //if my [areaStuff.h] isnt already defined...
#define AREASTUFF_H       //then define [AREASTUFF_H] with the following code lines as seen below
//i need to make [constant expressions] for area for square, rectangles, or circles, cylinders,
//area of a square = side*side
//area of a rectangle = length * width
// area of a circle = pi*(radius^2) = pi*radius*radius which will need to be a double because pi has so many decimal places
// area of a cylinder = pi*radius*radius*height which will need to be a double because pi has so many decimal places
// also need a constant expression for pi which will need to be a double because pi has so many decimal places

constexpr double pi = 3.14159265358979323846;  
// Constexpr ensures the value of pi is computed at compile-time and double allows it to be many decimal places

constexpr int squareArea(int side); //parameter for this function is [side]
constexpr int rectangleArea(int length, int width); //parameter for this function is [length] and [width]
constexpr double circleArea(double radius); //parameter for this function is [radius] and its a [double] since it is interacting with pi
constexpr double cylinderArea(double radius, double height);//paramet of funct are [radius] and [height] are [double]s since pi interaction 
//this is my constant expressions declarations of my  individual functions that i will expand on in the [areaStuff.cpp] file


//this is the statement to end the definition of the [areaStuff.h]
#endif // AREASTUFF_H