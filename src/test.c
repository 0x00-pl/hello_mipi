#include <stdint.h>



typedef struct _trans_block_16_t {
    uint16_t line0[4];
    uint16_t line1[4];
    uint16_t line2[4];
    uint16_t line3[4];
} transs_block_16_t;

#define AS_UINT64(addr) (*(uint64_t*)(addr))

static inline void swap16(uint16_t& a, uint16_t& b){
    uint16_t t = a;
    a = b;
    b = t;
} 

void transpose_block_16(uint64_t* src, uint64_t* dst, uint32_t src_w, uint32_t dst_w){
    transs_block_16_t tmp;
    AS_UINT64(&tmp.line0) = src[0];
    AS_UINT64(&tmp.line1) = src[src_w/4];
    AS_UINT64(&tmp.line2) = src[2*src_w/4];
    AS_UINT64(&tmp.line3) = src[3*src_w/4];
    
    swap16(tmp.line0[1], tmp.line1[0]);
    swap16(tmp.line2[3], tmp.line3[2]);
    swap16(tmp.line0[2], tmp.line2[0]);
    swap16(tmp.line1[3], tmp.line3[1]);
    swap16(tmp.line0[3], tmp.line3[0]);
    swap16(tmp.line1[2], tmp.line2[1]);
    
    dst[0] = AS_UINT64(&tmp.line0);
    dst[dst_w/4] = AS_UINT64(&tmp.line1);
    dst[2*dst_w/4] = AS_UINT64(&tmp.line2);
    dst[3*dst_w/4] = AS_UINT64(&tmp.line3);
}
