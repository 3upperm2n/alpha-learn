#include <iostream>
#include <set>

int main(int argc, char **argv) {

	std::pair<int, int> node1;
	std::cout << node1.first << ", " << node1.second << std::endl;


	std::pair<int, int> node2(1, 10);
	std::cout << node2.first << ", " << node2.second << std::endl;

	std::pair<int, int> node3(1, 10);
	std::cout << node3.first << ", " << node3.second << std::endl;

	std::pair<int, int> node4(2, 10);
	std::cout << node4.first << ", " << node4.second << std::endl;

	std::pair<int, int> node5(1, 11);
	std::cout << node5.first << ", " << node5.second << std::endl;

	
	std::set<std::pair<int, int> > NS;
	std::cout << "set size : " << NS.size() << std::endl;

	NS.insert(node2);
	std::cout << "set size : " << NS.size() << std::endl;

	NS.insert(node3);
	std::cout << "set size : " << NS.size() << std::endl;

	NS.insert(node4);
	std::cout << "set size : " << NS.size() << std::endl;

	NS.insert(node5);
	std::cout << "set size : " << NS.size() << std::endl;

	if (NS.find(node3) != NS.end())
		std::cout << "found (" << node3.first << "," << node3.second << ")\n";

	if (NS.find(node5) != NS.end())
		std::cout << "found (" << node5.first << "," << node5.second << ")\n";

	std::pair<int, int> node6(12,12);
	if (NS.find(node6) != NS.end())
		std::cout << "found (" << node6.first << "," << node6.second << ")\n";
	else
		std::cout << "not found (" << node6.first << "," << node6.second << ")\n";

	return 0;
}
