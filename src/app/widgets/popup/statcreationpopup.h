#ifndef STATCREATIONPOPUP_H
#define STATCREATIONPOPUP_H

#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QWidget>

class StatCreationPopup : public QWidget
{
    Q_OBJECT
public:
    explicit StatCreationPopup(QWidget *parent = nullptr);
    QString getName() const { return nameEdit.text(); }
    int getValue() const { return valueMaxEdit.value(); }

signals:
    void confirm(bool);

private:
    QVBoxLayout mainLyt;
    QLabel title;
    QLineEdit nameEdit;
    QSpinBox valueMaxEdit;
    QComboBox diceEdit;
    QHBoxLayout btnLyt;
    QPushButton confirmBtn;
    QPushButton cancelBtn;
};

#endif // STATCREATIONPOPUP_H
