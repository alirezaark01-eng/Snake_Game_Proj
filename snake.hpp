#ifndef SNAKE_HPP
#define SNAKE_HPP


#include <conio.h>
#include <iostream>
#include <vector>
#include <algorithm>


struct Position
{
    int x , y ;

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
            gameOver = false;
            currentDir = Direction::RIGHT;
        
            snake.push_back({WIDTH/2, HEIGHT/2});
        
            food = {5, 5};
        }

        void clear_screen(){
            system("cls") ;
        }

        void draw (){
            clear_screen() ;

            std::cout << "==== SNAKE GAME ====\n" ;
            std::cout << "====================\n" ;
            
            std::cout << "snake lenght :" << snake.size() << std::endl;
            std::cout << "snake head position: (" << snake[0].x << "," << snake[0].y << ")\n" ; 
            
            std::cout << "food position : (" << food.x << "," << food.y << ")\n" ;

            std::cout << "score: " << score << std::endl


            std::cout << "current direction: ";
            switch (currentDir)
            {
                case Direction::up :
                    std::cout << "UP" ;
                    break;
            
                case Direction::DOWN :
                    std::cout << "DOWN" ;
                    break;
            
                case Direction::LEFT :
                    std::cout << "LEFT" ;
                    break;

                case Direction::RIGHT :
                    std::cout << "RIGHT" ;
                    break;
            }
            std::cout << std::cout << std::endl ;

            std::cout << "\n simple board ...!" ;
            std::cout << "S = snake head , F = food , . = empty space\n\n" ;

            for (int y = 0 ; y<HEIGHT ; y++){
                for(int x = 0 ; x < WIDTH ; x++){
                    Position currentpos = {x,y} ;

                    if (snake[0] == currentpos){
                        std::cout << "S " ;
                    }
                    else if (food == currentpos)
                    {
                        std::cout << "F " ;
                    }
                    else{
                        std::cout << ". " ;
                    }
                std::cout << std::endl ;
                    
                }
            }
            std::cout << "\n===================\n";
            std::cout << "CONTROLS:\n";
            std::cout << "W = Up, S = Down, A = Left, D = Right\n";
            std::cout << "X = Exit game\n";
            std::cout << "=====================\n";
        }


        void input(){

            if (_kbhit()) {
                char key = _getch() ;

                key = tolower(key) ;

                std::cout << "\nkey pressed :" << key << std::endl ;

                switch (key)
                {
                case 'w':
                    std::cout << "command : Move UP\n" ;
                    break;

                case 's':
                    std::cout << "command : Move DOWN\n" ;
                    break;
                
                case 'a':
                    std::cout << "command : Move LEFT\n" ;
                    break;

                case 'd':
                    std::cout << "command : Move RIGHT\n" ;
                    break;

                case 'x' :
                    gameOver = true
                    std::cout << "command : EXIT game\n" ;
                    break;

                default :
                    std::cout << "Invalid key! :|"

                }
            for (int i = 0 ; i < 1000000 ; i++) ;

            }

        }
        void test_debug(){
            std::cout << "\n=== this is a test for debug ===\n"
            std::cout << "number of snake segments: " << snake.size() << std::endl;
            std::cout << "is game over ?" << (gameOver ? "yes" : "no") << std::endl ;

        }

        void run ;
        void logic ;
        void generate_food ;
    };

#endif
