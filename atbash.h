#ifndef ATBASH_H
#define ATBASH_H

#include <QDialog>

namespace Ui {
class Atbash;
}

class Atbash : public QDialog
{
    Q_OBJECT

public:
    explicit Atbash(QWidget *parent = nullptr);
    ~Atbash();

private slots:
    void on_EncryptpushButton_clicked();
    void on_DecryptpushButton_clicked();
    void on_ExitpushButton_clicked();
    QString Cryptofunction(QString& Text);

private:
    QString Alphabet[2];
    Ui::Atbash *ui;
};

#endif // ATBASH_H
