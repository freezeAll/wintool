#pragma once



#pragma comment (lib,"psapi")


#ifdef _DEBUG

#pragma comment (lib,"boost_regex-vc140-mt-gd-1_65")
#pragma comment (lib,"boost_filesystem-vc140-mt-gd-1_65")

#else

#pragma comment (lib,"boost_regex-vc140-mt-1_65")
#pragma comment (lib,"boost_filesystem-vc140-gd-1_65")
#endif

#include <fstream>
#include <string>

#include <boost/filesystem.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/sources/severity_channel_logger.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/from_stream.hpp>
#include <boost/log/utility/setup/formatter_parser.hpp>
#include <boost/log/utility/setup/filter_parser.hpp>
#include <boost/log/core.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <memory>


namespace wintool
{
	
	namespace logging = boost::log;
	namespace tri = logging::trivial;
	namespace src = boost::log::sources;
	namespace kws = logging::keywords;
	typedef src::severity_channel_logger<tri::severity_level> Logger;
	bool init_log_environment(std::string _cfg)
	{


		if (!boost::filesystem::exists("./logs/"))
		{
			boost::filesystem::create_directory("./logs/");
		}
		logging::add_common_attributes(
		
		
		);

		logging::register_simple_formatter_factory<tri::severity_level, char>("Severity");
		logging::register_simple_filter_factory<tri::severity_level, char>("Severity");
		
		
		
		std::ifstream file(_cfg);
		try
		{
			logging::init_from_stream(file);
		}
		catch (const std::exception& e)
		{
			std::cout << "init_logger is fail, read log config file fail. curse: " << e.what() << std::endl;
			exit(-2);
		}
		auto b_core = logging::core::get();
		
		
		

		return true;
	}

}

#define OUT_LOG(logger,level) BOOST_LOG_SEV(logger,level) << "[" << __FUNCTION__<<":"<< __LINE__ << "]\t"

#define ADD_LOGGER(name,cl) wintool::Logger (name)(wintool::kws::channel = (cl))