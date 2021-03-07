#include "jsoncpprest.h"

#include <cpprest/json.h>
#include <sstream>

using namespace std;
typedef web::json::value JsonValue;
typedef web::json::value::value_type JsonValueType;
typedef std::string String;
typedef std::stringstream StringStream;

String JsonValueTypeToString(const JsonValueType& type)
{
  switch (type)
    {
        case JsonValueType::Array: return "Array";
        case JsonValueType::Boolean: return "Boolean";
        case JsonValueType::Null: return "Null";
        case JsonValueType::Number: return "Number";
        case JsonValueType::Object: return "Object";
        case JsonValueType::String: return "String";
    }
}

void Externalize(const JsonValue& json)
{
    for (auto iter =  json.as_object().cbegin() ; iter != json.as_object().cend(); ++iter)
    {
        auto k = iter->first;
        auto v = iter->second;

//        auto key = k.;
        auto value = v.to_string();

//        cout << key << L" : " << value << " (" << JsonValueTypeToString(v.type()) << ")" << endl;
    }
}

void Test1_json_serialize()
{
    JsonValue json;

    json["key1"] = JsonValue::boolean(false);
    json["key2"] = JsonValue::number(44);
    json["key3"] = JsonValue::number(43.6);
    json["key4"] = JsonValue::string(U("str"));

    Externalize(json);

    json.serialize(cout);
}

void Test2_json_deserialize()
{
    StringStream ss;

    ss << U("{\"key1\":false,\"key2\":44,\"key3\":43.6,\"key4\":\"str\"}");

    JsonValue json = JsonValue::parse(ss);

    Externalize(json);

    json.serialize(cout);
}

//int main()
//{
//    cout << "Running test 1" << endl;
//    Test1_json_serialize();

//    cout << endl << "Running test 2" << endl;
//    Test2_json_deserialize();
//    return 0;
//}
