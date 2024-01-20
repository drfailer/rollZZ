#ifndef FILESELECTORPOPUP_HPP
#define FILESELECTORPOPUP_HPP
#include "tools/popup.h"
#include <QWidget>
#include <QPushButton>
#include <QFileDialog>
#include <QDir>
#include <QLineEdit>
#include "config.h"

namespace CSCreator {

class FileSelectorPopup : public Tools::Popup {
public:
    FileSelectorPopup(const QString& name, const QString& defaultFile):
        Popup(name),
        fileNameEdit((defaultFile.isEmpty()) ? TEMPLATE_DIRECTORY : defaultFile),
        fileSelectButton("Browse")
    {
        add(&fileNameEdit);
        add(&fileSelectButton);
        connect(&fileSelectButton, &QPushButton::clicked, this, [&]{
                QString pathToFile = QFileDialog::getOpenFileName(this,
                        "find files",
                        fileNameEdit.text());

                if (!pathToFile.isEmpty()) {
                    fileNameEdit.setText(pathToFile);
                }
            });
    }
    ~FileSelectorPopup() = default;
    QString getFile() const { return fileNameEdit.text(); }

private:
    QLineEdit fileNameEdit;
    QPushButton fileSelectButton;
};

} // end namespace CSCreator

#endif
