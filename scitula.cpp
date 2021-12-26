#include "scitula.h"
#include "ui_scitula.h"
#include <QVector>
#include <QErrorMessage>

Scitula::Scitula(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Scitula)
{
    ui->setupUi(this);
}

Scitula::~Scitula()
{
    delete ui;
}

void Scitula::on_EncryptpushButton_clicked()
{
    QString Open_message = ui->MessageplainTextEdit->toPlainText();
    ui->EncryptedplainTextEdit->setPlainText(Cryptofunction(Open_message, true));
}

void Scitula::on_DecryptpushButton_clicked()
{
    QString Encrypted_message = ui->EncryptedplainTextEdit->toPlainText();
    ui->DecryptedtextBrowser->setText(Cryptofunction(Encrypted_message, false));
}

QString Scitula::Cryptofunction(QString& Text, const bool& is_Encryption)
{
    int M = ui->KeyspinBox->value();

    if(M > Text.length() || M <= 0)
    {
        QErrorMessage errorMessage;
        errorMessage.showMessage("Key has to be less or equal than Text length and greater than 0");
        errorMessage.exec();
        return "";
    }

    QString _Text;
    int index = 0;
    int N = ((Text.length() - 1) / M) + 1;
    int missing = N*M - Text.length();

    if(!is_Encryption)
    {
        std::swap(N, M);
    }

    for(int i = 0; i < M; i++)
    {

        int _j = 0;

        if(is_Encryption)
        {
            _j = (((i >= (M - missing)) && missing) ? (N - 1) : N);
        }
        else
        {
            _j = ((i == (M - 1)) ? (N - missing) : N);
        }

        int step = M;
        bool f = false;

        for(int j = 0; j < _j; j++)
        {
            if(j >= (N - missing) && !f && !is_Encryption)
            {
                step--;
                f = !f;
            }

            _Text += Text[index + i];
            index += step;
        }

        index = 0;
    }

    return _Text;
}

void Scitula::on_ExitpushButton_clicked()
{
    this->close();
}

