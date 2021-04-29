#include <QCoreApplication>
#include <QDebug>
#include <QDBusConnection>
#include "sysdbusregister.h"
#include "monitor_key_event.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    a.setOrganizationName("Kylin Team");
    a.setApplicationName("system-bus-monitorkey-service");

    QDBusConnection systemBus = QDBusConnection::systemBus();
    if (!systemBus.registerService("com.monitorkey.systemdbus")){
        qCritical() << "QDbus register service failed reason:" << systemBus.lastError();
        //exit(1);
    }

    if (!systemBus.registerObject("/", new SysdbusRegister(), QDBusConnection::ExportAllSlots | QDBusConnection::ExportAllSignals)){
        qCritical() << "QDbus register object failed reason:" << systemBus.lastError();
        //exit(2);
    }
    qDebug() << "ok";
    MonitorKeyEvent monitorevent(argc,argv);
    return a.exec();
}
