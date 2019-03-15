#pragma once
#include <stdint.h>

#define STRUCT_PACKED __attribute__((__packed__))

typedef struct STRUCT_PACKED _mipi_dpi_t {
	uint8_t SoT;
	uint8_t payload;
	uint8_t Eot;
} mipi_dpi_t;

typedef struct STRUCT_PACKED _mipi_error_report_t {
    uint8_t sot_error:1;
    uint8_t sot_sync_error:1;
    uint8_t eot_error:1;
    uint8_t escape_mode_entry_command_error:1;
    uint8_t low_power_transmit_sync_error:1;
    uint8_t peripheral_timeout_error:1;
    uint8_t false_control_error:1;
    uint8_t contention_detected:1;
    uint8_t ecc_error_single_bit:1;
    uint8_t ecc_error_multi_bit:1;
    uint8_t checksum_error:1;
    uint8_t dsi_data_type_not_recognized:1;
    uint8_t dsi_vc_id_invalid:1;
    uint8_t invalid_transmission_length:1;
    uint8_t reserved:1;
    uint8_t dsi_protocol_violation:1;
} mipi_error_report_t;

typedef enum _mipi_processor_data_type_e{
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
	MIPI_DISPLAY_SHORT_WRITE_1 = 0x15,
	MIPI_DISPLAY_READ = 0x06,
	MIPI_EXECUTE_QUEUE = 0x16,
	MIPI_SET_MAXIMUM_RETURN_PACKET_SIZE = 0x37,
	MIPI_NULL = 0x09,
	MIPI_BLANKING = 0x19,
	MIPI_GENERIC_LONG_WRITE = 0x29,
	MIPI_DISPLAY_LONG_WRITE = 0x39,
	MIPI_PICTURE_PARAMETER_SET = 0x0a,
	MIPI_COMPRESSED_PIXEL_STREAM = 0x0b,
	MIPI_LOOSELY_PACKED_PIXEL_STREAM_20_BIT_YCBCR_4_2_2 = 0x0c,
	MIPI_PACKED_PIXEL_STREAM_24_BIT_YCVCR_4_2_2 = 0x1c,
	MIPI_PACKED_PIXEL_STREAM_16_BIT_YCVCR_4_2_2 = 0x2c,
	MIPI_PACKED_PIXEL_STREAM_30_BIT_RGB_10_10_10 = 0x0d,
	MIPI_PACKED_PIXEL_STREAM_36_BIT_RGB_12_12_12 = 0x1d,
	MIPI_PACKED_PIXEL_STREAM_12_BIT_YCVCR_4_2_0 = 0x3d,
	MIPI_PACKED_PIXEL_STREAM_16_BIT_RGB_5_6_5 = 0x0e,
	MIPI_PACKED_PIXEL_STREAM_18_BIT_RGB_6_6_6 = 0x1e,
	MIPI_LOOSELY_PACKED_PIXEL_STREAM_18_BIT_RGB_6_6_6 = 0x2e,
	MIPI_PACKED_PIXEL_STREAM_24_BIT_RGB_8_8_8 = 0x3e,
	MIPI_DO_NOT_USE_00 = 0x00,
	MIPI_DO_NOT_USE_10 = 0x10,
	MIPI_DO_NOT_USE_20 = 0x20,
	MIPI_DO_NOT_USE_30 = 0x30,
	MIPI_DO_NOT_USE_0F = 0x0f,
	MIPI_DO_NOT_USE_1F = 0x1f,
	MIPI_DO_NOT_USE_2F = 0x2f,
	MIPI_DO_NOT_USE_3F = 0x3f,
} mipi_processor_data_type_e;

static const char mipi_processor_data_type_is_lang[] = {
    [MIPI_SYNC_V_START] = 0,
    [MIPI_SYNC_V_END] = 0,
    [MIPI_SYNC_H_START] = 0,
    [MIPI_SYNC_H_END] = 0,
    [MIPI_COMPRESSION_MODE] = 0,
    [MIPI_END_OF_TRANSMISSION_PACKET] = 0,
    [MIPI_COLOR_MODE_OFF] = 0,
    [MIPI_COLOR_MODE_ON] = 0,
    [MIPI_SHUT_DOWN_PERIPHERAL] = 0,
    [MIPI_TURN_ON_PERIPHERAL] = 0,
    [MIPI_GENERIC_SHORT_WRITE_0] = 0,
    [MIPI_GENERIC_SHORT_WRITE_1] = 0,
    [MIPI_GENERIC_SHORT_WRITE_2] = 0,
    [MIPI_GENERIC_READ_0] = 0,
    [MIPI_GENERIC_READ_1] = 0,
    [MIPI_GENERIC_READ_2] = 0,
    [MIPI_DISPLAY_SHORT_WRITE_0] = 0,
    [MIPI_DISPLAY_SHORT_WRITE_1] = 0,
    [MIPI_DISPLAY_READ] = 0,
    [MIPI_EXECUTE_QUEUE] = 0,
    [MIPI_SET_MAXIMUM_RETURN_PACKET_SIZE] = 0,
    [MIPI_NULL] = 1,
    [MIPI_BLANKING] = 1,
    [MIPI_GENERIC_LONG_WRITE] = 1,
    [MIPI_DISPLAY_LONG_WRITE] = 1,
    [MIPI_PICTURE_PARAMETER_SET] = 1,
    [MIPI_COMPRESSED_PIXEL_STREAM] = 1,
    [MIPI_LOOSELY_PACKED_PIXEL_STREAM_20_BIT_YCBCR_4_2_2] = 1,
    [MIPI_PACKED_PIXEL_STREAM_24_BIT_YCVCR_4_2_2] = 1,
    [MIPI_PACKED_PIXEL_STREAM_16_BIT_YCVCR_4_2_2] = 1,
    [MIPI_PACKED_PIXEL_STREAM_30_BIT_RGB_10_10_10] = 1,
    [MIPI_PACKED_PIXEL_STREAM_36_BIT_RGB_12_12_12] = 1,
    [MIPI_PACKED_PIXEL_STREAM_12_BIT_YCVCR_4_2_0] = 1,
    [MIPI_PACKED_PIXEL_STREAM_16_BIT_RGB_5_6_5] = 1,
    [MIPI_PACKED_PIXEL_STREAM_18_BIT_RGB_6_6_6] = 1,
    [MIPI_LOOSELY_PACKED_PIXEL_STREAM_18_BIT_RGB_6_6_6] = 1,
    [MIPI_PACKED_PIXEL_STREAM_24_BIT_RGB_8_8_8] = 1,
    [MIPI_DO_NOT_USE_00] = 0,
    [MIPI_DO_NOT_USE_10] = 0,
    [MIPI_DO_NOT_USE_20] = 0,
    [MIPI_DO_NOT_USE_30] = 0,
    [MIPI_DO_NOT_USE_0F] = 0,
    [MIPI_DO_NOT_USE_1F] = 0,
    [MIPI_DO_NOT_USE_2F] = 0,
    [MIPI_DO_NOT_USE_3F] = 0,
};

typedef enum _mipi_peripheral_data_type_e{
    MIPI_PERIPHERAL_ACKNOWLEDGE_AND_ERROR_REPORT = 0x02,
    MIPI_PERIPHERAL_END_OF_TRANSMISSION_PACKET = 0x08,
    MIPI_PERIPHERAL_GENERIC_SHORT_READ_RESPONSE_1 = 0x11,
    MIPI_PERIPHERAL_GENERIC_SHORT_READ_RESPONSE_2 = 0x12,
    MIPI_PERIPHERAL_GENERIC_long_READ_RESPONSE = 0x1a,
    MIPI_PERIPHERAL_DISPLAY_LONG_READ_RESPONSE = 0x1c,
    MIPI_PERIPHERAL_DISPLAY_SHORT_READ_RESPONSE_1 = 0x21,
    MIPI_PERIPHERAL_DISPLAY_SHORT_READ_RESPONSE_2 = 0x22
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
