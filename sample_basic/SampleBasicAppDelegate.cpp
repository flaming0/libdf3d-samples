#include "SampleBasicAppDelegate.h"

#include "FPSCamera.h"

void SampleBasicAppDelegate::initScene()
{
    auto scene = make_shared<df3d::scene::Scene>();
    auto camera = make_shared<FPSCamera>(1.0f);

    g_sceneManager->setCurrentScene(scene);
    g_sceneManager->setCamera(camera);

    g_physicsWorld->setGravity({ 0, -10, 0 });

    camera->transform()->setPosition(0.0f, 0.0f, 5.0f);

    auto teapot = make_shared<df3d::scene::Node>();
    teapot->attachComponent(make_shared<df3d::components::MeshComponent>("teapot.obj"));
    //teapot->attachComponent(make_shared<df3d::components::PhysicsComponent>(df3d::components::PhysicsComponent::CreationParams()));

    // Add lights.
    auto light = make_shared<df3d::scene::Node>();
    light->attachComponent(make_shared<df3d::components::LightComponent>(df3d::components::LightComponent::Type::DIRECTIONAL));
    light->light()->setDirection({ 0.0f, 0.0f, -1.0f });

    g_sceneManager->addNodeToScene(teapot);
    g_sceneManager->addNodeToScene(light);
}

SampleBasicAppDelegate::SampleBasicAppDelegate()
{

}

SampleBasicAppDelegate::~SampleBasicAppDelegate()
{

}

df3d::platform::AppInitParams SampleBasicAppDelegate::getAppInitParams() const
{
    df3d::platform::AppInitParams params;
    params.windowWidth = 1024;
    params.windowHeight = 768;
    params.fullscreen = false;

    return params;
}

bool SampleBasicAppDelegate::onAppStarted(int windowWidth, int windowHeight)
{
    df3d::base::glog << "Initializing SampleBasicAppDelegate with screen size" << windowWidth << "x" << windowHeight << df3d::base::logmess;

    df3d::base::EngineInitParams params;
    params.windowWidth = windowWidth;
    params.windowHeight = windowHeight;
    if (!g_engineController->init(params))
        return false;

    df3d::render::MaterialLib::Defines.push_back("HIGH_QUALITY");

    initScene();

    return true;
}

void SampleBasicAppDelegate::onAppEnded()
{
    g_engineController->shutdown();
}

void SampleBasicAppDelegate::onAppPaused()
{

}

void SampleBasicAppDelegate::onAppResumed()
{

}

void SampleBasicAppDelegate::onAppUpdate(float dt)
{
    g_engineController->update(dt, dt);
    g_engineController->postUpdate();
    g_engineController->runFrame();
}

void SampleBasicAppDelegate::onTouchEvent(const df3d::base::TouchEvent &touchEvent)
{

}

void SampleBasicAppDelegate::onMouseButtonEvent(const df3d::base::MouseButtonEvent &mouseButtonEvent)
{

}

void SampleBasicAppDelegate::onMouseMotionEvent(const df3d::base::MouseMotionEvent &mouseMotionEvent)
{

}

void SampleBasicAppDelegate::onMouseWheelEvent(const df3d::base::MouseWheelEvent &mouseWheelEvent)
{

}

void SampleBasicAppDelegate::onKeyUp(const df3d::base::KeyboardEvent::KeyCode &code)
{

}

void SampleBasicAppDelegate::onKeyDown(const df3d::base::KeyboardEvent::KeyCode &code)
{

}
