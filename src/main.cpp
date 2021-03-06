#include <QApplication>
#include <QIcon>
#include <QSettings>

#include "MainWindow.hpp"

constexpr int DEFAULT_WIDTH = 500;
constexpr int DEFAULT_HEIGHT = 600;

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    a.setOrganizationName("flatulation");
    a.setApplicationName("heatin");
    a.setWindowIcon(QIcon::fromTheme("utilities-system-monitor"));
    QSettings settings;
    const auto size = settings.value("main_size", QSize(DEFAULT_WIDTH, DEFAULT_HEIGHT)).value<QSize>();

    MainWindow w;
    w.resize(size);
    w.show();
    auto ret = a.exec();
    settings.setValue("main_size", w.size());
    return ret;
}
