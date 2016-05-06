#include "regexptest.h"
#include "ui_regexptest.h"

regexptest::regexptest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::regexptest)
{
    ui->setupUi(this);
}

regexptest::~regexptest()
{
    delete ui;
}

QString sidQRegExpEscape(QString regExp){return regExp.replace("\\","\\\\");}

void regexptest::on_pushButton_clicked()
{
    QString code = ui->plainTextEdit->toPlainText();
    QString rege = ui->lineEdit->text();

    QString esca = rege.replace("\\","\\\\");

                                // QRegExp::escape(rege); // shit
    ui->lineEdit_2->setText(esca);

    QRegExp QR(rege, Qt::CaseInsensitive);
    QStringList result;
    QHash<int, QStringList> allResult;

    int count = 0;
    int pos = 0;

    while ((pos = QR.indexIn(code, pos)) != -1) {

        ++count;
        pos += QR.matchedLength();

        result.clear();
        result.append(QR.capturedTexts());
        //result.append(QR.cap(1));
       // allResult.insert(count, QR.capturedTexts());

        int i = 0;
        int x = result.count();

        for(i=0; i<x; i++){
           ui->plainTextEdit_2->appendPlainText(QString::number(count)+"-"+QString::number(i)+" "+result.at(i));
        }
        //ui->plainTextEdit_2->appendPlainText("\n");
        //ui->plainTextEdit_2->appendPlainText(QR.cap(1));
    }
}
