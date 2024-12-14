#include "primarybutton.h"

PrimaryButton::PrimaryButton(const QString &text, QWidget *parent)
    : QPushButton(text, parent)
{
    setStyleSheet(
        "QPushButton {"
        "background-color: #A4B8C4;"
        "color: white;"
        "font-size: 16px;"
        "border-radius: 20px;"
        "border: 2px solid #8E9EAB;"
        "}"
        "QPushButton:hover {"
        "background-color: #8E9EAB;"
        "}"
        );
}
