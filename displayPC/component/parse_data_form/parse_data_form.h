#ifndef PARSE_DATA_FORM_H
#define PARSE_DATA_FORM_H

#include "./truck_param.h"

#include "yaml-cpp/yaml.h"

#include <iostream>
#include <fstream>

#include <QCoreApplication>
#include <QMap>
#include <QMessageBox>
#include <QString>
#include <QVector>
#include <QWidget>

namespace Ui
{
  class ParseDataForm;
}

class ParseDataForm : public QWidget
{
  Q_OBJECT

public:
  explicit ParseDataForm(QWidget *parent = 0);
  ~ParseDataForm();

private slots:
  void on_comboBox_currentIndexChanged(int index);

  void on_save_param_clicked();

private:
  QMap<std::string, TruckParam> truck_paramm;
  QVector<TruckParam> truck_paramv;
  YAML::Node config;
  Ui::ParseDataForm *ui;
  bool init();
  bool initTruckParam();
  //  bool updateIndex(int index);
};

#endif // PARSE_DATA_FORM_H
