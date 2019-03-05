#pragma once
#include <stdint.h>

#define STRUCT_PACKED __attribute__((__packed__))

typedef struct STRUCT_PACKED _mipi_dpi_t {
	uint8_t SoT;
	uint8_t payload;
	uint8_t Eot;
} mipi_dpi_t;

typedef enum {
	MIPI_SYNC_V_START = 0x01,
	MIPI_SYNC_V_END = 0x11,
	MIPI_SYNC_H_START = 0x21,
    MIPI_SYNC_H_END = 0x31,
    MIPI_COMPRESSION_MODE = 0x07,
    MIPI_END_OF_TRANSMISSION_PACKET = 0x08,
    MIPI_COLOR_MODE_OFF = 0x02,
    MIPI_COLOR_MODE_ON = 0x12,
    MIPI_SHUT_DOWN_PERIPHERAL = 0x22,
    MIPI_TURN_ON_PERIPHERAL = 0x32,
    MIPI_GENERIC_SHORT_WRITE_0 = 0x03,
    MIPI_GENERIC_SHORT_WRITE_1 = 0x13,
    MIPI_GENERIC_SHORT_WRITE_2 = 0x23,
    MIPI_GENERIC_READ_0 = 0x04,
    MIPI_GENERIC_READ_1 = 0x14,
    MIPI_GENERIC_READ_2 = 0x24,
    MIPI_DISPLAY_SHORT_WRITE_0 = 0x05,
    MIPI_DISPLAY_SHORT_WRITE_1 = 0x5,
    MIPI_DISPLAY_READ = 0x06,
    MIPI_EXECUTE_QUEUE = 0x16,
    MIPI_SET_MAXIMUM_RETURN_PACKET_SIZE = 0x37,
    MIPI_NULL = 0x09,
    MIPI_BLANKING = 0x19,
} data_type_e;

typedef struct STRUCT_PACKED _mipi_data_id_t {
	data_type_e data_type : 6;
	uint8_t virtual_channel_indentifier : 2;
} mipi_data_id_t;

typedef struct STRUCT_PACKED _mipi_packet_header_t {
	mipi_data_id_t data_id;
	uint16_t word_count;
	uint8_t ecc;
} mipi_packet_header_t;

typedef struct STRUCT_PACKED _mipi_short_packet_t {
	mipi_data_id_t data_id;
	uint8_t data0;
	uint8_t data1;
	uint8_t ecc;
} mipi_short_packet_t;

#define mipi_long_packet_checksum(packet)                                      \
	(*(int16_t *)&((packet).payload[(packet).packet_header.word_count]))
typedef struct STRUCT_PACKED _mipi_long_packet_t {
	mipi_packet_header_t packet_header;
	/// payload size is packet_header.word_count
	uint8_t payload[];
	// checksum is at end of packet
	// uint16_t checksum;
} mipi_long_packet_t;
