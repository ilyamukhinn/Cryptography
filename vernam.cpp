#include "vernam.h"
#include "ui_vernam.h"
#include <bitset>
#include <QErrorMessage>

Vernam::Vernam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Vernam)
{
    ui->setupUi(this);
}

Vernam::~Vernam()
{
    delete ui;
}

QString Vernam::Cryptofunction(QString& Text)
{
    QString Key = ui->KeylineEdit->text();

    if(Key.length() > Text.length())
    {
        QErrorMessage errorMessage;
        errorMessage.showMessage("Key has to be less or equal than Text length");
        errorMessage.exec();
        return "";
    }

    int Key_index = 0;
    for(auto& ch : Text)
    {
        ch = QChar(ch.unicode() ^ Key[Key_index].unicode());
        Key_index = (Key_index + 1) % Key.length();
    }

    return Text;
}

void Vernam::on_EncryptpushButton_clicked()
{
    QString Open_message = ui->MessageplainTextEdit->toPlainText();
    ui->EncryptedplainTextEdit->setPlainText(Cryptofunction(Open_message));
}

void Vernam::on_DecryptpushButton_clicked()
{
    QString Encrypted_message = ui->EncryptedplainTextEdit->toPlainText();
    ui->DecryptedtextBrowser->setText(Cryptofunction(Encrypted_message));
}

void Vernam::on_ExitpushButton_clicked()
{
    this->close();
}
