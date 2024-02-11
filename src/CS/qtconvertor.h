#ifndef QTCONVERTOR_HPP
#define QTCONVERTOR_HPP
#include "convertor.hpp"
#include <QString>

// TODO rename
struct QtConvertor {
    deserialize_custom_type(QString, const std::string& str) {
        return QString::fromUtf8(str.substr(1, str.size() - 2).c_str());
    }

    serialize_custom_type(const QString &elt) {
        std::ostringstream oss;
        oss << "\"" << elt.toStdString() << "\"";
        return oss.str();
    }

    CONVERTOR;
};

#endif
