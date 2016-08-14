#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <map>
#include <string>

/*
std::map<std::string, int> cores_per_compute_unit= {
	{"GeForce GTX 1080", 128},
	{"GeForce GTX 590", 32},
	{"GeForce GT 730", 192},
	{"Tesla K40c", 192},
	{"Tesla K20c", 192}
};
*/

std::map<std::string, int> cores_per_compute_unit;
std::map<std::string, int>::iterator it;



int main(int argc, char **argv) {
	cores_per_compute_unit["GeForce GTX 1080"] = 128;
	cores_per_compute_unit["GeForce GTX 590"]  = 32;
	cores_per_compute_unit["GeForce GT 730"]   = 192;
	cores_per_compute_unit["Tesla K40c"]       = 192;
	cores_per_compute_unit["Tesla K20c"]       = 192;


	char pbuf[100]="GeForce GT 730";	
	//char pbuf[100]="GeForce GT 7";	

	it = cores_per_compute_unit.find(pbuf);

	if(it != cores_per_compute_unit.end())
	{
		std::cout << "device "<<  it->first << " : " << it->second << std::endl;	
	}
	else 
	{
		std::cerr << "unknow device" << std::endl;	
		exit(1);
	}



	//	std::pair<int, int> node6(12,12);
	//	if (NS.find(node6) != NS.end())
	//		std::cout << "found (" << node6.first << "," << node6.second << ")\n";
	//	else
	//		std::cout << "not found (" << node6.first << "," << node6.second << ")\n";

	return 0;
}
