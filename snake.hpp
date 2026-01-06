#ifndef SNAKE_HPP
#define SNAKE_HPP


#include<conio.h>
#include<iostream>
#include<vector>


struct Position
{
    bool operator == (const Position & other) const {
        return x == other.x && y == other.y;
    }
};

enum class Direction { UP, DOWN, LEFT, RIGHT };


class Game {
    private:
        const int WIDTH = 20;
        const int HEIGHT = 20;
        std::vector<Position> snake;
        Direction currentDir;
        Position food;
        int score;
        bool gameOver;


    public:
        Game() {
            score = 0;
             = false;
            currentDir = Direction::RIGHT;
        
            snake.push_back({WIDTH/2, HEIGHT/2});
        
            food = {5, 5};
        }


        void draw;
        void input ;
        void run ;
        void logic ;
        void generate_food ;
    };

#endif
