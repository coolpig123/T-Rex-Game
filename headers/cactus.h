#pragma once
#include "raylib.h"
class cactus{
    public:
        float x;
        float y;
        float startingX;
        int width;
        int height;
        Color color;
        cactus(float yC,float xC,float widthC,float heightC,Color colorC);
        void move();
        void collision(float playerX, float playerY,int playerWidth,int playerHeight,int screenWidth);
        void draw();
};