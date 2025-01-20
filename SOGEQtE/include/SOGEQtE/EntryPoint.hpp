#ifndef SOGEQTE_ENTRYPOINT_HPP
#define SOGEQTE_ENTRYPOINT_HPP

#include <SOGE/SOGE.hpp>


namespace sogeqte
{
    class SOGEQtEApp final : public soge::Engine
    {
    public:
        explicit SOGEQtEApp(AccessTag&& aTag);

        SOGEQtEApp(const SOGEQtEApp&) = delete;
        SOGEQtEApp& operator=(const SOGEQtEApp&) = delete;

        SOGEQtEApp(SOGEQtEApp&&) = delete;
        SOGEQtEApp& operator=(SOGEQtEApp&&) = delete;

        ~SOGEQtEApp() override;

        void Load(AccessTag) override;

    };
}

#endif // !SOGEQTE_ENTRYPOINT_HPP
