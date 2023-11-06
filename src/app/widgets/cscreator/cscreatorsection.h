#ifndef CSCREATORSECTION_H
#define CSCREATORSECTION_H

#include <QComboBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QFrame>

enum ComponentTypes {
    None = 0,
    BasicStat = 1,
    BonusStat = 2,
    ListStat = 3,
    Descriptor = 4,
    Attacks = 5,
};

class SectionPopup;

class CSCreatorSection : public QFrame
{
    Q_OBJECT
public:
    explicit CSCreatorSection(const QString& title, QWidget *parent = nullptr);
    ~CSCreatorSection();
    void setTitle(QString newTitle) { title.setText(newTitle); }
    void add(QWidget* wgt);
    void move(bool up, QWidget* wgt);

    // TODO: write accessors
    QString getTitle() const { return title.text(); }
    void setTitle(const QString& newTitle) { title.setText(newTitle); }

signals:
    void remove();
    void moveUp();
    void moveDown();

private slots:
    void settingsPopup();
    void addElement(int element);

private:
    QVBoxLayout mainLyt;
    QHBoxLayout headerLyt; // contains the title and the buttons
    QVBoxLayout bodyLyt;
    QLabel title;
    QHBoxLayout titleLyt;
    QHBoxLayout btnsLyt;
    QPushButton removeBtn;
    QPushButton settingsBtn;
    QPushButton moveUpBtn;
    QPushButton moveDownBtn;
    QComboBox addElementBtn;
    QList<QWidget*> content;

    SectionPopup *sectionPopup = nullptr;
};

#endif // CSCREATORSECTION_H
