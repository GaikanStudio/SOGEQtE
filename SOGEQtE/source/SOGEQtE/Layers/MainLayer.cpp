#include "SOGEQtE/Layers/MainLayer.hpp"

// int main(int argc, char** argv)
//{
//     auto app = new sogeqte::QTEApplication(argc, argv, "SOGEEditor");
//     return app->Run();
// }


namespace sogeqte
{
    MainLayer::MainLayer() : Layer("MainLayer")
    {
        int a = 0;
        app = new QTEApplication(a, nullptr, "SOGEQtE");
        app->Run();
    }

    MainLayer::~MainLayer()
    {
    }

    void MainLayer::OnAttach()
    {
    }

    void MainLayer::OnDetach()
    {
        app->GetGUIApplication()->exec();
    }

    void MainLayer::OnUpdate()
    {
        app->GetGUIApplication()->processEvents();
    }

    void MainLayer::OnFixedUpdate(float aDeltaTime)
    {
    }
}
