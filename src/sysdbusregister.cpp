#include "sysdbusregister.h"
#include "monitor_key_event.h"
#include <QDBusConnection>
#include <QDBusError>
#include <QDBusMessage>
#include <QDebug>

SysdbusRegister::SysdbusRegister()
{
}

SysdbusRegister::~SysdbusRegister()
{

}

int SysdbusRegister::exitService()
{
    qApp->exit(0);
    return 0;
}

QString SysdbusRegister::monitor_key()
{
    /*创建QT的DBus信号*/
    QDBusMessage message =QDBusMessage::createSignal("/", "com.ukui.test.interface", "uktest");
    message<<"tttest";
    QDBusConnection::systemBus().send(message);
    QString ba ="test2";
    return QString(ba);
}
