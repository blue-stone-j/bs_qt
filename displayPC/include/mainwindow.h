#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// qt
#include <QDateTime>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QProcess>
#include <QSettings>
#include <QString>
#include <QVector>
#include <QWidget>

// C++
#include <thread>
#include <vector>

// pcl
#include <pcl/io/pcd_io.h>

#include "mainwindow_ui.h"
#include "component/parse_data_form/parse_data_form.h"

#include <QMainWindow>

#include "widgets/editable_label/editable_label.h"

#include "component/viewer/pclview/pclview.h"
#include "process/perception/patch_work/patch_work_base.h"
#include "process/perception/covariance/covariance_base.h"

namespace Ui
{
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

  //--- thread ---//
  std::vector<pthread_t> threads;
  void OutPut(QString out);

private:
  Ui::MainWindow *ui;

  ParseDataForm *parse_data_form;

  QSettings *settings; // 申明一个QSetting类函数

  int outsize = 1;

  //--- image and pcd cloud ---//
  PCLView pcl_viewer;

  PerceptionInterface *perception;

  //--- state ---//
  QString sum_files; // update after selecting directory
  EditableLabel *voxel_size2;

  // -- play ---//
  QIcon play_ico, pause_ico;
  bool isPlay = false;
  QTimer play_timer;
  void playPause();     //
  void lastFrame();     //
  void nextFrame();     //
  void addInterval();   // add interval between two cloud when we play cloud list
  void minusInterval(); //
private slots:
  void playClouds();

  //--- file ---//
private:
  QVector<QPair<QString, QString>> path_vector;
  QVector<QString> out_str;
  int cur_index = 0;
  void updateAll(); // update viewer, info text
  void updateDisplay(pcl::PointCloud<pcl::PointXYZI>::Ptr ori_cloud);
private slots:
  bool openDirectory();
  bool openAbout();
private slots:
  void on_file_list_clicked(const QModelIndex &index); // choose a cloud to process and display
  void on_merge_cloud_clicked();                       // use only when cloud is in global cooridate system
  void on_filter_cloud_clicked();                      //

  void on_viewport_clicked();

  void on_record_but_clicked();

  void on_parse_data_clicked();

protected:
  void closeEvent(QCloseEvent *event) override;
};

#endif // MAINWINDOW_H

/*
playStyle = "border: 1px solid;";
*/
