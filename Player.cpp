#include "Player.h"
#include "raylib.h"

void Player::Draw()
{
    DrawCircle(m_circle_x, m_circle_y, m_radius, BLUE);
}

void Player::UpdateMovement(int& width, int& height)
{
    // Circle Boundries
    bool left_boundry   {m_circle_x - m_radius > 0};
    bool right_boundry  {m_circle_x + m_radius < width};
    bool top_boundry    {m_circle_y - m_radius > 0};
    bool bottom_boundry {m_circle_y + m_radius < height};


    // Update circle position based on input
    if (IsKeyDown(KEY_D) && right_boundry) {
        m_circle_x += m_speed;
    }
    if (IsKeyDown(KEY_A)&& left_boundry) {
        m_circle_x -= m_speed;
    }
    if (IsKeyDown(KEY_W) && top_boundry) {
        m_circle_y -= m_speed;
    }
    if (IsKeyDown(KEY_S) && bottom_boundry) {
        m_circle_y += m_speed;
    }

    // Circle edges 
    circle_left   =  {m_circle_x - m_radius};
    circle_right  =  {m_circle_x + m_radius};
    circle_top    =  {m_circle_y - m_radius};
    circle_bottom =  {m_circle_y + m_radius};
}