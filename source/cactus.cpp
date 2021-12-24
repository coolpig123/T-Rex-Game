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
    x-=2;
    if(x < 0){
        x = startingX;
    }
}
void cactus::collision(float playerX, float playerY,int playerWidth,int playerHeight,int screenWidth){
    if(x >= playerX && x <= playerX + playerWidth && y >= playerY && y <= playerY+playerHeight){
        x = screenWidth;
        cout << playerX << " " << playerY << endl;
        cout << x << " " << y << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        
    }else{
        move();
    }
}
void cactus::draw(){
    DrawRectangle(x,y,width,height,color);
}