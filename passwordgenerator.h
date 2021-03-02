#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class PasswordGenerator; }
QT_END_NAMESPACE

class PasswordGenerator : public QMainWindow
{
    Q_OBJECT

public:
    PasswordGenerator(QWidget *parent = nullptr);
    ~PasswordGenerator();
    QString symbols = "qwertyuiopasdfghjklzxcvbnm1234567890QWERTYUIOPASDFGHJKLZXCVBNM";
    QString symbolsSpec = "qwertyuiopasdfghjklzxcvbnm1234567890QWERTYUIOPASDFGHJKLZXCVBNM!@#$%&*-_=~";

private slots:
    void on_GenerateBtn_clicked();

    void on_DefaultGenerationRB_clicked();

    void on_AcronymGenerationRB_clicked();

private:
    Ui::PasswordGenerator *ui;
};
#endif // PASSWORDGENERATOR_H
