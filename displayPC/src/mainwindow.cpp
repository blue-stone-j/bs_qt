#include "mainwindow.h"

// warn no files;save merged cloud; cache clouds; stop when select a cloud; delete cloud;
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)

{
  ui->setupUi(this);
  //  this->setGeometry(0,0,1650,800);
  this->setWindowIcon(QIcon("../assets/logo.ico"));
  //  this->setWindowTitle("点云分析");

  settings = new QSettings("./config/config.ini", QSettings::IniFormat); // 构建函数
  if (settings->value("/perception/algorithm").toString() == QString("patchwork"))
  {
    OutPut("perception: patchwork");
    perception = new PatchWorkBase();
  }
  else if (settings->value("/perception/algorithm").toString() == QString("covariance"))
  {
    OutPut("perception: Covariance");
    perception = new CovarianceBase();
  }
  else
  {
    OutPut(settings->value("/perception/algorithm").toString() + QString(" doesn't exist! Now perception: patch work"));
    perception = new PatchWorkBase();
  }

  //--- display image and pcd cloud ---//
  pcl_viewer.setParent(ui->display_group);

  //--- file list ---//

  //--- display state ---//
  ui->show_ori_cloud2->setToggle(true);
  voxel_size2 = new EditableLabel();
  ui->state_layout->addWidget(voxel_size2, 2, 8);
  //  ui->cloud_time2->setText(QDateTime::fromMSecsSinceEpoch(long long int msecs));
  ui->cloud_time2->setText(QDateTime::currentDateTime().toString("MM-dd hh:mm:ss.zzz"));

  int numtem = pcl_viewer.cloudSize();
  ui->cloud_size2->setText(QString::number(numtem / 10000, 10) + QString(",") + QString::number(numtem % 10000, 10));

  sum_files = QString(" / ") + QString::number(0, 10);
  ui->index_file2->setText(QString::number(0, 10) + sum_files);

  // -- play setting ---//
  play_ico = QIcon("../assets/play.png");
  pause_ico = QIcon("../assets/pause.png");

  connect(ui->play_frame, &QPushButton::clicked, this, &MainWindow::playPause);
  connect(ui->last_frame, &QPushButton::clicked, this, &MainWindow::lastFrame);
  connect(ui->next_frame, &QPushButton::clicked, this, &MainWindow::nextFrame);

  connect(&play_timer, SIGNAL(timeout()), this, SLOT(playClouds()));
  connect(ui->add_interval, &QPushButton::clicked, this, &MainWindow::addInterval);
  connect(ui->minus_interval, &QPushButton::clicked, this, &MainWindow::minusInterval);

  connect(ui->select_path, SIGNAL(triggered()), this, SLOT(openDirectory()));
  connect(ui->about, SIGNAL(triggered()), this, SLOT(openAbout()));

  parse_data_form = new ParseDataForm();

  // parse_data_form->setWindowTitle("远程操作");
}

MainWindow::~MainWindow()
{
  delete ui;
}
void MainWindow::playClouds()
{
  if (cur_index < path_vector.size() - 1)
  {
    cur_index++;
    ui->file_list->clearSelection();
    ui->file_list->item(cur_index)->setSelected(true);
    updateAll();
  }
  else
  {
    ui->play_frame->setIcon(pause_ico);
    isPlay = false;
    play_timer.stop();
  }
}

void MainWindow::playPause()
{
  if (isPlay)
  {
    isPlay = false;
    play_timer.stop();
    ui->play_frame->setIcon(pause_ico);
    return;
  }
  else
  {
    if (cur_index < path_vector.size() - 1)
    {
      ui->play_frame->setIcon(play_ico);
      isPlay = true;

      play_timer.start(ui->interval->text().toFloat() * 1000);
    }
    return;
  }
}

void MainWindow::lastFrame()
{
  isPlay = false;
  play_timer.stop();
  ui->play_frame->setIcon(pause_ico);
  if (cur_index > 0)
  {
    cur_index--;
    ui->file_list->clearSelection();
    ui->file_list->item(cur_index)->setSelected(true);
    updateAll();
  }
}

void MainWindow::nextFrame()
{
  isPlay = false;
  play_timer.stop();
  ui->play_frame->setIcon(pause_ico);
  if (cur_index < path_vector.size() - 1)
  {
    cur_index++;
    ui->file_list->clearSelection();
    ui->file_list->item(cur_index)->setSelected(true);
    updateAll();
  }
}

void MainWindow::addInterval()
{
  int interval = round(ui->interval->text().toFloat() * 10);
  if (interval < 10)
  {
    ui->interval->setText(QString::number(float(interval + 1) / 10));
  }
}

void MainWindow::minusInterval()
{
  int interval = round(ui->interval->text().toFloat() * 10);
  if (interval > 1)
  {
    ui->interval->setText(QString::number(float(interval - 1) / 10));
  }
}

bool MainWindow::openDirectory()
{
  path_vector.clear();
  ui->file_list->clear();
  cur_index = 0;

  QString dirpath = QFileDialog::getExistingDirectory(this, "select folder", QString(std::getenv("HOME")) + "/temp/", QFileDialog::ShowDirsOnly);
  QDir dir(dirpath);
  dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
  dir.setSorting(QDir::Name);

  QFileInfoList list = dir.entryInfoList();

  for (int i = 0; i < list.size(); ++i)
  {
    QFileInfo fileInfo = list.at(i);
    if (fileInfo.fileName().endsWith(".pcd"))
    {
      path_vector.push_back(QPair<QString, QString>(fileInfo.filePath(), fileInfo.fileName().left(fileInfo.fileName().size() - 4)));
    }
  }
  if (path_vector.empty())
  {
    return false;
  }
  for (int i = 0; i < path_vector.size(); ++i)
  {
    ui->file_list->addItem(path_vector[i].second);
  }
  updateAll();
  pcl_viewer.resetViewport();

  sum_files = QString(" / ") + QString::number(path_vector.size(), 10);
  update(); // necessary for slot
  return true;
}

void MainWindow::on_file_list_clicked(const QModelIndex &index)
{
  cur_index = index.row();
  updateAll();
}

void MainWindow::updateAll()
{

  pcl::PointCloud<pcl::PointXYZI>::Ptr thisCloud;
  thisCloud.reset(new pcl::PointCloud<pcl::PointXYZI>);

  if (-1 == pcl::io::loadPCDFile(path_vector[cur_index].first.toStdString(), *thisCloud))
  {
    QMessageBox MyBox(QMessageBox::Warning, "warning", "Cloud file doesn't exist", QMessageBox::No | QMessageBox::Yes);
    MyBox.exec();
  }

  //  std::cout << settings->value("/perception/perception").toBool() << ", " << ui->process_cloud2->isToggled() << std::endl;

  updateDisplay(thisCloud);

  ui->cloud_time2->setText(QDateTime::fromMSecsSinceEpoch(path_vector[cur_index].second.toLong()).toString("MM-dd hh:mm:ss.zzz"));
  ui->index_file2->setText(QString::number(cur_index + 1, 10) + sum_files);
  int numtem = pcl_viewer.cloudSize();
  ui->cloud_size2->setText(QString::number(numtem / 10000, 10) + QString(",") + QString::number(numtem % 10000, 10));
}

void MainWindow::updateDisplay(pcl::PointCloud<pcl::PointXYZI>::Ptr ori_cloud)
{
  if (settings->value("/perception/perception").toBool()) // load when startup
  {
    double time = path_vector[cur_index].second.toDouble() / 1000;
    perception->runPerception(*ori_cloud, time);
  }

  pcl_viewer.inputOriCloud(ui->show_ori_cloud2->isToggled() ? perception->parseOriCloud() : pcl::PointCloud<pcl::PointXYZI>());

  pcl_viewer.inputObjCloud(ui->show_obj_cloud2->isToggled() ? (perception->parseObjectCloud()) : pcl::PointCloud<pcl::PointXYZI>());

  pcl_viewer.inputObj(ui->show_obj2->isToggled() ? (perception->parseObs()) : std::vector<ObjectBox>());
  // std::cout << "box num: " << perception->parseObs().size() << std::endl;
  ui->obj_num2->setText(QString::number(perception->parseObs().size(), 10));

  pcl_viewer.displayCloud();
}

void MainWindow::on_merge_cloud_clicked()
{
  QItemSelectionModel *selections = ui->file_list->selectionModel(); // 返回当前的选择模式
  QModelIndexList selected_list = selections->selectedIndexes();     // 返回所有选定的模型项目索引列表

  if (!selected_list.count())
  {
    return;
  }
  pcl::PointCloud<pcl::PointXYZI>::Ptr cloudstem;
  for (int i = 0; i < selected_list.count(); i++)
  {
    pcl::PointCloud<pcl::PointXYZI> cloudtem;
    pcl::io::loadPCDFile(path_vector[selected_list.at(i).row()].first.toStdString(), cloudtem);
    *cloudstem += cloudtem;
  }

  updateDisplay(cloudstem);

  int numtem = pcl_viewer.cloudSize();
  ui->cloud_size2->setText(QString::number(numtem / 10000, 10) + QString(",") + QString::number(numtem % 10000, 10));
}

void MainWindow::on_filter_cloud_clicked()
{
  pcl_viewer.filterCloud(voxel_size2->label->text().toFloat());
  int numtem = pcl_viewer.cloudSize();
  ui->cloud_size2->setText(QString::number(numtem / 10000, 10) + QString(",") + QString::number(numtem % 10000, 10));
}

void MainWindow::closeEvent(QCloseEvent *event)
{
  for (int i = 0, size = threads.size(); i < size; i++)
  {
    qDebug() << "close thread" << pthread_cancel(threads[i]);
  }
}

void MainWindow::on_viewport_clicked()
{
  pcl_viewer.resetViewport();
}

void MainWindow::on_record_but_clicked()
{

  QProcess process;
  QStringList args;
  args << "/home/jpw/rec.sh";

  if (!QFileInfo(args.at(0)).isFile())
  {
    QString temStr = QString("Record script doesn't exist!");
    OutPut(temStr);

    return;
  }

  qDebug() << "start";
  process.start("sh", args);
  sleep(5);
  process.close();
  qDebug() << "close";
  //  system("gnome-terminal -- bash -c 'echo 123456 | -S ssh nnnn@10.10.1.14 ;roscore;'&"); cd ~;rosbag record -a; cd ~;ssh nnnn@10.10.1.14
  //  system("gnome-terminal -- bash -c 'ssh nnnn@10.10.1.14;'");
}

void MainWindow::OutPut(QString out)
{
  QString temStr = QString::number(outsize++) + QString(": ") + out;
  out_str.push_back(temStr);
  ui->output->append(temStr);
  if (out_str.size() > 200) // max outputs
  {
    ui->output->clear();
    out_str.erase(out_str.begin(), out_str.end() - 100); // reserve some new outputs
    for (int i = 0; i < out_str.size(); i++)
    {
      ui->output->append(out_str[i]);
    }
  }
}

void MainWindow::on_parse_data_clicked()
{

  //  ParseDataForm *parse_data_form = new ParseDataForm();
  //  parse_data_form->setWindowTitle("远程操作");
  parse_data_form->show();
}

bool MainWindow::openAbout()
{
  QMessageBox::about(this, "about software", "Tool to debug perception module. Code of perception module and data transmition is integrated, record remotely and parse locally included.");
  return true;
}

/* todo: net connection indicator; reset camera and view
 */
