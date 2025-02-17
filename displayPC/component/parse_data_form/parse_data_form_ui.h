
#ifndef PARSE_DATA_FORM_UI_H
#define PARSE_DATA_FORM_UI_H

#include <QtCore/QVariant>
#include <QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ParseDataForm
{
public:
  QComboBox *comboBox;
  QLabel *select_truck;
  QLabel *record_time1;
  QLineEdit *record_time2;
  QGroupBox *truck_param_group;
  QWidget *truck_param_widget;
  QGridLayout *show_layout;
  QLabel *ip1;
  QLineEdit *ip2;
  QLabel *lf1;
  QLineEdit *lf2;
  QPushButton *save_param;
  QLabel *bf1;
  QLineEdit *lb2;
  QLabel *save_path1;
  QLineEdit *save_path2;
  QGroupBox *operation_group;
  QWidget *operation_layout_widget;
  QGridLayout *operation_layout;
  QPushButton *start;
  QPushButton *end;
  QPushButton *parse;
  QPushButton *transmit;
  QPushButton *allAuto;
  QCheckBox *checkBox;
  QProgressBar *progress_bar;

  void setupUi(QWidget *ParseDataForm)
  {
    if (ParseDataForm->objectName().isEmpty())
    {
      ParseDataForm->setObjectName(QStringLiteral("ParseDataForm"));
    }
    ParseDataForm->resize(359, 650);
    comboBox = new QComboBox(ParseDataForm);
    comboBox->setObjectName(QStringLiteral("comboBox"));
    comboBox->setGeometry(QRect(120, 20, 141, 25));
    select_truck = new QLabel(ParseDataForm);
    select_truck->setObjectName(QStringLiteral("select_truck"));
    select_truck->setGeometry(QRect(30, 20, 67, 17));
    record_time1 = new QLabel(ParseDataForm);
    record_time1->setObjectName(QStringLiteral("record_time1"));
    record_time1->setGeometry(QRect(30, 60, 67, 17));
    record_time2 = new QLineEdit(ParseDataForm);
    record_time2->setObjectName(QStringLiteral("record_time2"));
    record_time2->setGeometry(QRect(120, 60, 191, 25));
    truck_param_group = new QGroupBox(ParseDataForm);
    truck_param_group->setObjectName(QStringLiteral("truck_param_group"));
    truck_param_group->setGeometry(QRect(30, 100, 291, 281));
    truck_param_widget = new QWidget(truck_param_group);
    truck_param_widget->setObjectName(QStringLiteral("truck_param_widget"));
    truck_param_widget->setGeometry(QRect(10, 30, 271, 201));
    show_layout = new QGridLayout(truck_param_widget);
    show_layout->setObjectName(QStringLiteral("show_layout"));
    show_layout->setContentsMargins(0, 0, 0, 0);

    ip1 = new QLabel(truck_param_widget);
    ip1->setObjectName(QStringLiteral("ip1"));
    show_layout->addWidget(ip1, 0, 0, 1, 1);
    ip2 = new QLineEdit(truck_param_widget);
    ip2->setObjectName(QStringLiteral("ip2"));
    show_layout->addWidget(ip2, 0, 1, 1, 1);

    lf1 = new QLabel(truck_param_widget);
    lf1->setObjectName(QStringLiteral("lf1"));
    show_layout->addWidget(lf1, 1, 0, 1, 1);
    lf2 = new QLineEdit(truck_param_widget);
    lf2->setObjectName(QStringLiteral("lf2"));
    show_layout->addWidget(lf2, 1, 1, 1, 1);

    save_param = new QPushButton(truck_param_widget);
    save_param->setObjectName(QStringLiteral("save_param"));
    show_layout->addWidget(save_param, 4, 0, 1, 2);

    bf1 = new QLabel(truck_param_widget);
    bf1->setObjectName(QStringLiteral("bf1"));
    show_layout->addWidget(bf1, 2, 0, 1, 1);

    lb2 = new QLineEdit(truck_param_widget);
    lb2->setObjectName(QStringLiteral("lb2"));
    show_layout->addWidget(lb2, 2, 1, 1, 1);

    save_path1 = new QLabel(truck_param_widget);
    save_path1->setObjectName(QStringLiteral("save_path1"));
    show_layout->addWidget(save_path1, 3, 0, 1, 1);

    save_path2 = new QLineEdit(truck_param_widget);
    save_path2->setObjectName(QStringLiteral("save_path2"));
    show_layout->addWidget(save_path2, 3, 1, 1, 1);

    operation_group = new QGroupBox(ParseDataForm);
    operation_group->setObjectName(QStringLiteral("operation_group"));
    operation_group->setGeometry(QRect(30, 390, 291, 161));
    operation_layout_widget = new QWidget(operation_group);
    operation_layout_widget->setObjectName(QStringLiteral("operation_layout_widget"));
    operation_layout_widget->setGeometry(QRect(10, 30, 271, 121));
    operation_layout = new QGridLayout(operation_layout_widget);
    operation_layout->setObjectName(QStringLiteral("operation_layout"));
    operation_layout->setContentsMargins(0, 0, 0, 0);

    start = new QPushButton(operation_layout_widget);
    start->setObjectName(QStringLiteral("start"));
    operation_layout->addWidget(start, 0, 0, 1, 1);

    end = new QPushButton(operation_layout_widget);
    end->setObjectName(QStringLiteral("end"));
    operation_layout->addWidget(end, 0, 1, 1, 1);

    parse = new QPushButton(operation_layout_widget);
    parse->setObjectName(QStringLiteral("parse"));
    operation_layout->addWidget(parse, 1, 1, 1, 1);

    transmit = new QPushButton(operation_layout_widget);
    transmit->setObjectName(QStringLiteral("transmit"));
    operation_layout->addWidget(transmit, 1, 0, 1, 1);

    allAuto = new QPushButton(operation_layout_widget);
    allAuto->setObjectName(QStringLiteral("allAuto"));
    operation_layout->addWidget(allAuto, 2, 0, 1, 2);

    checkBox = new QCheckBox(ParseDataForm);
    checkBox->setObjectName(QStringLiteral("checkBox"));
    checkBox->setGeometry(QRect(270, 20, 92, 23));
    progress_bar = new QProgressBar(ParseDataForm);
    progress_bar->setObjectName(QStringLiteral("progress_bar"));
    progress_bar->setGeometry(QRect(30, 580, 291, 23));
    progress_bar->setValue(24);

    retranslateUi(ParseDataForm);

    QMetaObject::connectSlotsByName(ParseDataForm);
  } // setupUi

  void retranslateUi(QWidget *ParseDataForm)
  {
    ParseDataForm->setWindowTitle(QApplication::translate("ParseDataForm", "Form", Q_NULLPTR));
    select_truck->setText(QApplication::translate("ParseDataForm", "select truck", Q_NULLPTR));
    record_time1->setText(QApplication::translate("ParseDataForm", "record time", Q_NULLPTR));
    truck_param_group->setTitle(QApplication::translate("ParseDataForm", "truck param", Q_NULLPTR));
    lf1->setText(QApplication::translate("ParseDataForm", "front lidar", Q_NULLPTR));
    ip1->setText(QApplication::translate("ParseDataForm", "IP", Q_NULLPTR));

    save_param->setToolTip(QApplication::translate("ParseDataForm", "<html><head/><body><p>保存的参数仅在该窗口有效，不会更改配置文件</p></body></html>", Q_NULLPTR));
    save_param->setText(QApplication::translate("ParseDataForm", "save param", Q_NULLPTR));

    bf1->setText(QApplication::translate("ParseDataForm", "back lidar", Q_NULLPTR));
    save_path1->setText(QApplication::translate("ParseDataForm", "save path", Q_NULLPTR));
    operation_group->setTitle(QApplication::translate("ParseDataForm", "operation", Q_NULLPTR));

    start->setToolTip(QApplication::translate("ParseDataForm", "<html><head/><body><p>click to start record</p></body></html>", Q_NULLPTR));
    start->setText(QApplication::translate("ParseDataForm", "start record", Q_NULLPTR));

    end->setToolTip(QApplication::translate("ParseDataForm", "<html><head/><body><p>click to stop recording</p></body></html>", Q_NULLPTR));
    end->setText(QApplication::translate("ParseDataForm", "stop record", Q_NULLPTR));

    parse->setToolTip(QApplication::translate("ParseDataForm", "<html><head/><body><p>parse data to format for debug</p></body></html>", Q_NULLPTR));
    parse->setText(QApplication::translate("ParseDataForm", "parse data", Q_NULLPTR));

    transmit->setToolTip(QApplication::translate("ParseDataForm", "<html><head/><body><p>把数据传递至本地</p></body></html>", Q_NULLPTR));
    transmit->setText(QApplication::translate("ParseDataForm", "pull data", Q_NULLPTR));

    allAuto->setToolTip(QApplication::translate("ParseDataForm", "<html><head/><body><p>按照设定的规则自动完成录制拉取解析; 用时间命名文件夹</p></body></html>", Q_NULLPTR));
    allAuto->setText(QApplication::translate("ParseDataForm", "一键完成", Q_NULLPTR));

    checkBox->setText(QApplication::translate("ParseDataForm", "网络连接", Q_NULLPTR));
  } // retranslateUi
};

namespace Ui
{
  class ParseDataForm : public Ui_ParseDataForm
  {
  };
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARSE_DATA_FORM_H
