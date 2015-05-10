#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class mainWindow;
}

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = 0);
    ~mainWindow();

private slots:

    void on_aes_btn_crypt_clicked();

    void on_aes_btn_decrypt_clicked();

private:
    Ui::mainWindow *ui;
};

#endif // MAINWINDOW_H
