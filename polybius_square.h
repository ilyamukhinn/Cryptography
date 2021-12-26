#ifndef POLYBIUS_SQUARE_H
#define POLYBIUS_SQUARE_H

#include <QDialog>
#include <QVector>

namespace Ui {
class Polybius_square;
}

class Polybius_square : public QDialog
{
    Q_OBJECT

public:
    explicit Polybius_square(QWidget *parent = nullptr);
    ~Polybius_square();

private slots:
    void on_EncryptpushButton_clicked();
    void on_DecryptpushButton_clicked();
    void on_ExitpushButton_clicked();
    QString Cryptofunction(QString& Text, const bool& is_Encryption);

private:
    QVector<QVector<QChar>> Square[2];
    Ui::Polybius_square *ui;
};

#endif // POLYBIUS_SQUARE_H
