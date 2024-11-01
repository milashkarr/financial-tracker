#include "loginwindow.h"
#include <QMessageBox>

LoginWindow::LoginWindow(QWidget *parent) : QWidget(parent)
{
    // Устанавливаем фиксированный размер окна
    setFixedSize(450, 600);

    // Устанавливаем заголовок окна
    setWindowTitle("Авторизация");

    // Устанавливаем градиентный фон окна
    setStyleSheet("background: #FCFAFA;");

    // Создаем главный вертикальный layout
    QVBoxLayout *loginMainLayout = new QVBoxLayout(this);

    // Создаем QLabel для надписи "Логин"
    loginLabel = new QLabel("Логин", this);
    QFont loginFont("Calibri Light", 11); // Изменяем шрифт
    loginLabel->setFont(loginFont);
    loginLabel->setStyleSheet("color: black; background-color: #FCFAFA;");
    loginMainLayout->addWidget(loginLabel);

    // Создаем QLineEdit для ввода логина
    loginEdit = new QLineEdit(this);
    loginEdit->setStyleSheet("QLineEdit { border: 2px solid #C8D3D5; border-radius: 20px; padding: 8px; background-color: white; selection-background-color: darkgray; min-width: 150px; min-height: 35px; font-size: 16px; }");
    loginMainLayout->addWidget(loginEdit);

    // Создаем QLabel для надписи "Пароль"
    passwordLabel = new QLabel("Пароль", this);
    QFont passwordFont("Calibri Light", 11); // Изменяем шрифт
    passwordLabel->setFont(passwordFont);
    passwordLabel->setStyleSheet("color: black; background-color: #FCFAFA;");
    loginMainLayout->addWidget(passwordLabel);

    // Создаем QLineEdit для ввода пароля
    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password); // Скрываем вводимый пароль
    passwordEdit->setStyleSheet("QLineEdit { border: 2px solid #C8D3D5; border-radius: 20px; padding: 8px; background-color: white; selection-background-color: darkgray; min-width: 150px; min-height: 35px; font-size: 16px; }");
    loginMainLayout->addWidget(passwordEdit);

    // Создаем кнопку "Показать пароль"
    showPasswordButton = new QPushButton("Показать пароль", this);
    showPasswordButton->setFixedSize(130, 30);
    showPasswordButton->setStyleSheet("QPushButton {"
                                      "background-color: #6E8387;"
                                      "color: white;"
                                      "font-size: 15px;"
                                      "border-radius: 15px;"
                                      "border: 2px solid #5A6E72;"
                                      "}"
                                      "QPushButton:hover {"
                                      "background-color: #5A6E72;"
                                      "}");
    connect(showPasswordButton, &QPushButton::clicked, this, &LoginWindow::onShowPasswordButtonClicked);
    loginMainLayout->addWidget(showPasswordButton);

    // Создаем кнопку "Войти"
    loginButton = new QPushButton("Войти", this);
    loginButton->setFixedSize(150, 40);
    loginButton->setStyleSheet( "QPushButton {"
                               "background-color: #A4B8C4;"
                               "color: white;"
                               "font-size: 16px;"
                               "border-radius: 20px;"
                               "border: 2px solid #8E9EAB;"
                               "}"
                               "QPushButton:hover {"
                               "background-color: #8E9EAB;"
                               "}");

    // Добавляем тень к кнопке
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(20);
    shadowEffect->setColor(QColor(0, 0, 0, 80));
    shadowEffect->setOffset(0, 4);
    loginButton->setGraphicsEffect(shadowEffect);

    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::onLoginButtonClicked);
    loginMainLayout->addWidget(showPasswordButton, 0, Qt::AlignCenter);
    loginMainLayout->addWidget(loginButton, 0, Qt::AlignCenter);

    // Создаем QLabel для сообщения об успешной авторизации
    successLabel = new QLabel("", this);
    successLabel->setStyleSheet("color: green; background-color: #FCFAFA;");
    successLabel->hide(); // Скрываем метку до нажатия кнопки "Войти"
    loginMainLayout->addWidget(successLabel);

    // Устанавливаем отступы и интервалы
    loginMainLayout->setContentsMargins(50, 50, 50, 50);
    loginMainLayout->setSpacing(20);

    // Устанавливаем центральный виджет и layout
    setLayout(loginMainLayout);
}

void LoginWindow::onLoginButtonClicked() {
    // Обработка нажатия кнопки "Войти"
    QMessageBox::information(this, "Информация", "Вы успешно авторизовались!");
}

void LoginWindow::onShowPasswordButtonClicked() {
    // Обработка нажатия кнопки "Показать пароль"
    if (passwordEdit->echoMode() == QLineEdit::Password) {
        passwordEdit->setEchoMode(QLineEdit::Normal);
        showPasswordButton->setText("Скрыть пароль");
    } else {
        passwordEdit->setEchoMode(QLineEdit::Password);
        showPasswordButton->setText("Показать пароль");
    }
}
