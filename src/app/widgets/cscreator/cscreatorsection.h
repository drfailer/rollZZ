#ifndef CSCREATORSECTION_H
#define CSCREATORSECTION_H

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class SectionPopup;

class CSCreatorSection : public QWidget
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
    QPushButton addElementBtn;
    QList<QWidget*> content;

    SectionPopup *sectionPopup = nullptr;
};

#endif // CSCREATORSECTION_H
