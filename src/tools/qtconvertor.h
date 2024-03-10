#ifndef QTCONVERTOR_HPP
#define QTCONVERTOR_HPP
#include "convertor.hpp"
#include <QString>
#include <QSize>
#include <iostream>

// TODO rename
struct QtConvertor {
    deserialize_custom_type(QString, const std::string& str) {
        return QString::fromUtf8(str.substr(1, str.size() - 2).c_str());
    }

    serialize_custom_type(const QString& elt) {
        std::ostringstream oss;
        oss << "\"" << elt.toStdString() << "\"";
        return oss.str();
    }

    /**deserialize_custom_type(QVector<QString>, const std::string& str) {
        QVector<QString> result;
        std::stringstream ss(str);
        std::string s = "";
        char _;

        ss >> _;
        while(s != "]")
        {
            ss >> s >> _;
            std::cout << s << std::endl;
            result.push_back(QString::fromStdString(s));
        }
        return result;
    }

    serialize_custom_type(const QVector<QString> &elt) {
        std::ostringstream oss;
        oss << "[";
        for(QString str: elt)
        {
            oss << str.toStdString() << ",";
        }
        oss << "]";
        return oss.str();
    }**/

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

#endif
