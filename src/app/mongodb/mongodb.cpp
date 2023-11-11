#include "mongodb.hpp"


mongocxx::instance inst{};
mongocxx::client MongoDB::client = mongocxx::client{ mongocxx::uri{"mongodb://127.0.0.1:27017"}};
mongocxx::database MongoDB::db = client["default"];


void MongoDB::init(std::string db_str){
    try{
    // Replace the connection string with your MongoDB deployment's connection string.
    db = client[db_str];

    // Ping the database.
    const auto ping_cmd = bsoncxx::builder::basic::make_document(bsoncxx::builder::basic::kvp("ping", 1));
    db.run_command(ping_cmd.view());
    std::cout << "Pinged your deployment. You successfully connected to MongoDB!" << std::endl;
    }
    catch(...){
        throw std::exception();
    }
}

void MongoDB::insertDocument(bsoncxx::document::view_or_value doc, std::string collection_str){
    mongocxx::collection collection = db[collection_str];
    collection.insert_one(doc);
    std::cout << "end of insertDocument" << std::endl;
}

void MongoDB::requestAll(std::string collection_str){
    mongocxx::collection collection = db[collection_str];
    auto cursor_all = collection.find({});
    std::cout << "collection " << collection.name()
              << " contains these documents:" << std::endl;
    for (auto doc : cursor_all) {
        std::cout << bsoncxx::to_json(doc, bsoncxx::ExtendedJsonMode::k_relaxed) << std::endl;
    }
    std::cout << std::endl;
    std::cout << "end of requestAll" << std::endl;
}

bsoncxx::document::value MongoDB::requestOne(std::string collection_str){
    mongocxx::collection collection = db[collection_str];
    std::cout << "end of requestOne" << std::endl;
    return  collection.find_one({}).value();
}

bsoncxx::document::view_or_value toDocument(Dice d){
    bsoncxx::document::value document = make_document(
               kvp("faces", d.getFaces()),
               kvp("diceNumber",d.getDiceNumber()));
    std::cout << "end of toDocument" << std::endl;
    return document;
}

Dice toObject(bsoncxx::document::value doc){
    bsoncxx::document::view doc_view= doc.view();
    std::cout << "end of toObject" << std::endl;
    return Dice(doc_view["faces"].get_int32().value,doc_view["diceNumber"].get_int32().value);
}
