#pragma once
#include <stdint.h>

#define STRUCT_PACKED __attribute__((__packed__))

#define MIPI_SSDC 0x888
#define MIPI_SSS 0x3444443

typedef struct STRUCT_PACKED _mipi_dpi_t {
	uint8_t SoT;
	uint8_t payload;
	uint8_t Eot;
} mipi_dpi_t;

typedef struct STRUCT_PACKED _mipi_error_report_t {
	uint8_t sot_error : 1;
	uint8_t sot_sync_error : 1;
	uint8_t eot_error : 1;
	uint8_t escape_mode_entry_command_error : 1;
	uint8_t low_power_transmit_sync_error : 1;
	uint8_t peripheral_timeout_error : 1;
	uint8_t false_control_error : 1;
	uint8_t contention_detected : 1;
	uint8_t ecc_error_single_bit : 1;
	uint8_t ecc_error_multi_bit : 1;
	uint8_t checksum_error : 1;
	uint8_t dsi_data_type_not_recognized : 1;
	uint8_t dsi_vc_id_invalid : 1;
	uint8_t invalid_transmission_length : 1;
	uint8_t reserved : 1;
	uint8_t dsi_protocol_violation : 1;
} mipi_error_report_t;

typedef enum _mipi_processor_data_type_e {
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

static const uint8_t mipi_processor_data_type_is_lang[] = {
	[MIPI_DO_NOT_USE_00] = 0,
	[MIPI_SYNC_V_START] = 0,
	[MIPI_COLOR_MODE_OFF] = 0,
	[MIPI_GENERIC_SHORT_WRITE_0] = 0,
	[MIPI_GENERIC_READ_0] = 0,
	[MIPI_DISPLAY_SHORT_WRITE_0] = 0,
	[MIPI_DISPLAY_READ] = 0,
	[MIPI_COMPRESSION_MODE] = 0,
	[MIPI_END_OF_TRANSMISSION_PACKET] = 0,
	[MIPI_NULL] = 1,
	[MIPI_PICTURE_PARAMETER_SET] = 1,
	[MIPI_COMPRESSED_PIXEL_STREAM] = 1,
	[MIPI_LOOSELY_PACKED_PIXEL_STREAM_20_BIT_YCBCR_4_2_2] = 1,
	[MIPI_PACKED_PIXEL_STREAM_30_BIT_RGB_10_10_10] = 1,
	[MIPI_PACKED_PIXEL_STREAM_16_BIT_RGB_5_6_5] = 1,
	[MIPI_DO_NOT_USE_0F] = 0,
	[MIPI_DO_NOT_USE_10] = 0,
	[MIPI_SYNC_V_END] = 0,
	[MIPI_COLOR_MODE_ON] = 0,
	[MIPI_GENERIC_SHORT_WRITE_1] = 0,
	[MIPI_GENERIC_READ_1] = 0,
	[MIPI_DISPLAY_SHORT_WRITE_1] = 0,
	[MIPI_EXECUTE_QUEUE] = 0,
	[23] = 0xff,
	[24] = 0xff,
	[MIPI_BLANKING] = 1,
	[26] = 0xff,
	[27] = 0xff,
	[MIPI_PACKED_PIXEL_STREAM_24_BIT_YCVCR_4_2_2] = 1,
	[MIPI_PACKED_PIXEL_STREAM_36_BIT_RGB_12_12_12] = 1,
	[MIPI_PACKED_PIXEL_STREAM_18_BIT_RGB_6_6_6] = 1,
	[MIPI_DO_NOT_USE_1F] = 0,
	[MIPI_DO_NOT_USE_20] = 0,
	[MIPI_SYNC_H_START] = 0,
	[MIPI_SHUT_DOWN_PERIPHERAL] = 0,
	[MIPI_GENERIC_SHORT_WRITE_2] = 0,
	[MIPI_GENERIC_READ_2] = 0,
	[37] = 0xff,
	[38] = 0xff,
	[39] = 0xff,
	[40] = 0xff,
	[MIPI_GENERIC_LONG_WRITE] = 1,
	[42] = 0xff,
	[43] = 0xff,
	[MIPI_PACKED_PIXEL_STREAM_16_BIT_YCVCR_4_2_2] = 1,
	[45] = 0xff,
	[MIPI_LOOSELY_PACKED_PIXEL_STREAM_18_BIT_RGB_6_6_6] = 1,
	[MIPI_DO_NOT_USE_2F] = 0,
	[MIPI_DO_NOT_USE_30] = 0,
	[MIPI_SYNC_H_END] = 0,
	[MIPI_TURN_ON_PERIPHERAL] = 0,
	[51] = 0xff,
	[52] = 0xff,
	[53] = 0xff,
	[54] = 0xff,
	[MIPI_SET_MAXIMUM_RETURN_PACKET_SIZE] = 0,
	[56] = 0xff,
	[MIPI_DISPLAY_LONG_WRITE] = 1,
	[58] = 0xff,
	[59] = 0xff,
	[60] = 0xff,
	[MIPI_PACKED_PIXEL_STREAM_12_BIT_YCVCR_4_2_0] = 1,
	[MIPI_PACKED_PIXEL_STREAM_24_BIT_RGB_8_8_8] = 1,
	[MIPI_DO_NOT_USE_3F] = 0,
};

typedef enum _mipi_peripheral_data_type_e {
	MIPI_PERIPHERAL_ACKNOWLEDGE_AND_ERROR_REPORT = 0x02,
	MIPI_PERIPHERAL_END_OF_TRANSMISSION_PACKET = 0x08,
	MIPI_PERIPHERAL_GENERIC_SHORT_READ_RESPONSE_1 = 0x11,
	MIPI_PERIPHERAL_GENERIC_SHORT_READ_RESPONSE_2 = 0x12,
	MIPI_PERIPHERAL_GENERIC_LONG_READ_RESPONSE = 0x1a,
	MIPI_PERIPHERAL_DISPLAY_LONG_READ_RESPONSE = 0x1c,
	MIPI_PERIPHERAL_DISPLAY_SHORT_READ_RESPONSE_1 = 0x21,
	MIPI_PERIPHERAL_DISPLAY_SHORT_READ_RESPONSE_2 = 0x22
} data_type_e;

static const uint8_t mipi_peripheral_data_type_is_lang[1 << 6] = {
	[0x00] = 0xff,
	[0x01] = 0xff,
	[MIPI_PERIPHERAL_ACKNOWLEDGE_AND_ERROR_REPORT] = 0,
	[0x03] = 0xff,
	[0x04] = 0xff,
	[0x05] = 0xff,
	[0x06] = 0xff,
	[0x07] = 0xff,
	[MIPI_PERIPHERAL_END_OF_TRANSMISSION_PACKET] = 0,
	[0x09] = 0xff,
	[0x0a] = 0xff,
	[0x0b] = 0xff,
	[0x0c] = 0xff,
	[0x0d] = 0xff,
	[0x0e] = 0xff,
	[0x0f] = 0xff,
	[0x10] = 0xff,
	[MIPI_PERIPHERAL_GENERIC_SHORT_READ_RESPONSE_1] = 0,
	[MIPI_PERIPHERAL_GENERIC_SHORT_READ_RESPONSE_2] = 0,
	[0x13] = 0xff,
	[0x14] = 0xff,
	[0x15] = 0xff,
	[0x16] = 0xff,
	[0x17] = 0xff,
	[0x18] = 0xff,
	[0x19] = 0xff,
	[MIPI_PERIPHERAL_GENERIC_LONG_READ_RESPONSE] = 1,
	[0x1b] = 0xff,
	[MIPI_PERIPHERAL_DISPLAY_LONG_READ_RESPONSE] = 1,
	[0x1d] = 0xff,
	[0x1e] = 0xff,
	[0x1f] = 0xff,
	[0x20] = 0xff,
	[MIPI_PERIPHERAL_DISPLAY_SHORT_READ_RESPONSE_1] = 0,
	[MIPI_PERIPHERAL_DISPLAY_SHORT_READ_RESPONSE_2] = 0,
	[0x23] = 0xff,
	[0x24] = 0xff,
	[0x25] = 0xff,
	[0x26] = 0xff,
	[0x27] = 0xff,
	[0x28] = 0xff,
	[0x29] = 0xff,
	[0x2a] = 0xff,
	[0x2b] = 0xff,
	[0x2c] = 0xff,
	[0x2d] = 0xff,
	[0x2e] = 0xff,
	[0x2f] = 0xff,
	[0x30] = 0xff,
	[0x31] = 0xff,
	[0x32] = 0xff,
	[0x33] = 0xff,
	[0x34] = 0xff,
	[0x35] = 0xff,
	[0x36] = 0xff,
	[0x37] = 0xff,
	[0x38] = 0xff,
	[0x39] = 0xff,
	[0x3a] = 0xff,
	[0x3b] = 0xff,
	[0x3c] = 0xff,
	[0x3d] = 0xff,
	[0x3e] = 0xff,
	[0x3f] = 0xff,
};

typedef struct STRUCT_PACKED _mipi_3d_control_payload_t {
	uint8_t _3d_mode_on : 2;
	uint8_t _3d_image_format : 2;
	uint8_t _3d_vsync : 1;
	uint8_t _3d_l_r_order : 1;
	uint8_t zeros : 2;
} mipi_3d_control_payload_t;

typedef struct STRUCT_PACKED _mipi_compression_mode_parameters_t {
	uint8_t compression_enabled : 1;
	/// + 00 = VESA DSC Standard 1.0
	/// + 11 = vendor-specific algorithm
	/// + 01, 10 = reserved, not used
	uint8_t algorithm_identifier : 2;
	uint8_t reserved : 3;
	uint8_t pps_selector : 2;
	uint8_t zeros1 : 2;
	uint8_t zeros2;
} mipi_compression_mode_parameters_t;

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
