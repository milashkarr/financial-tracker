#include "registrationform.h"
#include "loginwindow.h" // Добавляем заголовок для LoginWindow
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QLineEdit>
#include <QGraphicsDropShadowEffect>

RegistrationForm::RegistrationForm(QWidget *parent)
    : QWidget(parent)
{
    // Устанавливаем фиксированный размер окна
    setFixedSize(480, 680);

    // Устанавливаем заголовок окна
    setWindowTitle("Регистрация");

    // Устанавливаем градиентный фон окна
    setStyleSheet("background: #FCFAFA;");

    // Создаем главный вертикальный layout
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Создаем QLabel для надписей
    QLabel *firstNameLabel = new QLabel("Имя:", this);
    QLabel *lastNameLabel = new QLabel("Фамилия:", this);
    QLabel *birthDateLabel = new QLabel("Дата рождения:", this);
    QLabel *phoneNumberLabel = new QLabel("Номер телефона:", this);
    QLabel *emailLabel = new QLabel("Email:", this);
    QLabel *usernameLabel = new QLabel("Логин:", this);
    QLabel *passwordLabel = new QLabel("Пароль:", this);

    // Устанавливаем шрифт и стиль для меток
    QFont labelFont("Calibri Light", 10); // Уменьшаем размер шрифта
    firstNameLabel->setFont(labelFont);
    lastNameLabel->setFont(labelFont);
    birthDateLabel->setFont(labelFont);
    phoneNumberLabel->setFont(labelFont);
    emailLabel->setFont(labelFont);
    usernameLabel->setFont(labelFont);
    passwordLabel->setFont(labelFont);

    firstNameLabel->setStyleSheet("color: black; background-color: #FCFAFA;");
    lastNameLabel->setStyleSheet("color: black; background-color: #FCFAFA;");
    birthDateLabel->setStyleSheet("color: black; background-color: #FCFAFA;");
    phoneNumberLabel->setStyleSheet("color: black; background-color: #FCFAFA;");
    emailLabel->setStyleSheet("color: black; background-color: #FCFAFA;");
    usernameLabel->setStyleSheet("color: black; background-color: #FCFAFA;");
    passwordLabel->setStyleSheet("color: black; background-color: #FCFAFA;");

    // Создаем QLineEdit для ввода данных
    firstNameEdit = new QLineEdit(this);
    lastNameEdit = new QLineEdit(this);
    phoneNumberEdit = new QLineEdit(this);
    emailEdit = new QLineEdit(this);
    usernameEdit = new QLineEdit(this);
    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Normal); // Устанавливаем режим отображения пароля

    dayEdit = new QLineEdit(this);
    dayEdit->setPlaceholderText("День");
    QString dateEditStyle = "QLineEdit { border: 2px solid #C8D3D5; border-radius: 17px; padding: 6px; background-color: white; selection-background-color: darkgray; min-width: 57px; min-height: 30px; font-size: 14px; }";
    monthEdit = new QLineEdit(this);
    monthEdit->setPlaceholderText("Месяц");
    yearEdit = new QLineEdit(this);
    yearEdit->setPlaceholderText("Год");

    // Устанавливаем стили для QLineEdit
    QString lineEditStyle = "QLineEdit { border: 2px solid #C8D3D5; border-radius: 15px; padding: 6px; background-color: white; selection-background-color: darkgray; min-width: 120px; min-height: 30px; font-size: 14px; }";
    firstNameEdit->setStyleSheet(lineEditStyle);
    lastNameEdit->setStyleSheet(lineEditStyle);
    phoneNumberEdit->setStyleSheet(lineEditStyle);
    emailEdit->setStyleSheet(lineEditStyle);
    usernameEdit->setStyleSheet(lineEditStyle);
    passwordEdit->setStyleSheet(lineEditStyle);
    //dayEdit->setStyleSheet(lineEditStyle);
    //monthEdit->setStyleSheet(lineEditStyle);
    //yearEdit->setStyleSheet(lineEditStyle);
    dayEdit->setStyleSheet(dateEditStyle);
    monthEdit->setStyleSheet(dateEditStyle);
    yearEdit->setStyleSheet(dateEditStyle);

    // Создаем кнопку "Зарегистрироваться"
    registerButton = new QPushButton("Зарегистрироваться", this);
    registerButton->setFixedSize(200, 35); // Увеличиваем ширину кнопки
    registerButton->setStyleSheet("QPushButton {"
                                  "background-color: #A4B8C4;"
                                  "color: white;"
                                  "font-size: 16px;" // Уменьшаем размер шрифта
                                  "border-radius: 15px;" // Уменьшаем радиус закругления
                                  "border: 2px solid #8E9EAB;"
                                  "}"
                                  "QPushButton:hover {"
                                  "background-color: #8E9EAB;"
                                  "}");

    // Добавляем тень к кнопке
    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect(this);
    shadowEffect->setBlurRadius(15); // Уменьшаем размытие тени
    shadowEffect->setColor(QColor(0, 0, 0, 80));
    shadowEffect->setOffset(0, 3); // Уменьшаем смещение тени
    registerButton->setGraphicsEffect(shadowEffect);

    // Создаем QLabel для сообщения о статусе регистрации
    statusLabel = new QLabel("", this);
    statusLabel->setStyleSheet("color: #0CCA4A; background-color: #FCFAFA;"); // Изменяем цвет текста
    statusLabel->hide(); // Скрываем метку до нажатия кнопки "Зарегистрироваться"

    // Создаем пустой QLabel для разделения строк ввода
    QLabel *separatorLabel = new QLabel("", this);
    separatorLabel->setFixedHeight(1); // Устанавливаем высоту разделителя

    // Создаем пустой QLabel для разделения между строкой ввода пароля и кнопкой "Зарегистрироваться"
    QLabel *passwordButtonSeparator = new QLabel("", this);
    passwordButtonSeparator->setFixedHeight(1); // Устанавливаем высоту разделителя

    // Создаем вертикальный layout и добавляем в него виджеты
    mainLayout->addWidget(firstNameLabel);
    mainLayout->addWidget(firstNameEdit);
    mainLayout->addWidget(lastNameLabel);
    mainLayout->addWidget(lastNameEdit);
    //mainLayout->addWidget(separatorLabel); // Добавляем разделитель

    // Создаем горизонтальный layout для даты рождения
    QHBoxLayout *birthDateLayout = new QHBoxLayout;
    birthDateLayout->addWidget(birthDateLabel);
    birthDateLayout->addWidget(dayEdit);
    birthDateLayout->addWidget(monthEdit);
    birthDateLayout->addWidget(yearEdit);
    mainLayout->addLayout(birthDateLayout);

    mainLayout->addWidget(phoneNumberLabel);
    mainLayout->addWidget(phoneNumberEdit);
    mainLayout->addWidget(emailLabel);
    mainLayout->addWidget(emailEdit);
    mainLayout->addWidget(usernameLabel);
    mainLayout->addWidget(usernameEdit);
    mainLayout->addWidget(passwordLabel);
    mainLayout->addWidget(passwordEdit);
    //mainLayout->addWidget(passwordButtonSeparator); // Добавляем разделитель
    mainLayout->addWidget(registerButton, 0, Qt::AlignCenter);
    mainLayout->addWidget(statusLabel);

    // Устанавливаем отступы и интервалы
    mainLayout->setContentsMargins(30, 30, 30, 30); // Уменьшаем отступы
    mainLayout->setSpacing(15); // Уменьшаем интервалы

    // Устанавливаем центральный виджет и layout
    setLayout(mainLayout);

    // Подключаем сигнал нажатия кнопки к слоту
    connect(registerButton, &QPushButton::clicked, this, &RegistrationForm::onRegisterClicked);
}

void RegistrationForm::onRegisterClicked()
{
    QString firstName = firstNameEdit->text();
    QString lastName = lastNameEdit->text();
    QString phoneNumber = phoneNumberEdit->text();
    QString email = emailEdit->text();
    QString username = usernameEdit->text();
    QString password = passwordEdit->text();
    QString day = dayEdit->text();
    QString month = monthEdit->text();
    QString year = yearEdit->text();

    if (firstName.isEmpty() || lastName.isEmpty() || phoneNumber.isEmpty() || email.isEmpty() || username.isEmpty() || password.isEmpty() || day.isEmpty() || month.isEmpty() || year.isEmpty()) {
        statusLabel->setText("Пожалуйста, заполните все поля.");
        statusLabel->setStyleSheet("color: #0CCA4A; background-color: #FCFAFA;"); // Изменяем цвет текста
        statusLabel->show();
    } else {
        // Здесь можно добавить логику для сохранения данных регистрации
        QMessageBox::information(this, "Регистрация", "Регистрация успешна!");
        statusLabel->setText("Регистрация успешна!");
        statusLabel->setStyleSheet("color: #0CCA4A; background-color: #FCFAFA;"); // Изменяем цвет текста
        statusLabel->show();

        // Открываем окно входа
        LoginWindow *loginWindow = new LoginWindow();
        loginWindow->show();

        // Закрываем текущее окно регистрации
        this->close();
    }
}
