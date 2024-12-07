#ifndef REGISTRATIONFORM_H
#define REGISTRATIONFORM_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

class RegistrationForm : public QWidget
{
    Q_OBJECT

public:
    RegistrationForm(QWidget *parent = nullptr);

private slots:
    void onRegisterClicked();

private:
    QLineEdit *firstNameEdit;
    QLineEdit *lastNameEdit;
    QLineEdit *phoneNumberEdit;
    QLineEdit *emailEdit;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;
    QLineEdit *dayEdit;
    QLineEdit *monthEdit;
    QLineEdit *yearEdit;
    QPushButton *registerButton;
    QLabel *statusLabel;
};

#endif // REGISTRATIONFORM_H
