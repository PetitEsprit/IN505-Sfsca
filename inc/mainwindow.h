#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sfscascene.h"
#include "Login.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void drawScore();
    ~MainWindow();

private slots:
    void on_button_login_pressed();

    void on_button_register_pressed();

    void on_button_VT12_clicked();

    void on_button_VT23_clicked();

    void on_button_P12_clicked();

    void on_button_P22_clicked();

    void on_button_P32_clicked();

    void on_button_V12_clicked();

    void on_button_V13_clicked();

    void on_button_V23_clicked();

    void on_button_start_clicked();

    void on_button_score_clicked();

    void addScoreEntry();

    void on_button_retour_clicked();

private:
    Ui::MainWindow *ui;
    SfscaScene *scene;
    Login ulogin;
};

#endif // MAINWINDOW_H
