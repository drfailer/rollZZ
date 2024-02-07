#ifndef QTCONVERTOR_H
#define QTCONVERTOR_H

#include "convertor.hpp"
#include <QString>
#include <QSize>

struct QtConvertor {
  deserialize_custom_type(QString, const std::string& str) {
    return QString::fromUtf8(str.substr(1, str.size() - 2).c_str());
  }

  serialize_custom_type(const QString &elt) {
    std::ostringstream oss;
    oss << "\"" << elt.toStdString() << "\"";
    return oss.str();
  }

  deserialize_custom_type(QSize, const std::string& str) {
    int first,second;
    std::stringstream ss(str);
    char _;
    ss >> _ >> first >> _ >> second >> _;

    return QSize(first,second);
  }

  serialize_custom_type(const QSize &elt) {
    std::ostringstream oss;
    oss << "\(" << elt.width() << ":" << elt.height() << ")\"";
    return oss.str();
  }

  CONVERTOR;
};

#endif // QTCONVERTOR_H
