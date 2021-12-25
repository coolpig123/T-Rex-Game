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
    downHeight = height - 0.5*height;
    initialHeight = height;
    downY = startingY ;  //(initialHeight-downHeight) add this is you want to squeeze the player
}
void player::jump(){
    if(!isJump && IsKeyDown(KEY_UP)){
        isJump = true;
        velocity = -20;
        acceleration = 0.4;
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
void player::down(){
    if(IsKeyDown(KEY_DOWN)){
        //height = downHeight; add this is you want to squeeze the player
        y = downY;
    }else{
        //height = initialHeight; add this is you want to squeeze the player
    }
}
void player::updateScore(){
    if(highScore<score){
        highScore = score;
    }
    score++;
}