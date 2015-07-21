#pragma once

#include <df3d.h>

class SampleBasicAppDelegate : public df3d::platform::AppDelegate
{
public:
    SampleBasicAppDelegate();
    ~SampleBasicAppDelegate();

    df3d::platform::AppInitParams getAppInitParams() const override;

    bool onAppStarted(int windowWidth, int windowHeight) override;
    void onAppEnded() override;
    void onAppPaused() override;
    void onAppResumed() override;

    void onAppUpdate(float dt) override;
    void onTouchEvent(const df3d::base::TouchEvent &touchEvent) override;
    void onMouseButtonEvent(const df3d::base::MouseButtonEvent &mouseButtonEvent) override;
    void onMouseMotionEvent(const df3d::base::MouseMotionEvent &mouseMotionEvent) override;
    void onMouseWheelEvent(const df3d::base::MouseWheelEvent &mouseWheelEvent) override;
    void onKeyUp(const df3d::base::KeyboardEvent::KeyCode &code) override;
    void onKeyDown(const df3d::base::KeyboardEvent::KeyCode &code) override;
};
