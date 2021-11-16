#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include"admin.h"
#include"results.h"
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    void save();
    ~MainWindow();

private slots:
    void on_button_clicked();
    void on_commandLinkButton_clicked();


    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_dateEdit_userDateChanged(const QDate &date);

    void on_dateEdit_2_userDateChanged(const QDate &date);


private:
    Ui::MainWindow *ui;
    Admin *amn;
     results *result1;
};
#endif
