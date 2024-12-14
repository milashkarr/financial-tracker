#ifndef PRIMARYBUTTON_H
#define PRIMARYBUTTON_H

#include <QPushButton>

class PrimaryButton : public QPushButton
{
    Q_OBJECT

public:
    explicit PrimaryButton(const QString &text, QWidget *parent = nullptr);
};

#endif // PRIMARYBUTTON_H
