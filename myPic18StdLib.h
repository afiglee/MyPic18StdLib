/* 
 * File:   myPic18StdLib.h
 * Author: m2tx9
 *
 * Created on September 24, 2024, 5:50 PM
 */

#ifndef MYPIC18STDLIB_H
#define	MYPIC18STDLIB_H

#include <stdint.h>

#ifdef	__cplusplus
extern "C" {
#endif

#define NOT_HEX(A) ((A < '0' || A > 'f') || \
        (A > 'F' && A < 'a') || \
        (A > '9' && A < 'A'))

#define HEX2CHAR(hex,ch) if (hex >= 0x0A) {\
        ch = 'A' + (hex - 0x0A);\
    } else {\
        ch = '0' + hex;\
    }
  
    // Reads up to 2 case insensitive chars starting at p
    // and returns 8 bits value. 
    // Any non hex value will break loop and converted 
    // till then value returned
    uint8_t hex2uint8(const char* p);

    // Reads up to 4 case insensitive chars starting at p
    // and returns 16 bits value. 
    // Any non hex value will break loop and converted 
    // till then value returned
    uint16_t hex2uint16(const char* p);

    // Converts uint8_t to 2 chars hex representation (uppercase)
    // Buffer at p must have at least 2 chars available
    void uint8_2hex(const uint8_t data, char *p);
    
    // Converts uint16_t to 4 chars hex representation (uppercase)
    // Buffer at p must have at least 4 chars available
    void uint16_2hex(const uint16_t data, char *p);
    
    // Returns 0 if both chars at p represents hex value.
    // Returns 1 otherwise
    uint8_t check_hex_uint8(char *p);
    
#ifdef	__cplusplus
}
#endif

#endif	/* MYPIC18STDLIB_H */

