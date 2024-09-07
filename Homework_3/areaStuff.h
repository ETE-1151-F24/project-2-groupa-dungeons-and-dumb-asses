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

//this is my constant expressions declarations of my  individual functions that i will expand on in the [areaStuff.cpp] file

constexpr int squareArea(int side); 
constexpr int rectangleArea(int length, int width);
constexpr double circleArea(double radius);
constexpr double cylinderArea(double radius, double height);



//this is the statement to end the definition of the [conversionStuff.h]
#endif // CONVERSIONSTUFF_H