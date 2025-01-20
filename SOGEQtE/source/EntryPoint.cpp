#include "SOGEQtE/EntryPoint.hpp"
#include "SOGEQtE/Layers/MainLayer.hpp"

#include <SOGE/Core/EntryPoint.hpp>


namespace sogeqte
{
    SOGEQtEApp::SOGEQtEApp(AccessTag&& aTag) : Engine(std::move(aTag))
    {
        SOGE_APP_INFO_LOG("Initialize SOGEQtE App");
    }

    SOGEQtEApp::~SOGEQtEApp()
    {
        SOGE_APP_INFO_LOG("Destroying SOGEQtE App");
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    void SOGEQtEApp::Load(AccessTag)
    {
        this->PushLayer(new MainLayer());
    }
}

soge::Engine* soge::CreateApplication()
{
    return Engine::Reset<sogeqte::SOGEQtEApp>();
}
