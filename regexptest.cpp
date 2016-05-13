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
    useCase_translate();
    QString code = ui->plainTextEdit->toPlainText();
    QString rege = ui->lineEdit->text();



    if(rege.length()<1) return;

    QFile file("rege.log");
    if(file.open(QIODevice::WriteOnly)){
        file.write(QByteArray::fromStdString(rege.toStdString()));
        file.write("\n");
    };
    file.close();

    //QString esca = rege.replace("\\","\\\\");

                                // QRegExp::escape(rege); // shit
    //ui->lineEdit_2->setText(esca);

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

        int i = 0;
        int x = result.count();

        for(i=0; i<x; i++){
           ui->plainTextEdit_2->appendPlainText(QString::number(count)+"-"+QString::number(i)+" "+result.at(i));
        }

    }
}

void regexptest::useCase_translate(){
    QString rege = ui->lineEdit->text();
    QString repl = rege.replace("\\", "\\\\");

    ui->lineEdit_2->setText(repl);
}

void regexptest::on_lineEdit_editingFinished()
{
    useCase_translate();
}

void regexptest::on_pushButton_3_clicked()
{
    ui->plainTextEdit->setPlainText("debug_prnt (\"Module IP1 was run at %02d:%02d\", m_pos, m_channel);");
}

void regexptest::on_pushButton_2_clicked()
{
    ui->plainTextEdit_2->setPlainText("");
}
