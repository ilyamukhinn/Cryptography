#ifndef SCITULA_H
#define SCITULA_H

#include <QDialog>

namespace Ui {
class Scitula;
}

class Scitula : public QDialog
{
    Q_OBJECT

public:
    explicit Scitula(QWidget *parent = nullptr);
    ~Scitula();

private slots:
    void on_EncryptpushButton_clicked();
    void on_DecryptpushButton_clicked();
    void on_ExitpushButton_clicked();
    QString Cryptofunction(QString& Text, const bool& is_Encryption);

private:
    Ui::Scitula *ui;
};

#endif // SCITULA_H
