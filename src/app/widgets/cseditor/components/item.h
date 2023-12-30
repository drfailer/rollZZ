#ifndef CSEDITOR_ITEM_HPP
#define CSEDITOR_ITEM_HPP

#include "CS/item.h"
#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QBoxLayout>
#include <QPushButton>
#include <functional>

namespace CSEditor {

class Item : public QWidget {
    Q_OBJECT
  public:
    Item(CS::Item *item, bool useWeight, QWidget *parent = nullptr);
    ~Item() = default;
    void connectWeightEdit(QObject* object, std::function<void(int)> function);
    int getWeight() const { return weightEdit.value(); }

  signals:
    void remove();

  private:
    CS::Item *item;
    QHBoxLayout layout;
    QLineEdit nameEdit;
    QLineEdit descriptionEdit;
    QSpinBox quantityEdit;
    QSpinBox weightEdit;
    // NOTE: we may add the possibility to move stuff in the inventory
    QPushButton removeBtn;
};

} // end namespace CSEditor

#endif
