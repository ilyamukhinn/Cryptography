#ifndef CAESAR_H
#define CAESAR_H

#include <QDialog>

namespace Ui {
class Caesar;
}

class Caesar : public QDialog
{
    Q_OBJECT

public:
    explicit Caesar(QWidget *parent = nullptr);
    ~Caesar();

private slots:
    void on_EncryptpushButton_clicked();
    void on_DecryptpushButton_clicked();
    void on_ExitpushButton_clicked();
    QString Cryptofunction(QString& Text, const bool& is_Encryption);

private:
    QString Alphabet[2];
    Ui::Caesar *ui;
};

#endif // CAESAR_H
