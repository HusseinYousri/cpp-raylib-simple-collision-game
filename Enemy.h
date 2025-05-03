#pragma once

class Enemy
{

public:

    // Constructor to initialize the Enemy object with rectangle properties
    Enemy(const int& rect_x, const int& rect_y, const int& rect_width, const int& rect_height, const int& rect_speed)
    {
        m_rect_x      = rect_x;
        m_rect_y      = rect_y;
        m_rect_width  = rect_width;
        m_rect_height = rect_height;
        m_rect_speed  = rect_speed;

        m_enemycount++; // Increment enemy count when a new enemy is created
    }

    // Public Functions
    const int& GetRectLeft()     const  { return rect_left;   };
    const int& GetRectRight()    const  { return rect_right;  };
    const int& GetRectTop()      const  { return rect_top;    };
    const int& GetRectBottom()   const  { return rect_bottom; };
    const static int& GetEnemyCount() { return m_enemycount; }; // Static function to get enemy count

    // Function to draw the rectangle on the screen
    void Draw();

    // Function to update the rectangle's position based on screen boundaries
    void UpdateMovement(int& width, int& height);

private:

    static int m_enemycount; // Static variable to track enemy count

    // Rectangle properties
    int m_rect_x;
    int m_rect_y;
    int m_rect_width;
    int m_rect_height;
    int m_rect_speed;

    // Rectangle edges
    int rect_left;
    int rect_right;
    int rect_top;
    int rect_bottom;
};