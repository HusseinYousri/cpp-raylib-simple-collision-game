#include "Enemy.h"
#include "raylib.h"


int Enemy::m_enemycount = 0; // Initialize static variable outside the class definition

void Enemy::Draw()
{
    DrawRectangle(m_rect_x, m_rect_y, m_rect_width, m_rect_height, RED);
}

void Enemy::UpdateMovement(int& width, int& height)
{
    // Apply Speed to the rectangle on Y-axis
    m_rect_y += m_rect_speed;

    // Rectangle Boundries
    bool rect_top_boundry       {m_rect_y < 0};
    bool rect_bottom_boundry    {m_rect_y + m_rect_height > height};

    // Reverse direction if it hits the top or bottom of the screen
    if (rect_top_boundry || rect_bottom_boundry) {
        m_rect_speed *= -1;
    }

    // Rectangle edges
    rect_left   =  {m_rect_x};
    rect_right  =  {m_rect_x + m_rect_width};
    rect_top    =  {m_rect_y};
    rect_bottom =  {m_rect_y + m_rect_height};
}