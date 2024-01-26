#ifndef CREATECHARACTERPOPUP_HPP
#define CREATECHARACTERPOPUP_HPP
#include "config.h"
#include "tools/popup.h"
#include <QLabel>
#include <QLineEdit>
#include <QFileDialog>

class CreateCharacterPopup: public Tools::Popup {
public:
    CreateCharacterPopup():
        Tools::Popup("Create a new character"),
        nameLable("name:"),
        templateLabel("template:"),
        fileNameEdit(TEMPLATE_DIRECTORY),
        fileSelectButton("Browse")
    {
        add(&nameLable);
        add(&nameEdit);
        add(&templateLabel);
        add(&fileNameEdit);
        add(&fileSelectButton);
        connect(&fileSelectButton, &QPushButton::clicked, this, [&]{
                QString pathToFile = QFileDialog::getOpenFileName(this,
                        "find template",
                        fileNameEdit.text());

                if (!pathToFile.isEmpty()) {
                    fileNameEdit.setText(pathToFile);
                }
            });
    }
    ~CreateCharacterPopup() = default;

    /* accessors **************************************************************/

    QString getName() const {
        return nameEdit.text();
    }

    QString getTemplate() const {
        return fileNameEdit.text();
    }

private:
    QLabel nameLable;
    QLabel templateLabel;
    QLineEdit nameEdit;
    QLineEdit fileNameEdit;
    QPushButton fileSelectButton;
};

#endif
