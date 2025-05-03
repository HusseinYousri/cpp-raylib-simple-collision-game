#pragma once   

class Player
{
    
public:
    
    // Constructor to initialize the Player object with circle properties
    Player(int circle_x, int circle_y, int radius, int speed)
    {
        m_circle_x   = circle_x;
        m_circle_y   = circle_y;
        m_radius     = radius;
        m_speed      = speed;
    };



    // Public Functions
    const int& GetCircleLeft()     const  { return circle_left;   };
    const int& GetCircleRight()    const  { return circle_right;  };
    const int& GetCircleTop()      const  { return circle_top;    };
    const int& GetCircleBottom()   const  { return circle_bottom; };

    // Function to draw the circle on the screen
    void Draw();
    // Function to update the circle's position based on user input and screen boundaries
    void UpdateMovement(int& width, int& height);

private:
    
    // Variables

    // Circle properties
    int m_circle_x;
    int m_circle_y;
    int m_radius;
    int m_speed;

    // Circle edges
    int circle_left;
    int circle_right;
    int circle_top;
    int circle_bottom;
};