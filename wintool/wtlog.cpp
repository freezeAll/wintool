
//#include "wtlog.h"
//ADD_LOGGER(main_logger, "TEST");
#include "config_json.h"
#include <fstream>
#include <iostream>
#include <map>
REG_PARAM("test", paramtest,std::vector<int>)
REG_PARAM("test", pppp,int)
REG_PARAM("app", ssl, int)
int main()
{
	ssl s;
	paramtest pt;
	pppp p;
	json j;

	std::cout << s.get() << std::endl;
	std::cout << pt.get()[0] << std::endl;
	std::cout << p.get() << std::endl;

	s.set(5154);
	p.set(231222);
	pt.set({ 231231 });


	s.save_2_file();
	pt.save_2_file();
	p.save_2_file();
	
	
	//std::cout << s.get() << std::endl;
	//std::cout << p.get() << std::endl;
	//std::cout << pt.get() << std::endl;

	//std::setw
    return 0;
}

