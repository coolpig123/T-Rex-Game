#pragma once
#include "raylib.h"
class player{
    public:
        float x;
        float y;
        float startingY;
        int width;
        int height;
        float velocity;
        float acceleration;
        bool isJump;
        Color color;
        player(float xC,float yC,float startingYC,int widthC,int heightC,bool isJumpC,Color ColorC);
        void jump();
        void draw();
};
