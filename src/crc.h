#pragma once

static unsigned short gsCRC16GenerationCode = 0x8408;
unsigned short CalculateCRC16(unsigned char *pcDataStream,
			      unsigned short sNumberOfDataBytes);
