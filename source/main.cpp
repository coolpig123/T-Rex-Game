
#include "raylib.h"
#include "../headers/player.h"
#include "../headers/cactus.h"
int main(void)
{
    int screenWidth = 900;
    int screenHeight = 450;
    int cactusVelocity = 4;
    int fps = 60;
    player Player(50,400,400,50,50,false,WHITE);
    cactus Cactus(430,900,20,20,BLUE);
    cactus CactusTwo(420,1200,40,30,GREEN);
    bool gameOver = false;
    InitWindow(screenWidth, screenHeight, "T-Rex-Game");
    SetTargetFPS(fps);               
    while (!WindowShouldClose()){
        BeginDrawing();
        if(!gameOver){
            ClearBackground(BLACK);
            DrawText(TextFormat("score : %i", Player.score),0,0,20,WHITE);
            DrawText(TextFormat("high score : %i", Player.highScore),0,20,20,WHITE);
            Player.draw();
            Cactus.draw();
            CactusTwo.draw();
            Cactus.move(cactusVelocity);
            CactusTwo.move(cactusVelocity);
            Player.jump();
            Player.down();
            Player.updateScore();
            if(Cactus.collision(Player.x,Player.y,Player.width,Player.height,screenWidth) || CactusTwo.collision(Player.x,Player.y,Player.width,Player.height,screenWidth)){
                gameOver = true;
            }
            if(Player.score % 500 == 0){
                cactusVelocity+=1;
            }
        }else{
            ClearBackground(BLACK);
            DrawText("Game Over!",screenWidth/2-150,screenHeight/2-40,50,WHITE);
            DrawText("Press space to start over",screenWidth/2-150,screenHeight/2+20,20,WHITE);
            DrawText(TextFormat("score : %i", Player.score),screenWidth/2-150,screenHeight/2+40,20,WHITE);
            if(IsKeyPressed(KEY_SPACE)){
                gameOver = false;
                Player.score = 0;
                cactusVelocity = 4;
                Cactus.x = Cactus.startingX;
                CactusTwo.x = CactusTwo.startingX;
            }
        }  
        EndDrawing();
    }
    CloseWindow();     
}