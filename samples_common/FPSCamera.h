#pragma once

#include <df3d.h>

class FPSCamera : public df3d::scene::Camera
{
    float m_velocity = 0.0f;

    int m_yaw = 0, m_pitch = 0;
    int m_prevx = 0, m_prevy = 0;

    void moveForward(float step);
    void moveBackward(float step);
    void moveLeft(float step);
    void moveRight(float step);
    void move(const glm::vec3 &vec);

public:
    FPSCamera(float velocity);
    ~FPSCamera();

    void onRightMouseDown(int x, int y);
    void onRightMouseUp(int x, int y);
    void onMouseMotionEvent(int x, int y, bool rightButtonPressed);
    void onMouseWheel(int delta);
};
