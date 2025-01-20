#ifndef SOGEQTE_LAYERS_MAINLAYER_HPP
#define SOGEQTE_LAYERS_MAINLAYER_HPP

#include <SOGE/SOGE.hpp>


namespace sogeqte
{
    class MainLayer final : public soge::Layer
    {
    public:
        explicit MainLayer();
        ~MainLayer();

        void OnAttach() override;
        void OnDetach() override;

        void OnUpdate() override;
        void OnFixedUpdate(float aDeltaTime) override;

    };
}

#endif // !SOGEQTE_LAYERS_MAINLAYER_HPP
