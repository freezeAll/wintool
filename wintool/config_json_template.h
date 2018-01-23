#pragma once
#include "json.hpp"
#include <fstream>
#include <mutex>
using json = nlohmann::json;
using json_error = nlohmann::json::parse_error;
using type_error = nlohmann::json::type_error;
//static std::mutex* json_mutex = new std::mutex();

template<typename T>
class JsonParam
{
public:
	JsonParam(const std::string& cn,const std::string& fn):
		file_name(fn),
		cname(cn),
		data(T())
	{
		
		std::ifstream is(file_name + ".json");
		if (!is.is_open())
		{
			std::ofstream os(file_name + ".json");
			j.emplace(cname, data); 
			os << j;
		}
		else
		{
			is >> j;
			j.emplace(cname, data);
			data = j[cname];
		}
	};
	~JsonParam()
	{
	
	};

	inline void set(const T& s)
	{
		data = d;
		j[cname] = data;
	}

	inline T get()
	{
		return data;
	}

	inline void save_2_file()
	{
		std::ifstream is(file_name + ".json");
		is >> j;
		is.close();
		try { j[cname] = data; } 
		catch (type_error& e) { j.emplace(cname, data); }
		std::ofstream os(file_name + ".json");
		os << std::setw(4) << j;
	}
private:
	std::string file_name;
	std::string cname;
	T data;
	json j;
};

