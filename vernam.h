#ifndef VERNAM_H
#define VERNAM_H

#include <QDialog>

namespace Ui {
class Vernam;
}

class Vernam : public QDialog
{
    Q_OBJECT

public:
    explicit Vernam(QWidget *parent = nullptr);
    ~Vernam();

private slots:
    void on_EncryptpushButton_clicked();
    void on_DecryptpushButton_clicked();
    void on_ExitpushButton_clicked();
    QString Cryptofunction(QString& Text);

private:
    Ui::Vernam *ui;
};

#endif // VERNAM_H
