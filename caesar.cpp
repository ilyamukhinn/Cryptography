#include "caesar.h"
#include "ui_caesar.h"

Caesar::Caesar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Caesar)
{
    ui->setupUi(this);
    Alphabet[0] =  "abcdefghijklmnopqrstuvwxyz";
    Alphabet[1] =  "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

Caesar::~Caesar()
{
    delete ui;
}

void Caesar::on_EncryptpushButton_clicked()
{
    QString Open_message = ui->MessageplainTextEdit->toPlainText();
    ui->EncryptedplainTextEdit->setPlainText(Cryptofunction(Open_message, true));
}

void Caesar::on_DecryptpushButton_clicked()
{
    QString Encrypted_message = ui->EncryptedplainTextEdit->toPlainText();
    ui->DecryptedtextBrowser->setText(Cryptofunction(Encrypted_message, false));
}

QString Caesar::Cryptofunction(QString& Text, const bool& is_Encryption)
{
    int key_sign = is_Encryption ? -1 : 1;
    int key = ui->KeyspinBox->value();

    for(auto& ch : Text)
    {
        for(const auto& Alph : Alphabet)
        {
            int index = Alph.indexOf(ch);

            if(index == -1)
            {
                continue;
            }

            index = (((index + (key_sign * key)) % Alph.length()) + Alph.length()) % Alph.length();
            ch = Alph[index];
        }
    }

    return Text;
}

void Caesar::on_ExitpushButton_clicked()
{
    this->close();
}



