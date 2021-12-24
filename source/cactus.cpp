#include "raylib.h"
#include "../headers/cactus.h"
#include <chrono>
#include <thread>
#include <iostream>
using namespace std;
cactus::cactus(float yC,float xC,float widthC,float heightC,Color colorC){
    x = xC;
    startingX = xC;
    y = yC;
    width = widthC;
    height = heightC;
    color = colorC;
}
void cactus::move(){
    x-=4;
    if(x < 0-width){
        x = startingX;
    }
}
bool cactus::collision(float playerX, float playerY,int playerWidth,int playerHeight,int screenWidth){
    if(CheckCollisionRecs(Rectangle{x,y,(float)width,(float)height},Rectangle{playerX,playerY,(float)playerWidth,(float)playerHeight})){
        x = screenWidth;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        return true;
    }else{
        move();
        return false;
    }
}
void cactus::draw(){
    DrawRectangle(x,y,width,height,color);
}