#include <iostream>
#include "mipi.h"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	mipi_long_packet_t lp;
	mipi_long_packet_checksum(lp) = 10;

	std::cout << "Hello, world!" << sizeof(mipi_long_packet_t)
		  << mipi_long_packet_checksum(lp) << lp.payload[0]
		  << std::endl;
	return 0;
}
