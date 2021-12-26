#ifndef VIGENERE_H
#define VIGENERE_H

#include <QDialog>

namespace Ui {
class Vigenere;
}

class Vigenere : public QDialog
{
    Q_OBJECT

public:
    explicit Vigenere(QWidget *parent = nullptr);
    ~Vigenere();

private slots:
    void on_EncryptpushButton_clicked();
    void on_DecryptpushButton_clicked();
    void on_ExitpushButton_clicked();
    QString Cryptofunction(QString& Text, const bool& is_Encryption);
    bool Keyfunction(const QString& Key, const int& Text_len);

private:
    QString Alphabet[2];
    Ui::Vigenere *ui;
};

#endif // VIGENERE_H
