#include<iostream>
#include <cstdlib>
#include <ctime>
#include "GameHeaderEli.h"
#include "Leveling.h"

void MapGen(int a [5] [5]) //Map Generation
{
    srand(time(0));
	int staircoods [2];
	for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            if(i == 2 && j ==2)
            {
                
                    a [i] [j] = 1;
        
            }else{
                if ((rand()%99) <25)
                {
                    a [i] [j] = 2;
                }
            }
        }
    }

    staircoods [0] = rand () %4;
    staircoods [1] = rand () %4;

    while (staircoods[1] == 2 && staircoods[0] == 2 )
    {
        staircoods [0] = rand () %4;
        staircoods [1] = rand () %4;
    }

    a [staircoods[0]] [staircoods[1]] = 3;
	 for (size_t i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            std::cout << a[i][j];
        }
        std::cout << std::endl;
    }
}

void Movement (int map [5][5], int stats [6])
{
    std::string response;
    int px;
    int py;
    int x;
    int y;
    int floor = 1;
    int comp = 0;
    int stats [5];
    while (comp !=1)
    {
        std::cout << "What would you like to do: ";
        std::cin >> response;
        if (response == "right")
        {
            if(px+1 == 5)
            {
                std::cout << "You can not go right anymore\n";
            }else
            {
                    px = px +1;
            }
        }else if (response == "left")
        {
            if(px-1 == -1)
            {
                std::cout << "You can not go left anymore\n";
            }else
            {
                px = px -1;
            }
        }else if (response == "down")
        {
            if(py+1 == 5)
            {
                std::cout << "You can not go down anymore\n";
            }else
            {
                py = py +1;
            }
        }else if (response == "up")
        {
            if(py-1 == -1)
            {
                std::cout << "You can not go up anymore\n";
            }else
            {
                py = py -1;
            }
        }
        if (map[py][px] == 2)
        {
           // combat function  
           fight(stats, floor);   
        }else if ( map [py] [px] == 3)
        {
            floor +=1;
            MapGen(map);
        }
    }
}