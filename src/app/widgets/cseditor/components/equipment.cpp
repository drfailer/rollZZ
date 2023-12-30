#include "cseditor/components/equipment.h"
#include "CS/item.h"
#include "cseditor/components/component.h"
#include "cseditor/components/item.h"
#include <QPushButton>

namespace CSEditor {

/******************************************************************************/
/*                          constructor & destructor                          */
/******************************************************************************/

Equipment::Equipment(CS::Equipment *equipment, QWidget *parent)
    : Component(equipment->getTitle(), parent), equipment(equipment),
      addItemBtn("add item") {
    bodyAdd(&addItemBtn);
    connect(&addItemBtn, &QPushButton::clicked, this, [&] { addItem(); });
}

Equipment::~Equipment() {
    for (Item *item : items) {
        delete item;
    }
    items.clear();
}

/******************************************************************************/
/*                                manage items                                */
/******************************************************************************/

void Equipment::addItem() {
    if (items.count() < equipment->getMaxItems()) {
        CS::Item *item = new CS::Item();
        Item *newItemWgt = new Item(item, equipment->getUseWeight(), this);

        bodyInsert(bodyCount() - 1, newItemWgt);
        items.push_back(newItemWgt);
        connect(newItemWgt, &Item::remove, this, [&, item, wgt = newItemWgt] {
            items.removeOne(wgt);
            equipment->removeItem(item);
            bodyRemove(wgt);
            delete wgt;
        });
        // TODO not working yet
        /* newItemWgt->connectWeightEdit(this, [&](int) { */
        /*     equipment->setWeight(totalWeight()); */
        /*     setTitle(equipment->getTitle() + weightStr()); */
        /* }); */
    }
}

} // end namespace CSEditor
