#ifndef REGEXPTEST_H
#define REGEXPTEST_H

#include <QMainWindow>

namespace Ui {
class regexptest;
}

class regexptest : public QMainWindow
{
    Q_OBJECT

public:
    explicit regexptest(QWidget *parent = 0);
    ~regexptest();

private slots:
    void on_pushButton_clicked();

private:
    Ui::regexptest *ui;
};

#endif // REGEXPTEST_H