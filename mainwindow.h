#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QMessageBox>

namespace Ui {
class mainWindow;
}

class mainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit mainWindow(QWidget *parent = 0);
    ~mainWindow();
    QProcess p;
    QStringList params;
    QMessageBox msgbox;
    QString root = "/home/jan/Dokumente/PU";

private slots:

    void on_aes_btn_crypt_clicked();

    void on_aes_btn_decrypt_clicked();

    void on_aes_clear_left_clicked();

    void on_aes_clear_right_clicked();

    void on_rsa_btn_crypt_clicked();

    void on_rsa_btn_decrypt_clicked();

    void on_rsa_clear_left_clicked();

    void on_rsa_clear_right_clicked();

    void on_rsa_btn_keygen_clicked();

    void on_rsa_select_pubkey_clicked();

    void on_rsa_select_privkey_clicked();

    void on_rsa_btn_copy_left_clicked();

    void on_rsa_btn_copy_right_clicked();

    void on_aes_btn_copy_left_clicked();

    void on_aes_btn_copy_right_clicked();

private:
    Ui::mainWindow *ui;
};

#endif // MAINWINDOW_H
