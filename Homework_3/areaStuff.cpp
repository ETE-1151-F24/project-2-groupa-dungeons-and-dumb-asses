#include "areaStuff.h" // this includes the contents of the [areaStuff.h] file while compiling
// the areaStuff.cpp file with have the definitions of my functions included within this

constexpr int squareArea(int side){                         //the area of a square is the sides multiplied together
    return side*side;
}
constexpr int rectangleArea(int length, int width){         //the area of a rectangle is length * width
    return length*width;
}
constexpr double circleArea(double radius){                 //the area of a circle is pi*(radius^2)
    return pi*radius*radius;
} 
constexpr double cylinderArea(double radius, double height){  //the volume of a cylinder is (2*(pi*(radius^2)))+(2*pi*radius*height)
    return (2*(pi*(radius*radius)))+(2*pi*radius*height);       //this is the surface area formula for a cylinder
}