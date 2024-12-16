#ifndef SOGE_WIDGETS_MAINWINDOW_HPP
#define SOGE_WIDGETS_MAINWINDOW_HPP

#include <QtWidgets/QMainWindow.h>

// ADS/DockManager
#include <DockManager.h>

namespace Ui
{
    class MainWindow;
}

namespace sogeqte
{

    class QTEMainWindow : public QMainWindow
    {
        Q_OBJECT

    private:
        Ui::MainWindow* m_genUi;

        // Main docking container
        ads::CDockManager* m_dockManager;

    public:
        explicit QTEMainWindow(QWidget* aParent = nullptr);
        ~QTEMainWindow();


    };
}

#endif // !SOGE_WIDGETS_MAINWINDOW_HPP
