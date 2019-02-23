#pragma once
#include <stdint.h>

#define STRUCT_PACKED __attribute__((__packed__))

typedef struct {
    uint8_t SoT;
    uint8_t payload;
    uint8_t Eot;
} mipi_dpi_t;


typedef enum {
    
} data_type_e;

typedef struct STRUCT_PACKED {
    data_type_e data_type:6;
    uint8_t virtual_channel_indentifier:4;
} mipi_data_id_t;


typedef struct STRUCT_PACKED {
    mipi_data_id_t data_id;
    uint16_t word_count;
    uint8_t ecc;
} mipi_packet_header_t;

typedef struct STRUCT_PACKED {
    mipi_data_id_t data_id;
    uint8_t data0;
    uint8_t data1;
    uint8_t ecc;
} mipi_short_packet_t;


#define mipi_long_packet_checksum(packet) (*(int16_t*)&((packet).payload[(packet).packet_header.word_count]))
typedef struct STRUCT_PACKED {
    mipi_packet_header_t packet_header;
    /// payload size is packet_header.word_count
    uint8_t payload[];
    /// checksum is at end of packet
    // uint16_t checksum;
} mipi_long_packet_t;










