#include "vigenere.h"
#include "ui_vigenere.h"
#include <QErrorMessage>

Vigenere::Vigenere(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Vigenere)
{
    ui->setupUi(this);
    Alphabet[0] =  "abcdefghijklmnopqrstuvwxyz";
    Alphabet[1] =  "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

Vigenere::~Vigenere()
{
    delete ui;
}

bool Vigenere::Keyfunction(const QString& Key, const int& Text_len)
{
    if(Key.length() > Text_len)
    {
        QErrorMessage errorMessage;
        errorMessage.showMessage("Key has to be less or equal than Text length");
        errorMessage.exec();
        return false;
    }

    QString Alph = Alphabet[0] + Alphabet[1];
    for(const auto& ch : Key)
    {
        if(Alph.indexOf(ch) == -1)
        {
            QErrorMessage errorMessage;
            errorMessage.showMessage("The key can only contain characters of the English alphabet");
            errorMessage.exec();
            return false;
        }
    }

    return true;
}

QString Vigenere::Cryptofunction(QString& Text, const bool& is_Encryption)
{
    QString Key = ui->KeylineEdit->text();
    if(!Keyfunction(Key, Text.length()))
    {
        return "";
    }

    int Key_index = 0;
    for(auto& ch : Text)
    {
        int Text_index = 0;
        for(const auto& Alph : Alphabet)
        {
            if((Text_index = Alph.indexOf(ch)) != -1)
            {
                if(is_Encryption)
                {
                    ch = Alph[(Text_index + Alph.indexOf(Key[Key_index])) % Alph.length()];
                }
                else
                {
                    int New_text_index = (Text_index - Alph.indexOf(Key[Key_index])) % Alph.length();
                    New_text_index = New_text_index >= 0 ? New_text_index : New_text_index + Alph.length();
                    ch = Alph[New_text_index];
                }

                Key_index = (Key_index + 1) % Key.length();
                break;
            }
        }
    }

    return Text;
}

void Vigenere::on_EncryptpushButton_clicked()
{
    QString Open_message = ui->MessageplainTextEdit->toPlainText();
    ui->EncryptedplainTextEdit->setPlainText(Cryptofunction(Open_message, true));
}

void Vigenere::on_DecryptpushButton_clicked()
{
    QString Encrypted_message = ui->EncryptedplainTextEdit->toPlainText();
    ui->DecryptedtextBrowser->setText(Cryptofunction(Encrypted_message, false));
}

void Vigenere::on_ExitpushButton_clicked()
{
    this->close();
}

