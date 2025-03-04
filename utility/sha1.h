/* sha1.h

Copyright (c) 2005 Michael D. Leonhard

http://tamale.net/

This file is licensed under the terms described in the
accompanying LICENSE file.
*/

#ifndef SHA1_HEADER
typedef unsigned int Uint32;

#include <string.h>
#include <string>

using namespace std;

class SHA1
{
	private:
		// fields
		Uint32 H0, H1, H2, H3, H4;
		unsigned char bytes[64];
		int unprocessedBytes;
		Uint32 size;
		void process();
	public:
		SHA1();
		~SHA1();
		void addBytes( const char* data, int num );
		unsigned char* getDigest();
		// utility methods
		static Uint32 lrot( Uint32 x, int bits );
		static void storeBigEndianUint32( unsigned char* byte, Uint32 num);
		static char *hexPrinter( unsigned char* c, int l );
		static unsigned int shaToInteger( unsigned char* c, int l, unsigned int spacesize );
		unsigned int getIntSHA1(string s);
};

#define SHA1_HEADER
#endif
