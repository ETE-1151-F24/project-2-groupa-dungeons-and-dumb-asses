#ifndef AREASTUFF_H             //if my [areaStuff.h] isnt already defined...
#define AREASTUFF_H             //then define [AREASTUFF_H] with the following code lines as seen below
                                //i need to make [constant expressions] for area for square, rectangles, or circles, cylinders,
                                //area of a square = side*side
                                //area of a rectangle = length * width
                                // area of a circle == pi*radius*radius which will need to be a double because pi has so many decimal places
                                // area of a cylinder = pi*radius*radius*height ([double] ***because pi has high precision needs***)


constexpr double pi = 3.14159265358979323846;  
// [constexpr] ensures the value of pi is computed at compile-time and double allows for many decimal places

constexpr int squareArea(int side);                             //parameter this function is [side]
constexpr int rectangleArea(int length, int width);             //parameter this function is [length] and [width]
constexpr double circleArea(double radius);                     //parameter this function is [radius] and is [double] since with ***pi***
constexpr double cylinderArea(double radius, double height);     //parameter are [radius] and [height] are [double]s since ***pi*** interaction 

//^^^this is my constant expressions declarations of my  individual functions that i will expand on in the [areaStuff.cpp] file^^^


//this is the statement to end the definition of the [areaStuff.h]
#endif // AREASTUFF_H