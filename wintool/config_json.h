#pragma once
#include "json.hpp"
#include <fstream>
using json = nlohmann::json;
using json_error = nlohmann::json::parse_error;
using type_error = nlohmann::json::type_error;
#define REG_PARAM(filename,classname,type) class classname\
{\
public:\
classname() : cname(conver_class_name(typeid(classname).name())), fn(filename),data(type()) {\
std::ifstream is(fn + ".json");\
if(!is.is_open())\
{\
	std::ofstream os(fn + ".json");\
	j.emplace(cname,data);\
	os << j;\
}else\
{\
is >> j;\
j.emplace(cname, data);\
	data = j[cname];\
}\
}\
~classname() {\
	}\
		inline void set(const type& d) { data = d; j[cname] = data; }\
		inline type get() { return data; }\
inline void save_2_file()\
{\
	std::ifstream is(fn + ".json"); \
		is >> j; \
		is.close(); \
		try{j[cname] = data;} \
catch(type_error& e){j.emplace(cname, data);}\
		std::ofstream os(fn + ".json"); \
		os << std::setw(4) << j;\
}\
private:\
		std::string cname; \
		std::string fn; \
		type data; \
		json j;\
inline std::string conver_class_name(std::string s)\
{\
	std::string out;\
	for (auto iter = s.begin() + 6; iter < s.end(); iter++)\
	{\
		out.push_back(*iter);\
	}\
	return out;\
}\
};
