#include "atbash.h"
#include "ui_atbash.h"

Atbash::Atbash(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Atbash)
{
    ui->setupUi(this);
    Alphabet[0] =  "abcdefghijklmnopqrstuvwxyz";
    Alphabet[1] =  "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

Atbash::~Atbash()
{
    delete ui;
}

void Atbash::on_EncryptpushButton_clicked()
{
    QString Open_message = ui->MessageplainTextEdit->toPlainText();
    ui->EncryptedplainTextEdit->setPlainText(Cryptofunction(Open_message));
}

void Atbash::on_DecryptpushButton_clicked()
{
    QString Encrypted_message = ui->EncryptedplainTextEdit->toPlainText();
    ui->DecryptedtextBrowser->setText(Cryptofunction(Encrypted_message));
}

QString Atbash::Cryptofunction(QString& Text)
{
    for(auto& ch : Text)
    {
        for(const auto& Alph : Alphabet)
        {
            int index = 0;
            ch = ((index = Alph.indexOf(ch)) != -1 ?
                        Alph[Alph.length() - 1 - index] : ch);
        }
    }

    return Text;
}

void Atbash::on_ExitpushButton_clicked()
{
    this->close();
}

