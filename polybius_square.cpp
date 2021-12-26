#include "polybius_square.h"
#include "ui_polybius_square.h"
#include <qalgorithms.h>

Polybius_square::Polybius_square(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Polybius_square)
{
    ui->setupUi(this);
    Square[0] = {
        {'a', 'b', 'c', 'd', 'e'},
        {'f', 'g', 'h', 'i', 'k'},
        {'l', 'm', 'n', 'o', 'p'},
        {'q', 'r', 's', 't', 'u'},
        {'v', 'w', 'x', 'y', 'z'}
    };
    Square[1] = {
        {'A', 'B', 'C', 'D', 'E'},
        {'F', 'G', 'H', 'I', 'K'},
        {'L', 'M', 'N', 'O', 'P'},
        {'Q', 'R', 'S', 'T', 'U'},
        {'V', 'W', 'X', 'Y', 'Z'}
    };
}

Polybius_square::~Polybius_square()
{
    delete ui;
}

void Polybius_square::on_EncryptpushButton_clicked()
{
    QString Open_message = ui->MessageplainTextEdit->toPlainText();
    ui->EncryptedplainTextEdit->setPlainText(Cryptofunction(Open_message, true));
}

void Polybius_square::on_DecryptpushButton_clicked()
{
    QString Encrypted_message = ui->EncryptedplainTextEdit->toPlainText();
    ui->DecryptedtextBrowser->setText(Cryptofunction(Encrypted_message, false));
}

void Polybius_square::on_ExitpushButton_clicked()
{
    this->close();
}

QString Polybius_square::Cryptofunction(QString& Text, const bool& is_Encryption)
{
    Text.replace('j', 'i');
    Text.replace('J', 'I');
    int index = -1;

    for(auto& ch : Text)
    {
        for(const auto& Key : Square)
        {
            for(int j = 0; j < Key.length(); j++)
            {
                if((index = Key[j].indexOf(ch)) != -1)
                {
                    if(is_Encryption)
                    {
                        ch = Key[(j + 1) % Key.length()][index];
                    }
                    else
                    {
                        int _j = j == 0 ? Key.length() - 1 : j - 1;
                        ch = Key[_j][index];
                    }
                    break;
                }
            }
        }
    }

    return Text;
}
