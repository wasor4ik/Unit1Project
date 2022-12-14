#include <QCoreApplication>
#include <QLocale>
#include <QTranslator>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Hello world!" ;

    QCoreApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Unit1_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    return a.exec();
}
