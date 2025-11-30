#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
    robot_status_t robot;

    robot.direction = direction;
    robot.position.x = x;
    robot.position.y = y;

    return (robot);
}

void    rotate(robot_status_t *robot, char turn)
{
    if (turn == 'R' && robot->direction == 3)
        robot->direction = 0;
    else if (turn == 'R')
        robot->direction++;
    else if (turn == 'L' && robot->direction == 0)
        robot->direction = 3;
    else if (turn == 'L')
        robot->direction--;
}

void    advance(robot_status_t *robot)
{
    if (robot->direction == 0)
        robot->position.y++;
    else if (robot->direction == 1)
        robot->position.x++;
    else if (robot->direction == 2)
        robot->position.y--;
    else if (robot->direction == 3)
        robot->position.x--;
}

void robot_move(robot_status_t *robot, const char *commands)
{
    int     i;

    i = 0;
    while (commands && commands[i])
    {
        if (commands[i] == 'A')
        {
            advance(robot);
            i++;
        }
        else if (commands[i] == 'R' || commands[i] == 'L')
        {
            rotate(robot, commands[i]);
            i++;
        }
        else
            i++;
    }
}
