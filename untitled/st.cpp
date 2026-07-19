#include<QQmlApplicationEngine>
#include<QGuiApplication>
int main(int argc, char *argv[])
{

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;


    //

    QUrl url ("../../QQml.qml");
    engine.load(url);
    //


    return app.exec();
}