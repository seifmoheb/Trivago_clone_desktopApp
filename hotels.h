#ifndef HOTELS_H
#define HOTELS_H

#include <QDialog>

namespace Ui {
class hotels;
}

class hotels : public QDialog
{
    Q_OBJECT

public:
    explicit hotels(QWidget *parent = nullptr);
    ~hotels();

private:
    Ui::hotels *ui;
};

#endif // HOTELS_H
