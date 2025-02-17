#include "mainwindow.h"
#include <QApplication>
#include <QObject>
#include <QProcess>

#include <global_definition.h>
// #include <SavePcd.h>
#include <string>

std::thread *rosThread;
QSettings *settings; // 申明一个QSetting类函数

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  w.OutPut("have created main window");

  settings = new QSettings("../config/config.ini", QSettings::IniFormat); // 构建函数
  w.OutPut("have read configuration");

  return a.exec();
}
