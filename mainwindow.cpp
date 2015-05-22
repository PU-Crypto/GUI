#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>
#include <QInputDialog>
#include <QFileDialog>
#include <QClipboard>

mainWindow::mainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);
}

mainWindow::~mainWindow()
{
    delete ui;
}

//AES

void mainWindow::on_aes_btn_crypt_clicked()
{

    QString text = ui->aes_crypt->toPlainText();
    QString password = ui->aes_pass_left->text();

    params << root + "/AES/Rijndael.py" << "-m=e" << "-p=" + password << "-t=" + text;
    p.setProcessChannelMode(QProcess::MergedChannels);
    p.start("python3", params);
    p.waitForFinished(-1);

    QString p_stdout = p.readAll();
    ui->aes_crypt->setPlainText(p_stdout);
    params.clear();

}

void mainWindow::on_aes_btn_decrypt_clicked()
{

    QString text = ui->aes_decrypt->toPlainText();
    text.replace("\n", ""); //Verhindert Verfälschung der Eingabe durch Leerzeilen
    text.replace(" ", ""); //Verhindert Verfälschung der Eingabe durch Leerzeichen
    QString password = ui->aes_pass_right->text();

    params << root + "/AES/Rijndael.py" << "-m=d" << "-p=" + password << "-t=" + text;
    p.setProcessChannelMode(QProcess::MergedChannels);
    p.start("python3", params);
    p.waitForFinished(-1);

    QString p_stdout = p.readAll();
    ui->aes_decrypt->setPlainText(p_stdout);
    params.clear();

}

void mainWindow::on_aes_btn_copy_left_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->aes_crypt->toPlainText());
}

void mainWindow::on_aes_btn_copy_right_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->aes_decrypt->toPlainText());
}

void mainWindow::on_aes_clear_left_clicked()
{
    ui->aes_crypt->clear();
}

void mainWindow::on_aes_clear_right_clicked()
{
    ui->aes_decrypt->clear();
}

//RSA

void mainWindow::on_rsa_btn_keygen_clicked()
{
    bool status;
    QString keyname = QInputDialog::getText(this, "RSA Keygen", "Keyname:", QLineEdit::Normal, "NewKey", &status);
    if (status && !keyname.isEmpty())
    {
         params << "/home/jan/Dokumente/PU/RSA/TEST/RSA.py" << "-m=1" << "-n=" + keyname;
         p.setProcessChannelMode(QProcess::MergedChannels);
         p.start("python3", params);
         p.waitForFinished(-1);

         params.clear();
         msgbox.setText("Schlüssel erfolgreich erstellt und abgelegt.");
         msgbox.exec();
    }
}

void mainWindow::on_rsa_select_pubkey_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Select Keypair", root + "/GUI/build_debug/keys/", "JSON Key-Files (*.json)");
    ui->rsa_pubkey->setText(fileName);
}

void mainWindow::on_rsa_select_privkey_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Select Keypair", root + "/GUI/build_debug/keys/", "JSON Key-Files (*.json)");
    ui->rsa_privkey->setText(fileName);
}

void mainWindow::on_rsa_btn_crypt_clicked()
{
    QString text = ui->rsa_crypt->toPlainText();

    params << root + "/RSA/TEST/RSA.py" << "-m=2" << "-n=" + ui->rsa_pubkey->text() << "-t=" + text;
    p.setProcessChannelMode(QProcess::MergedChannels);
    p.start("python3", params);
    p.waitForFinished(-1);

    QString p_stdout = p.readAll();
    ui->rsa_crypt->setPlainText(p_stdout);
    params.clear();
}

void mainWindow::on_rsa_btn_decrypt_clicked()
{
    QString text = ui->rsa_decrypt->toPlainText();

    params << root + "/RSA/TEST/RSA.py" << "-m=3" << "-n=" + ui->rsa_privkey->text() << "-t=" + text;
    p.setProcessChannelMode(QProcess::MergedChannels);
    p.start("python3", params);
    p.waitForFinished(-1);

    QString p_stdout = p.readAll();
    ui->rsa_decrypt->setPlainText(p_stdout);
    params.clear();
}

void mainWindow::on_rsa_btn_copy_left_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->rsa_crypt->toPlainText());
}

void mainWindow::on_rsa_btn_copy_right_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->rsa_decrypt->toPlainText());
}

void mainWindow::on_rsa_clear_left_clicked()
{
    ui->rsa_crypt->clear();
}

void mainWindow::on_rsa_clear_right_clicked()
{
    ui->rsa_decrypt->clear();
}
