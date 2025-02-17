
#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "widgets/switcher_dual/switcher_dual.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
  QMenuBar *menubar;
  QToolBar *main_toolbar;
  QStatusBar *status_bar;
  QAction *select_path;
  QAction *save_pcd;
  QAction *pull_remote_data_act;
  QAction *about;
  QMenu *menu_file;
  QMenu *help;

  QWidget *central_widget;

  QGroupBox *display_group;

  QGroupBox *schedule_group;

  QGroupBox *state_group;
  QWidget *state_layout_widget;
  QGridLayout *state_layout;

  QLabel *cloud_time1;
  QLabel *cloud_time2;
  QLabel *cloud_size1;
  QLabel *cloud_size2;
  QLabel *index_file1;
  QLabel *index_file2;
  QLabel *obj_num1;
  QLabel *obj_num2;

  QGroupBox *show_control_group;

  QWidget *show_layout_widget;
  QGridLayout *show_layout;
  QLabel *show_obj1;
  SwitcherDual *process_cloud2;
  QLabel *process_cloud1;
  SwitcherDual *show_obj2;
  QLabel *show_obj_cloud1;
  SwitcherDual *show_obj_cloud2;
  QLabel *show_ori_cloud1;
  SwitcherDual *show_ori_cloud2;
  QPushButton *viewport;

  QGroupBox *play_group;
  QPushButton *last_frame;
  QPushButton *play_frame;
  QPushButton *next_frame;
  QPushButton *minus_interval;
  QPushButton *add_interval;
  QLineEdit *interval;

  QGroupBox *process_group;
  QWidget *process_layout_widget;
  QGridLayout *process_layout;
  QPushButton *filter_cloud;
  QPushButton *merge_cloud;
  QPushButton *record_but;
  QPushButton *parse_data;
  QLabel *voxel_size1;

  QGroupBox *file_group;
  QListWidget *file_list;

  QGroupBox *log_group;
  QTextEdit *output;

  void setupUi(QMainWindow *MainWindow)
  {
    if (MainWindow->objectName().isEmpty())
    {
      MainWindow->setObjectName(QStringLiteral("MainWindow"));
    }

    MainWindow->setWindowModality(Qt::WindowModal);
    MainWindow->resize(1650, 878);
    // MainWindow->setSizePolicy(sizePolicy);
    central_widget = new QWidget(MainWindow);
    central_widget->setObjectName(QStringLiteral("central_widget"));
    MainWindow->setCentralWidget(central_widget);

    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QStringLiteral("menubar"));
    menubar->setGeometry(QRect(0, 0, 1650, 28));

    menu_file = new QMenu(menubar);
    menu_file->setObjectName(QStringLiteral("menu_file"));
    menubar->addAction(menu_file->menuAction());

    select_path = new QAction(MainWindow);
    select_path->setObjectName(QStringLiteral("select_path"));
    menu_file->addAction(select_path);
    save_pcd = new QAction(MainWindow);
    save_pcd->setObjectName(QStringLiteral("save_pcd"));
    menu_file->addAction(save_pcd);
    pull_remote_data_act = new QAction(MainWindow);
    pull_remote_data_act->setObjectName(QStringLiteral("pull_remote_data_act"));
    menu_file->addSeparator();
    menu_file->addAction(pull_remote_data_act);

    help = new QMenu(menubar);
    help->setObjectName(QStringLiteral("help"));
    menubar->addAction(help->menuAction());

    about = new QAction(MainWindow);
    about->setObjectName(QStringLiteral("about"));
    help->addAction(about);

    MainWindow->setMenuBar(menubar);

    main_toolbar = new QToolBar(MainWindow);
    main_toolbar->setObjectName(QStringLiteral("main_toolbar"));
    MainWindow->addToolBar(Qt::TopToolBarArea, main_toolbar);

    status_bar = new QStatusBar(MainWindow);
    status_bar->setObjectName(QStringLiteral("status_bar"));
    MainWindow->setStatusBar(status_bar);

    // schedule group
    schedule_group = new QGroupBox(central_widget);
    schedule_group->setObjectName(QStringLiteral("schedule_group"));
    schedule_group->setGeometry(QRect(10, 0, 431, 801));
    state_group = new QGroupBox(schedule_group);
    state_group->setObjectName(QStringLiteral("state_group"));
    state_group->setGeometry(QRect(10, 30, 409, 91));
    state_layout_widget = new QWidget(state_group);
    state_layout_widget->setObjectName(QStringLiteral("state_layout_widget"));
    state_layout_widget->setGeometry(QRect(0, 30, 411, 56));
    state_layout = new QGridLayout(state_layout_widget);
    state_layout->setSpacing(6);
    state_layout->setContentsMargins(11, 11, 11, 11);
    state_layout->setObjectName(QStringLiteral("state_layout"));
    state_layout->setSizeConstraint(QLayout::SetDefaultConstraint);
    state_layout->setContentsMargins(5, 3, 5, 0);

    cloud_size2 = new QLabel(state_layout_widget);
    cloud_size2->setObjectName(QStringLiteral("cloud_size2"));
    cloud_size2->setStyleSheet(QLatin1String("border: 1px solid;\n"
                                             "border-color: rgb(52, 101, 164);"));
    cloud_size2->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);

    state_layout->addWidget(cloud_size2, 0, 3, 1, 1);

    cloud_time1 = new QLabel(state_layout_widget);
    cloud_time1->setObjectName(QStringLiteral("cloud_time1"));

    state_layout->addWidget(cloud_time1, 0, 0, 1, 1);

    cloud_time2 = new QLabel(state_layout_widget);
    cloud_time2->setObjectName(QStringLiteral("cloud_time2"));
    cloud_time2->setStyleSheet(QLatin1String("border: 1px solid;\n"
                                             "border-color: rgb(52, 101, 164);"));

    state_layout->addWidget(cloud_time2, 0, 1, 1, 1);

    cloud_size1 = new QLabel(state_layout_widget);
    cloud_size1->setObjectName(QStringLiteral("cloud_size1"));
    state_layout->addWidget(cloud_size1, 0, 2, 1, 1);

    index_file1 = new QLabel(state_layout_widget);
    index_file1->setObjectName(QStringLiteral("index_file1"));
    state_layout->addWidget(index_file1, 1, 0, 1, 1);

    index_file2 = new QLabel(state_layout_widget);
    index_file2->setObjectName(QStringLiteral("index_file2"));
    index_file2->setStyleSheet(QLatin1String("border: 1px solid;\n"
                                             "border-color: rgb(52, 101, 164);"));
    index_file2->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);

    state_layout->addWidget(index_file2, 1, 1, 1, 1);

    obj_num1 = new QLabel(state_layout_widget);
    obj_num1->setObjectName(QStringLiteral("obj_num1"));
    state_layout->addWidget(obj_num1, 1, 2, 1, 1);
    obj_num2 = new QLabel(state_layout_widget);
    obj_num2->setObjectName(QStringLiteral("obj_num2"));
    obj_num2->setStyleSheet(QLatin1String("border: 1px solid;\n"
                                          "border-color: rgb(52, 101, 164);"));
    obj_num2->setAlignment(Qt::AlignRight | Qt::AlignTrailing | Qt::AlignVCenter);
    state_layout->addWidget(obj_num2, 1, 3, 1, 1);

    // show control
    show_control_group = new QGroupBox(schedule_group);
    show_control_group->setObjectName(QStringLiteral("show_control_group"));
    show_control_group->setGeometry(QRect(10, 150, 411, 101));
    show_layout_widget = new QWidget(show_control_group);
    show_layout_widget->setObjectName(QStringLiteral("show_layout_widget"));
    show_layout_widget->setGeometry(QRect(10, 30, 391, 51));
    show_layout = new QGridLayout(show_layout_widget);
    show_layout->setSpacing(6);
    show_layout->setContentsMargins(11, 11, 11, 11);
    show_layout->setObjectName(QStringLiteral("show_layout"));
    show_layout->setContentsMargins(0, 0, 0, 0);

    process_cloud1 = new QLabel(show_layout_widget);
    process_cloud1->setObjectName(QStringLiteral("process_cloud1"));
    show_layout->addWidget(process_cloud1, 0, 0, 1, 1);
    process_cloud2 = new SwitcherDual(show_layout_widget);
    process_cloud2->setObjectName(QStringLiteral("process_cloud2"));
    show_layout->addWidget(process_cloud2, 0, 1, 1, 1);

    show_obj1 = new QLabel(show_layout_widget);
    show_obj1->setObjectName(QStringLiteral("show_obj1"));
    show_layout->addWidget(show_obj1, 0, 2, 1, 1);
    show_obj2 = new SwitcherDual(show_layout_widget);
    show_obj2->setObjectName(QStringLiteral("show_obj2"));
    show_layout->addWidget(show_obj2, 0, 3, 1, 1);

    show_obj_cloud1 = new QLabel(show_layout_widget);
    show_obj_cloud1->setObjectName(QStringLiteral("show_obj_cloud1"));
    show_layout->addWidget(show_obj_cloud1, 0, 4, 1, 1);
    show_obj_cloud2 = new SwitcherDual(show_layout_widget);
    show_obj_cloud2->setObjectName(QStringLiteral("show_obj_cloud2"));
    show_layout->addWidget(show_obj_cloud2, 0, 5, 1, 1);

    show_ori_cloud1 = new QLabel(show_layout_widget);
    show_ori_cloud1->setObjectName(QStringLiteral("show_ori_cloud1"));
    show_layout->addWidget(show_ori_cloud1, 1, 0, 1, 1);
    show_ori_cloud2 = new SwitcherDual(show_layout_widget);
    show_ori_cloud2->setObjectName(QStringLiteral("show_ori_cloud2"));
    show_layout->addWidget(show_ori_cloud2, 1, 1, 1, 1);

    viewport = new QPushButton(show_layout_widget);
    viewport->setObjectName(QStringLiteral("viewport"));
    show_layout->addWidget(viewport, 1, 2, 1, 1);

    // play group
    play_group = new QGroupBox(schedule_group);
    play_group->setObjectName(QStringLiteral("play_group"));
    play_group->setGeometry(QRect(10, 270, 411, 91));
    last_frame = new QPushButton(play_group);
    last_frame->setObjectName(QStringLiteral("last_frame"));
    last_frame->setGeometry(QRect(30, 30, 50, 50));
    last_frame->setStyleSheet(QStringLiteral("border: 1px solid;"));
    QIcon icon;
    icon.addFile(QStringLiteral("../assets/last.png"), QSize(), QIcon::Normal, QIcon::Off);
    last_frame->setIcon(icon);
    last_frame->setIconSize(QSize(40, 40));
    play_frame = new QPushButton(play_group);
    play_frame->setObjectName(QStringLiteral("play_frame"));
    play_frame->setGeometry(QRect(90, 30, 50, 50));
    play_frame->setStyleSheet(QStringLiteral("border: 1px solid;"));
    QIcon icon1;
    icon1.addFile(QStringLiteral("../assets/pause.png"), QSize(), QIcon::Normal, QIcon::Off);
    play_frame->setIcon(icon1);
    play_frame->setIconSize(QSize(40, 40));
    next_frame = new QPushButton(play_group);
    next_frame->setObjectName(QStringLiteral("next_frame"));
    next_frame->setGeometry(QRect(150, 30, 50, 50));
    next_frame->setStyleSheet(QStringLiteral("border: 1px solid;"));
    QIcon icon2;
    icon2.addFile(QStringLiteral("../assets/next.png"), QSize(), QIcon::Normal, QIcon::Off);
    next_frame->setIcon(icon2);
    next_frame->setIconSize(QSize(40, 40));
    minus_interval = new QPushButton(play_group);
    minus_interval->setObjectName(QStringLiteral("minus_interval"));
    minus_interval->setGeometry(QRect(220, 40, 32, 32));
    minus_interval->setStyleSheet(QStringLiteral("min-width: 30px; min-height: 30px; max-width: 30px; max-height: 30px; border-radius: 15px;border: 1px solid;"));
    QIcon icon3;
    icon3.addFile(QStringLiteral("../assets/minus.png"), QSize(), QIcon::Normal, QIcon::Off);
    minus_interval->setIcon(icon3);
    minus_interval->setIconSize(QSize(32, 32));
    add_interval = new QPushButton(play_group);
    add_interval->setObjectName(QStringLiteral("add_interval"));
    add_interval->setGeometry(QRect(350, 40, 32, 32));
    add_interval->setStyleSheet(QStringLiteral("min-width: 30px; min-height: 30px; max-width: 30px; max-height: 30px; border-radius: 15px;border: 1px solid;"));
    QIcon icon4;
    icon4.addFile(QStringLiteral("../assets/add.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
    add_interval->setIcon(icon4);
    add_interval->setIconSize(QSize(18, 18));
    interval = new QLineEdit(play_group);
    interval->setObjectName(QStringLiteral("interval"));
    interval->setGeometry(QRect(260, 30, 81, 51));
    interval->setStyleSheet(QStringLiteral("border: 1px solid;"));
    interval->setAlignment(Qt::AlignCenter);

    process_group = new QGroupBox(schedule_group);
    process_group->setObjectName(QStringLiteral("process_group"));
    process_group->setGeometry(QRect(10, 390, 411, 111));
    process_layout_widget = new QWidget(process_group);
    process_layout_widget->setObjectName(QStringLiteral("process_layout_widget"));
    process_layout_widget->setGeometry(QRect(10, 30, 391, 70));
    process_layout = new QGridLayout(process_layout_widget);
    process_layout->setSpacing(6);
    process_layout->setContentsMargins(11, 11, 11, 11);
    process_layout->setObjectName(QStringLiteral("process_layout"));
    process_layout->setContentsMargins(0, 0, 0, 0);

    merge_cloud = new QPushButton(process_layout_widget);
    merge_cloud->setObjectName(QStringLiteral("merge_cloud"));
    process_layout->addWidget(merge_cloud, 0, 0, 1, 1);

    filter_cloud = new QPushButton(process_layout_widget);
    filter_cloud->setObjectName(QStringLiteral("filter_cloud"));
    process_layout->addWidget(filter_cloud, 0, 1, 1, 1);

    voxel_size1 = new QLabel(process_layout_widget);
    voxel_size1->setObjectName(QStringLiteral("voxel_size1"));
    process_layout->addWidget(voxel_size1, 0, 2, 1, 1);

    record_but = new QPushButton(process_layout_widget);
    record_but->setObjectName(QStringLiteral("record_but"));
    process_layout->addWidget(record_but, 1, 0, 1, 1);

    parse_data = new QPushButton(process_layout_widget);
    parse_data->setObjectName(QStringLiteral("parse_data"));
    process_layout->addWidget(parse_data, 1, 1, 1, 1);

    display_group = new QGroupBox(central_widget);
    display_group->setObjectName(QStringLiteral("display_group"));
    display_group->setGeometry(QRect(450, 0, 1000, 800));
    display_group->setStyleSheet(QStringLiteral("background-color:transparent;"));

    file_group = new QGroupBox(central_widget);
    file_group->setObjectName(QStringLiteral("file_group"));
    file_group->setGeometry(QRect(1460, 0, 170, 801));
    file_list = new QListWidget(file_group);
    file_list->setObjectName(QStringLiteral("file_list"));
    file_list->setGeometry(QRect(0, 20, 171, 781));
    file_list->setAutoFillBackground(false);
    file_list->setSelectionMode(QAbstractItemView::ExtendedSelection);

    log_group = new QGroupBox(schedule_group);
    log_group->setObjectName(QStringLiteral("log_group"));
    log_group->setGeometry(QRect(10, 510, 411, 281));
    output = new QTextEdit(log_group);
    output->setObjectName(QStringLiteral("output"));
    output->setGeometry(QRect(0, 20, 411, 261));

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
  } // setupUi

  void retranslateUi(QMainWindow *MainWindow)
  {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Mimic World", Q_NULLPTR));
    select_path->setText(QApplication::translate("MainWindow", "select folder", Q_NULLPTR));
    save_pcd->setText(QApplication::translate("MainWindow", "save cloud", Q_NULLPTR));
    pull_remote_data_act->setText(QApplication::translate("MainWindow", "pull remote data", Q_NULLPTR));
    about->setText(QApplication::translate("MainWindow", "about software", Q_NULLPTR));
    menu_file->setTitle(QApplication::translate("MainWindow", "file", Q_NULLPTR));
    help->setTitle(QApplication::translate("MainWindow", "help", Q_NULLPTR));

    schedule_group->setTitle(QApplication::translate("MainWindow", "schedule", Q_NULLPTR));

    state_group->setTitle(QApplication::translate("MainWindow", "basic info", Q_NULLPTR));
    cloud_time1->setText(QApplication::translate("MainWindow", "time: ", Q_NULLPTR));
    cloud_time2->setText(QString());
    cloud_size1->setText(QApplication::translate("MainWindow", "size: ", Q_NULLPTR));
    cloud_size2->setText(QApplication::translate("MainWindow", "0,0", Q_NULLPTR));
    index_file1->setText(QApplication::translate("MainWindow", "index: ", Q_NULLPTR));
    index_file2->setText(QApplication::translate("MainWindow", "0 / 0", Q_NULLPTR));
    obj_num1->setText(QApplication::translate("MainWindow", "object: ", Q_NULLPTR));
    obj_num2->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));

    display_group->setTitle(QApplication::translate("MainWindow", "dispaly", Q_NULLPTR));

    file_group->setTitle(QApplication::translate("MainWindow", "files", Q_NULLPTR));

    show_control_group->setTitle(QApplication::translate("MainWindow", "show control", Q_NULLPTR));
    show_obj1->setText(QApplication::translate("MainWindow", "show object:", Q_NULLPTR));

    show_obj2->setToolTip(QApplication::translate("MainWindow", "whether show bounding box of objects", Q_NULLPTR));
    show_obj_cloud1->setText(QApplication::translate("MainWindow", "objects cloud:", Q_NULLPTR));
    show_obj_cloud2->setToolTip(QApplication::translate("MainWindow", "whether show objects cloud", Q_NULLPTR));
    show_ori_cloud1->setText(QApplication::translate("MainWindow", "original cloud:", Q_NULLPTR));
    show_ori_cloud2->setToolTip(QApplication::translate("MainWindow", "whether show original cloud", Q_NULLPTR));

    process_cloud1->setText(QApplication::translate("MainWindow", "process cloud: ", Q_NULLPTR));
    viewport->setText(QApplication::translate("MainWindow", "reset viewport", Q_NULLPTR));

    play_group->setTitle(QApplication::translate("MainWindow", "play control", Q_NULLPTR));
    last_frame->setText(QString());
    play_frame->setText(QString());
    next_frame->setText(QString());
    minus_interval->setText(QString());
    add_interval->setText(QString());
    interval->setText(QApplication::translate("MainWindow", "0.5", Q_NULLPTR));

    process_group->setTitle(QApplication::translate("MainWindow", "process group", Q_NULLPTR));
    filter_cloud->setText(QApplication::translate("MainWindow", "filter cloud", Q_NULLPTR));
    merge_cloud->setText(QApplication::translate("MainWindow", "merge cloud", Q_NULLPTR));
    record_but->setText(QApplication::translate("MainWindow", "record #1", Q_NULLPTR));
    parse_data->setText(QApplication::translate("MainWindow", "connect remotely", Q_NULLPTR));
    voxel_size1->setText(QApplication::translate("MainWindow", "voxel size: ", Q_NULLPTR));
    log_group->setTitle(QApplication::translate("MainWindow", "log", Q_NULLPTR));
  } // retranslateUi
};

namespace Ui
{
  class MainWindow : public Ui_MainWindow
  {
  };
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
