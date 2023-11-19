#ifndef MONGODB_HPP
#define MONGODB_HPP

#include <iostream>

#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/array.hpp>

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/exception/query_exception.hpp>

#include<exception>
#include"../CS/dice.h"
#include<mongocxx/exception/bulk_write_exception.hpp>

#include <cstddef>
#include <iostream>
#include <tuple>
#include <functional>
#include <vector>
#include <string>
#include <sstream>

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_array;
using bsoncxx::builder::basic::make_document;


class MongoDB {

public:
static void init(std::string db_str);
static void insertDocument(bsoncxx::document::view_or_value doc, std::string collection_str);
static void requestAll(std::string collection_str);
static bsoncxx::document::value requestOne(std::string collection_str);

private:
static mongocxx::database db;
static mongocxx::client client;
};

bsoncxx::document::view_or_value toDocument(Dice d);
Dice toObject(bsoncxx::document::value doc);

#endif // MONGODB_HPP
