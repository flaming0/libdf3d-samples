#include "FPSCamera.h"

void FPSCamera::moveForward(float step)
{
    move(getDir() * step);
}

void FPSCamera::moveBackward(float step)
{
    move(-getDir() * step);
}

void FPSCamera::moveLeft(float step)
{
    move(-getRight() * step);
}

void FPSCamera::moveRight(float step)
{
    move(getRight() * step);
}

void FPSCamera::move(const glm::vec3 &vec)
{
    transform()->setPosition(transform()->getPosition() + vec);
}

FPSCamera::FPSCamera(float velocity)
    : m_velocity(velocity)
{
}

FPSCamera::~FPSCamera()
{
}

void FPSCamera::onRightMouseDown(int x, int y)
{
    m_prevx = x;
    m_prevy = y;
}

void FPSCamera::onRightMouseUp(int x, int y)
{
    m_prevx = x;
    m_prevy = y;
}

void FPSCamera::onMouseMotionEvent(int x, int y, bool rightButtonPressed)
{
    static const float DAMPING = 0.3f;

    if (rightButtonPressed)
    {
        int dx = x - m_prevx;
        int dy = y - m_prevy;

        m_yaw += dx * DAMPING;
        m_pitch += dy * DAMPING;

        if (abs(m_yaw) > 360) m_yaw %= 360;
        if (m_pitch > 90) m_pitch = 90;
        if (m_pitch < -90) m_pitch = -90;

        transform()->setOrientation(glm::vec3((float)-m_pitch, (float)-m_yaw, 0.0f));
    }

    m_prevx = x;
    m_prevy = y;
}

void FPSCamera::onMouseWheel(int delta)
{
    if (delta > 0)
        moveForward(m_velocity);
    else
        moveBackward(m_velocity);
}
