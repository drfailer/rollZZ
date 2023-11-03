#include <cstdint>
#include <iostream>
#include <vector>

#include <bsoncxx/builder/basic/document.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/exception/query_exception.hpp>
#include "mongodb.hpp"

using bsoncxx::builder::basic::kvp;
using bsoncxx::builder::basic::make_array;
using bsoncxx::builder::basic::make_document;

void testt()
{
  mongocxx::database db;
  try
  {
    // Create an instance.
    mongocxx::instance inst{};

    // Replace the connection string with your MongoDB deployment's connection string.
    const auto uri = mongocxx::uri{"mongodb://127.0.0.1:27017"};

    // Setup the connection and get a handle on the "admin" database.
    mongocxx::client client{uri};
    db = client["5e-database"];

    // Ping the database.
    const auto ping_cmd = bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp("ping", 1));
    db.run_command(ping_cmd.view());
    std::cout << "Pinged your deployment. You successfully connected to MongoDB!" << std::endl;

    mongocxx::collection collection = db["backgrounds"];
    auto cursor_all = collection.find({});

    std::cout << "Database Name: " << db.name() << std::endl;

        // List collections in the database.
        auto collections = db.list_collections();
        for (const auto& collection : collections) {
            std::cout << "Collection: " << collection["name"].get_string().value.to_string() << std::endl;
        }

        bsoncxx::document::view_or_value stats = db.run_command(bsoncxx::builder::basic::make_document(
                 bsoncxx::builder::basic::kvp("dbStats", 1)));
             std::cout << "Database Statistics:" << std::endl;
             std::cout << bsoncxx::to_json(stats) << std::endl;

    std::cout << "collection " << collection.name()
              << " contains these documents:" << std::endl;
    for (const auto& doc : cursor_all) {
        std::cout << bsoncxx::to_json(doc) << std::endl;
    }
  }
 catch (const mongocxx::query_exception& e) {
    std::cerr << "MongoDB query exception: " << e.code() << " === " << e.what() << std::endl;
    // Handle the exception as needed
} catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
    // Handle other exceptions
}
}
