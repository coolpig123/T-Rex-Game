#include "../headers/player.h"
#include "raylib.h"
#include <iostream>
player::player(float xC,float yC,float startingYC,int widthC,int heightC,bool isJumpC,Color colorC){
    x = xC;
    y = yC;
    startingY = startingYC;
    width = widthC;
    height  = heightC;
    isJump  = isJumpC;
    color  = colorC;
}
void player::jump(){
    if(!isJump && IsKeyDown(KEY_SPACE)){
        isJump = true;
        velocity = -20;
        acceleration = 0.5;
        
    }else if(isJump){
        velocity += acceleration;
        velocity += acceleration;
        y += velocity;
    }
    if(y > startingY){
        y = startingY;
        velocity = 0;
        isJump = false;
    }
    
}
void player::draw(){
    DrawRectangle(x,y,width,height,color);
}