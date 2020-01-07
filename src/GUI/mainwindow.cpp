#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new SfscaScene(0,0,ui->graphicsView->width()-2,ui->graphicsView->height()-2,ui->graphicsView);
    ui->label_err->setVisible(false);
    connect(scene, SIGNAL(completed()), this, SLOT(addScoreEntry()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}

void MainWindow::addScoreEntry()
{
    ulogin.addEntry(scene->computeScore());
}

void MainWindow::drawScore()
{
    list<Grade> &scores = ulogin.getHistory();
    string msg;
    for(Grade g : scores)
    {
        msg += g.getDate("%F %T") + ": " + to_string(g.getGrade()) + "\n";

    }
    msg += "\nAverage: ";
    msg += to_string(ulogin.getAverage());
    ui->score_edit->setText(QString(msg.c_str()));
}

void MainWindow::on_button_login_pressed()
{
    int code = ulogin.login(ui->line_user->text().toStdString(), ui->line_pass->text().toStdString());
    if(code == SUCCESS)
        ui->stackedWidget->setCurrentIndex(1);
    else
    {
        if(!ui->label_err->isVisible()){ui->label_err->setVisible(true);}
        QString msg(ulogin.getErrorMessage().c_str());
        ui->label_err->setText(msg);
    }
}

void MainWindow::on_button_register_pressed()
{
    int code = ulogin.create(ui->line_user->text().toStdString(), ui->line_pass->text().toStdString());
    if(code == SUCCESS)
    {
        ulogin.login(ui->line_user->text().toStdString(), ui->line_pass->text().toStdString());
        ui->stackedWidget->setCurrentIndex(1);
    }
    else
    {
        if(!ui->label_err->isVisible()){ui->label_err->setVisible(true);}
        QString msg(ulogin.getErrorMessage().c_str());
        ui->label_err->setText(msg);
    }
}

void MainWindow::on_button_VT12_clicked()
{
    scene->setV(VT12);
    scene->myupdate();
}

void MainWindow::on_button_VT23_clicked()
{
    scene->setV(VT23);
    scene->myupdate();
}

void MainWindow::on_button_P12_clicked()
{
    scene->setPump2(T1);
    scene->myupdate();
}

void MainWindow::on_button_P22_clicked()
{
    scene->setPump2(T2);
    scene->myupdate();
}

void MainWindow::on_button_P32_clicked()
{
    scene->setPump2(T3);
    scene->myupdate();
}

void MainWindow::on_button_V12_clicked()
{
    scene->setV(V12);
    scene->myupdate();
}

void MainWindow::on_button_V13_clicked()
{
    scene->setV(V13);
    scene->myupdate();
}

void MainWindow::on_button_V23_clicked()
{
    scene->setV(V23);
    scene->myupdate();
}

void MainWindow::on_button_start_clicked()
{
    ui->graphicsView->setScene(scene);
    scene->setDone(false);
    scene->hideMsg();
    scene->runRandomConfig();
    scene->chronostart();
    scene->myupdate();
}

void MainWindow::on_button_score_clicked()
{
    drawScore();
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_button_retour_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
