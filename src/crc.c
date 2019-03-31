#include "crc.h"

unsigned short CalculateCRC16(unsigned char *pcDataStream,
			      unsigned short sNumberOfDataBytes)
{
	/*
     s CRC16Result: the return of* this function,
     sByteCounter: address pointer to count the number of the
     calculated data bytes
     cBitCounter: counter for bit shift (0 to 7)
     cCurrentData: byte size buffer to duplicate the calculated data
     byte for a bit shift operation
     */
	unsigned short sByteCounter;
	unsigned char cBitCounter;
	unsigned char cCurrentData;
	unsigned short sCRC16Result = 0xFFFF;
	if (sNumberOfDataBytes > 0) {
		for (sByteCounter = 0; sByteCounter < sNumberOfDataBytes;
		     sByteCounter++) {
			cCurrentData = *(pcDataStream + sByteCounter);
			for (cBitCounter = 0; cBitCounter < 8; cBitCounter++) {
				if (((sCRC16Result & 0x0001) ^
				     ((0x0001 * cCurrentData) & 0x0001)) > 0)
					sCRC16Result =
						((sCRC16Result >> 1) & 0x7FFF) ^
						gsCRC16GenerationCode;
				else
					sCRC16Result =
						(sCRC16Result >> 1) & 0x7FFF;
				cCurrentData = (cCurrentData >> 1) & 0x7F;
			}
		}
	}
	return sCRC16Result;
}
