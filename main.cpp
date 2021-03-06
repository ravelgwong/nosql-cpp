#include "DBControll.hpp"
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "httplib.h"
#include <iostream>
#include <string>

int main() {
    using namespace httplib;
    Server svr;
    DBControll db;

    svr.Get("/", [](const Request& /*req*/, Response& res) {
        res.set_content("GET on :8888 to get all commands\n"
            "PUT on :8888 with body (name:collectionName) to create a new collection\n"
            "PUT on :8888/collection/{name} with (name:docname,value:docvalue) to create a new document\n"
            "POST on : :8888/collection/{name} with (name:docname,value:docvalue) to create a new document\n"
            "DELETE on :8888/collection/{name} to delete collection {name}\n"
            "DELETE on :8888/collection/{name}/doc/{docname} to delete document {docname} on collection {name}\n"
            "GET on :8888/collection/{name}/doc/{docname} to get document\n"
            "GET on :8888/collection/{name} to get data in a collection as JSON\n"
            , "text/plain");
     });

    // GET REQUEST - Get Collection
    svr.Get(R"(/collection/([a-zA-Z]+))", [&](const Request& req, Response& res) {
        auto collection = req.matches[1]; //get the collection name from the request URL
        std::string result{ db.getCollectionString(collection) };
        std::cout << "GET on " << collection << std::endl;
        res.set_content(result, "text/plain"); //return all string inside collection
     });

    // GET REQUEST - Get Document
    svr.Get(R"(/collection/([a-zA-Z]+)/doc/([a-zA-Z]+))", [&](const Request& req, Response& res) {
        std::string collection = req.matches[1];
        std::string doc = req.matches[2];
        std::string result{ db.getDocumentString(collection,doc) };
        std::cout << "GET on " << collection << "/" << doc << std::endl;
        res.set_content(result, "text/plain");
     });

    // DELETE REQUEST - Delete Document
    svr.Delete(R"(/collection/([a-zA-Z]+)/doc/([a-zA-Z]+))", [&](const Request& req, Response& res) {
        std::string collection = req.matches[1];
        std::string doc = req.matches[2];
        bool result{ db.deleteDocument(collection,doc) };
        std::cout << "DELETE on " << collection << "/" << doc << " > " 
            << result <<  std::endl;
        std::string resStr = "{ 'error':'Could not delete document' }";
        if (result) {
            resStr = { db.getCollectionString(collection) };
        }
        res.set_content(resStr, "text/plain");
     });

    // DELETE REQUEST - Delete collection
    svr.Delete(R"(/collection/([a-zA-Z]+))", [&](const Request& req, Response& res) {
        std::string collection = req.matches[1];
        bool result{ db.deleteCollection(collection) };
        std::cout << "DELETE on " << collection << " > "
            << result << std::endl;
        std::string resStr = "{ 'error':'Could not delete collection' }";
        if (result) {
            resStr = "{}";
        }
        res.set_content(resStr, "text/plain");
     });

    // POST REQUEST - UPDATE DOCUMENT
    svr.Post(R"(/collection/([a-zA-Z]+))", [&](const Request& req, Response& res) {
        std::string collection = req.matches[1];
        if (!(req.has_file("name") && req.has_file("value"))) {
            res.set_content("{'error':'POST request must contains NAME and VALUE'}", "text/plain");
            return;
        }
        const auto& name = req.get_file_value("name").content;
        const auto& value = req.get_file_value("value").content;
        bool result{ db.updateDocument(collection, name, value) };
        std::cout << "UPDATE on " << collection << "/" << name << " with " << value 
            << " > " << result << std::endl;
        std::string resStr = "{ 'error':'Could not update document' }";
        if (result) {
           resStr = (db.getCollectionString(collection));
        }
        res.set_content(resStr, "text/plain");
    });
    
    // PUT REQUEST - CREATE DOCUMENT
    svr.Put(R"(/collection/([a-zA-Z]+))", [&](const Request& req, Response& res) {
        std::string collection = req.matches[1];
        if (!(req.has_file("name") && req.has_file("value"))) {
            res.set_content("{'error':'PUT request must contains NAME and VALUE'}", "text/plain");
            return;
        }
        const std::string name = req.get_file_value("name").content;
        const std::string value = req.get_file_value("value").content;
        bool result{ db.addDocument(collection, name, value) };
        std::cout << "CREATE on " << collection << "/" << name << " with " << value 
            << " > " << result << std::endl;
        std::string resStr = "{ 'error':'Could not create document' }";
        if (result) {
            resStr = (db.getCollectionString(collection));
        }
        res.set_content(resStr, "text/plain");
    });

    // PUT REQUEST - CREATE COLLECTION
    svr.Put("/", [&](const Request& req, Response& res) {
        if (!(req.has_file("name"))) {
            res.set_content("{'error':'PUT request must contains NAME'}", "text/plain");
            return;
        }
        const std::string name = req.get_file_value("name").content;
        bool result{ db.addCollection(name) };
        std::cout << "CREATE "<< name
            << " > " << result << std::endl;
        std::string resStr = "{ 'error':'Could not create collection' }";
        if (result) {
            resStr = (db.getCollectionString(name));
        }
        res.set_content(resStr, "text/plain");
    });


    svr.listen("localhost", 8888);
}
