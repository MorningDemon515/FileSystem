#include <inicpp.hpp> //https://github.com/dujingning/inicpp
#include <json\json.h> //https://github.com/open-source-parsers/jsoncpp

#include "FileSys.h"

#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
#include <sstream>
#include <memory>

#ifdef __cplusplus
extern "C" {
#endif

int GetINIint(const char* file, const char* section, const char* key)
{
    inicpp::IniManager f(file);
    std::string str = f[section][key];

    const char* cstr = str.c_str();
    return atoi(cstr);

}

float GetINIfloat(const char* file, const char* section, const char* key)
{
    inicpp::IniManager f(file);
    std::string str = f[section][key];

    const char* cstr = str.c_str();

    return atof(cstr);
}

const char* GetINIstring(const char* file, const char* section, const char* key)
{
    inicpp::IniManager f(file);
    std::string str = f[section][key];

    return str.c_str();
}

void WriteINIint(const char* file, const char* section, const char* key, int value)
{
    inicpp::IniManager f(file);
    f.modify(section,key,value);
}

void WriteINIfloat(const char* file, const char* section, const char* key, float value)
{
    inicpp::IniManager f(file);
    f.modify(section,key,value);
}

void WriteINIstring(const char* file, const char* section, const char* key, const char* value)
{
    inicpp::IniManager f(file);
    f.modify(section,key,value);
}

int GetJSONint(const char* file, const char* key)
{
    std::ifstream f(file, std::ifstream::binary);

    Json::CharReaderBuilder readerBuilder;
    Json::Value root;
    std::string errs;

    if (!Json::parseFromStream(readerBuilder, f, &root, &errs)) {
        std::cerr << "Failed to parse JSON: " << errs << std::endl;
        return 0; // return an empty string on error
    }

    std::string str = root[key].asString();

    const char* cstr = str.c_str();
    return atoi(cstr);
}

float GetJSONfloat(const char* file, const char* key)
{
    std::ifstream f(file, std::ifstream::binary);

    Json::CharReaderBuilder readerBuilder;
    Json::Value root;
    std::string errs;

    if (!Json::parseFromStream(readerBuilder, f, &root, &errs)) {
        std::cerr << "Failed to parse JSON: " << errs << std::endl;
        return 0.0f; // return an empty string on error
    }

    std::string str = root[key].asString();
    const char* cstr = str.c_str();

    return atof(cstr);
}

const char* GetJSONstring(const char* file, const char* key)
{
    std::ifstream f(file, std::ifstream::binary);

    Json::CharReaderBuilder readerBuilder;
    Json::Value root;
    std::string errs;

    if (!Json::parseFromStream(readerBuilder, f, &root, &errs)) {
        std::cerr << "Failed to parse JSON: " << errs << std::endl;
        return " "; // return an empty string on error
    }

    std::string str = root[key].asString();

    char* result = new char[str.size() + 1];
    std::strcpy(result, str.c_str());

    return result;

    delete[] str.c_str();
}

void WriteJSONint(const char* file, const char* key, int value)
{
    if (!file || !key || !value) {
        std::cerr << "Invalid arguments" << std::endl;
        return;
    }

    Json::Value root;
    std::ifstream ifs(file, std::ifstream::binary);
    if (ifs.is_open()) {
        Json::CharReaderBuilder readerBuilder;
        std::string errs;
        Json::parseFromStream(readerBuilder, ifs, &root, &errs);
    }
    ifs.close();

    root[key] = value;

    Json::StreamWriterBuilder writer;
    std::ofstream f(file, std::ofstream::binary);
    if (!f.is_open()) {
        std::cerr << "Failed to open file: " << file << std::endl;
        return;
    }

    f << Json::writeString(writer, root);

}
void WriteJSONfloat(const char* file, const char* key, float value)
{
    if (!file || !key || !value) {
        std::cerr << "Invalid arguments" << std::endl;
        return;
    }

    Json::Value root;
    std::ifstream ifs(file, std::ifstream::binary);
    if (ifs.is_open()) {
        Json::CharReaderBuilder readerBuilder;
        std::string errs;
        Json::parseFromStream(readerBuilder, ifs, &root, &errs);
    }
    ifs.close();

    root[key] = value;

    Json::StreamWriterBuilder writer;
    std::ofstream f(file, std::ofstream::binary);
    if (!f.is_open()) {
        std::cerr << "Failed to open file: " << file << std::endl;
        return;
    }

    f << Json::writeString(writer, root);
}

void WriteJSONstring(const char* file, const char* key, const char* value)
{
   if (!file || !key || !value) {
        std::cerr << "Invalid arguments" << std::endl;
        return;
    }

    Json::Value root;
    std::ifstream ifs(file, std::ifstream::binary);
    if (ifs.is_open()) {
        Json::CharReaderBuilder readerBuilder;
        std::string errs;
        Json::parseFromStream(readerBuilder, ifs, &root, &errs);
    }
    ifs.close();

    root[key] = value;

    Json::StreamWriterBuilder writer;
    std::ofstream f(file, std::ofstream::binary);
    if (!f.is_open()) {
        std::cerr << "Failed to open file: " << file << std::endl;
        return;
    }

    f << Json::writeString(writer, root);
}

#ifdef __cplusplus
}
#endif