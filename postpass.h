#ifndef POSTPASS_H
#define POSTPASS_H

#include <QDialog>
#include"data.h"
#include"editdel.h"
namespace Ui {
class postpass;
}

class postpass : public QDialog
{
    Q_OBJECT
public:
    explicit postpass(QWidget *parent = nullptr);
    ~postpass();

private slots:
    void on_AddButton_clicked();
    void on_ViewButton_clicked();

private:
    Ui::postpass *ui;
   class data *data1;
   class EditDel *deledits;
};
#endif // POSTPASS_H
