#include "cseditor/components/equipment.h"
#include "CS/item.h"
#include "tools/component.h"
#include "cseditor/components/item.h"
#include <QPushButton>

namespace CSEditor {

/******************************************************************************/
/*                          constructor & destructor                          */
/******************************************************************************/

Equipment::Equipment(CS::Equipment *equipment, QWidget *parent)
    : Tools::Component(equipment->getTitle(), parent), equipment(equipment),
      addItemBtn("add item") {
    bodyAdd(&addItemBtn);

    for (CS::Item *item : equipment->getItems()) {
        loadItem(item);
    }

    connect(&addItemBtn, &QPushButton::clicked, this, [&] { addItem(); });
    setContentsMargins(0, 5, 0, 5);
}

Equipment::~Equipment() {
}

/******************************************************************************/
/*                                manage items                                */
/******************************************************************************/

void Equipment::addItem() {
    if (equipment->count() < equipment->getMaxItems()) {
        CS::Item *item = new CS::Item();
        Item *newItemWgt = new Item(item, equipment->getUseWeight(), this);

        equipment->addItem(item);
        insertAndConnectItem(item, newItemWgt);
    }
}

void Equipment::loadItem(CS::Item *item) {
    Item *newItemWgt = new Item(item, equipment->getUseWeight(), this);
    insertAndConnectItem(item, newItemWgt);
}

void Equipment::insertAndConnectItem(CS::Item *item, Item* newItemWgt) {
    bodyInsert(bodyCount() - 1, newItemWgt);
    connect(newItemWgt, &Item::remove, this, [&, item, wgt = newItemWgt] {
                equipment->removeItem(item);
                bodyRemove(wgt);
            });
    // TODO not working yet
    /* newItemWgt->connectWeightEdit(this, [&](int) { */
    /*     equipment->setWeight(totalWeight()); */
    /*     setTitle(equipment->getTitle() + weightStr()); */
    /* }); */
}

} // end namespace CSEditor
