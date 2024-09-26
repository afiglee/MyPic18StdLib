
#include "myPic18StdLib.h"


uint8_t hex2uint8(const char* p)
{
    uint8_t val = 0;
    uint8_t steps = 2;
    while(steps--) {
        if (NOT_HEX(*p)) {
            break;
        }
        val <<= 4;
        if (*p <= '9') {
            val |= *p - '0';
        } else {
            val |= 0xA + ((*p & 0x5F)- 'A'); 
        }
        p++;
    }
    return val;
}

uint16_t hex2uint16(const char* p)
{
    uint16_t val = 0;
    uint8_t steps = 4;
    while(steps--) {
        if (NOT_HEX(*p)) {
            break;
        }
        val <<= 4;
        if (*p <= '9') {
            val |= *p - '0';
        } else {
            val |= 0xA + ((*p & 0x5F)- 'A'); 
        }
        p++;
    }
    return val;
}

void uint8_2hex(const uint8_t data, char *p)
{
    
    uint8_t hex = data >> 4;
    HEX2CHAR(hex,*p);
    hex = data & 0x0F;
    HEX2CHAR(hex,*(p+1));
}

void uint16_2hex(const uint16_t data, char *p)
{
    
    uint8_t hex = data >> 12;
    HEX2CHAR(hex,*p++);
    hex = (data >> 8) & 0x0F;
    HEX2CHAR(hex,*p++);
    hex = (data >> 4) & 0x0F;
    HEX2CHAR(hex,*p++);
    hex = data & 0x0F;
    HEX2CHAR(hex,*(p));
}

uint8_t check_hex_uint8(char *p) {
    if (NOT_HEX(*p) || (NOT_HEX(*(p+1)))) {
        return 0;
    }
    return 1;
}