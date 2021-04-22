#ifndef SYSDBUSREGISTER_H
#define SYSDBUSREGISTER_H

#include <QtDBus/QDBusContext>
#include <QObject>
#include <QCoreApplication>
#include <QProcess>
#include <QFile>
#include <QSettings>

class SysdbusRegister : public QObject, protected QDBusContext
{
    Q_OBJECT
    Q_CLASSINFO("D-Bus Interface", "com.monitorkey.interface")
public:
    SysdbusRegister();
    ~SysdbusRegister();

public slots:
    Q_SCRIPTABLE int exitService();
    Q_SCRIPTABLE QString monitor_key();
};

#endif // SYSDBUSREGISTER_H
