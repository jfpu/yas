
// Copyright (c) 2010-2014 niXman (i dot nixman dog gmail dot com). All
// rights reserved.
//
// This file is part of YAS(https://github.com/niXman/yas) project.
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
//
//
// Boost Software License - Version 1.0 - August 17th, 2003
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
//
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

#ifndef _yas__default_traits_hpp
#define _yas__default_traits_hpp

#include <yas/detail/config/config.hpp>

#include <cmath>

namespace yas {
namespace detail {

/***************************************************************************/

struct default_traits {
	template<typename T>
	static void atou(T &v, const char *str, std::size_t size);
	template<typename T>
	static void atoi(T &v, const char *str, std::size_t size);

	template<typename T>
	static void utoa(char *buf, const std::size_t bufsize, std::size_t &len, T v);
	template<typename T>
	static void itoa(char *buf, const std::size_t bufsize, std::size_t &len, T v);

	template<typename T>
	static void atof(T &v, const char *str, std::size_t size);
	template<typename T>
	static void atod(T &v, const char *str, std::size_t size);

	template<typename T>
	static void ftoa(char *buf, const std::size_t bufsize, std::size_t &len, T v);
	template<typename T>
	static void dtoa(char *buf, const std::size_t bufsize, std::size_t &len, T v);
}; // struct default_traits

/***************************************************************************/

template<typename T>
void default_traits::atou(T &v, const char *str, std::size_t size) {
	v = 0;
	switch ( size ) {
		case 20:	v += (str[size-20] - '0') * 10000000000000000000ull;
		case 19:	v += (str[size-19] - '0') * 1000000000000000000ull;
		case 18:	v += (str[size-18] - '0') * 100000000000000000ull;
		case 17:	v += (str[size-17] - '0') * 10000000000000000ull;
		case 16:	v += (str[size-16] - '0') * 1000000000000000ull;
		case 15:	v += (str[size-15] - '0') * 100000000000000ull;
		case 14:	v += (str[size-14] - '0') * 10000000000000ull;
		case 13:	v += (str[size-13] - '0') * 1000000000000ull;
		case 12:	v += (str[size-12] - '0') * 100000000000ull;
		case 11:	v += (str[size-11] - '0') * 10000000000ull;
		case 10:	v += (str[size-10] - '0') * 1000000000ull;
		case  9:	v += (str[size- 9] - '0') * 100000000ull;
		case  8:	v += (str[size- 8] - '0') * 10000000ull;
		case  7:	v += (str[size- 7] - '0') * 1000000ull;
		case  6:	v += (str[size- 6] - '0') * 100000ull;
		case  5:	v += (str[size- 5] - '0') * 10000ull;
		case  4:	v += (str[size- 4] - '0') * 1000ull;
		case  3:	v += (str[size- 3] - '0') * 100ull;
		case  2:	v += (str[size- 2] - '0') * 10ull;
		case  1:	v += (str[size- 1] - '0') * 1ull;
	}
}
template<typename T>
void default_traits::atoi(T &v, const char *str, std::size_t size) {
	v = 0;
	T sign = 1;
	if ( *str == '-' ) {
		sign = -1;
		++str;
		--size;
	}

	switch ( size ) {
		case 19:	v += (str[size-19] - '0') * 1000000000000000000ll;
		case 18:	v += (str[size-18] - '0') * 100000000000000000ll;
		case 17:	v += (str[size-17] - '0') * 10000000000000000ll;
		case 16:	v += (str[size-16] - '0') * 1000000000000000ll;
		case 15:	v += (str[size-15] - '0') * 100000000000000ll;
		case 14:	v += (str[size-14] - '0') * 10000000000000ll;
		case 13:	v += (str[size-13] - '0') * 1000000000000ll;
		case 12:	v += (str[size-12] - '0') * 100000000000ll;
		case 11:	v += (str[size-11] - '0') * 10000000000ll;
		case 10:	v += (str[size-10] - '0') * 1000000000ll;
		case  9:	v += (str[size- 9] - '0') * 100000000ll;
		case  8:	v += (str[size- 8] - '0') * 10000000ll;
		case  7:	v += (str[size- 7] - '0') * 1000000ll;
		case  6:	v += (str[size- 6] - '0') * 100000ll;
		case  5:	v += (str[size- 5] - '0') * 10000ll;
		case  4:	v += (str[size- 4] - '0') * 1000ll;
		case  3:	v += (str[size- 3] - '0') * 100ll;
		case  2:	v += (str[size- 2] - '0') * 10ll;
		case  1:	v += (str[size- 1] - '0') * 1ll;
	}
	v *= sign;
}

/***************************************************************************/

template<typename T>
void default_traits::utoa(char *buf, const std::size_t, std::size_t &len, T v) {
	len = 1;
	T t = v;
	if ( t >= 10000000000000000ull ) { len += 16; t /= 10000000000000000ull; }
	if ( t >= 100000000 ) { len += 8; t /= 100000000; }
	if ( t >= 10000 ) { len += 4; t /= 10000; }
	if ( t >= 100 ) { len += 2; t /= 100; }
	if ( t >= 10 ) { len += 1; }

	*(buf+len) = 0;
	char *p = buf+len-1;
	switch ( len ) {
		case 20: *p-- = '0' + (v % 10); v /= 10;
		case 19: *p-- = '0' + (v % 10); v /= 10;
		case 18: *p-- = '0' + (v % 10); v /= 10;
		case 17: *p-- = '0' + (v % 10); v /= 10;
		case 16: *p-- = '0' + (v % 10); v /= 10;
		case 15: *p-- = '0' + (v % 10); v /= 10;
		case 14: *p-- = '0' + (v % 10); v /= 10;
		case 13: *p-- = '0' + (v % 10); v /= 10;
		case 12: *p-- = '0' + (v % 10); v /= 10;
		case 11: *p-- = '0' + (v % 10); v /= 10;
		case 10: *p-- = '0' + (v % 10); v /= 10;
		case 9 : *p-- = '0' + (v % 10); v /= 10;
		case 8 : *p-- = '0' + (v % 10); v /= 10;
		case 7 : *p-- = '0' + (v % 10); v /= 10;
		case 6 : *p-- = '0' + (v % 10); v /= 10;
		case 5 : *p-- = '0' + (v % 10); v /= 10;
		case 4 : *p-- = '0' + (v % 10); v /= 10;
		case 3 : *p-- = '0' + (v % 10); v /= 10;
		case 2 : *p-- = '0' + (v % 10); v /= 10;
		case 1 : *p-- = '0' + (v % 10); v /= 10;
	}
}
template<typename T>
void default_traits::itoa(char *buf, const std::size_t, std::size_t &len, T v) {
	if ( v < 0 ) { *buf++ = '-'; }
	T t = v = std::abs(v);

	len = 1;
	if ( t >= 10000000000000000ll ) { len += 16; t /= 10000000000000000ll; }
	if ( t >= 100000000 ) { len += 8; t /= 100000000; }
	if ( t >= 10000 ) { len += 4; t /= 10000; }
	if ( t >= 100 ) { len += 2; t /= 100; }
	if ( t >= 10 ) { len += 1; }

	*(buf+len) = 0;
	char *p = buf+len-1;
	switch ( len ) {
		case 19: *p-- = '0' + (v % 10); v /= 10;
		case 18: *p-- = '0' + (v % 10); v /= 10;
		case 17: *p-- = '0' + (v % 10); v /= 10;
		case 16: *p-- = '0' + (v % 10); v /= 10;
		case 15: *p-- = '0' + (v % 10); v /= 10;
		case 14: *p-- = '0' + (v % 10); v /= 10;
		case 13: *p-- = '0' + (v % 10); v /= 10;
		case 12: *p-- = '0' + (v % 10); v /= 10;
		case 11: *p-- = '0' + (v % 10); v /= 10;
		case 10: *p-- = '0' + (v % 10); v /= 10;
		case 9 : *p-- = '0' + (v % 10); v /= 10;
		case 8 : *p-- = '0' + (v % 10); v /= 10;
		case 7 : *p-- = '0' + (v % 10); v /= 10;
		case 6 : *p-- = '0' + (v % 10); v /= 10;
		case 5 : *p-- = '0' + (v % 10); v /= 10;
		case 4 : *p-- = '0' + (v % 10); v /= 10;
		case 3 : *p-- = '0' + (v % 10); v /= 10;
		case 2 : *p-- = '0' + (v % 10); v /= 10;
		case 1 : *p-- = '0' + (v % 10); v /= 10;
	}
}

/***************************************************************************/

template<typename T>
void default_traits::atof(T &v, const char *str, std::size_t size) {
	default_traits::atod(v, str, size);
}
template<typename T>
void default_traits::atod(T &v, const char *str, std::size_t size) {
	((void)size);
	v = 0.0;
	bool neg = false;
	if (*str == '-') {
		neg = true;
		++str;
	}
	while (*str >= '0' && *str <= '9') {
		v = (v*10.0) + (*str - '0');
		++str;
	}
	if (*str == '.') {
		double f = 0.0;
		int n = 0;
		++str;
		while (*str >= '0' && *str <= '9') {
			f = (f*10.0) + (*str - '0');
			++str;
			++n;
		}
		v += f / std::pow(10.0, n);
	}

	v = neg ? -v : v;
}

/***************************************************************************/

template<typename T>
void default_traits::ftoa(char *buf, const std::size_t bufsize, std::size_t &len, T v) {
	default_traits::dtoa(buf, bufsize, len, v);
}

inline void strreverse(char* begin, char* end) {
	while (end > begin) {
		char aux = *end;
		*end-- = *begin;
		*begin++ = aux;
	}
}

template<typename T>
void default_traits::dtoa(char *buf, const std::size_t, std::size_t &len, T v) {
	std::size_t prec = YAS_DEFAULT_DOUBLE_PRECISION;
	// from: https://code.google.com/p/stringencoders/wiki/NumToA
	static const double powers_of_10[] = {
		1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000
	};
	/* Hacky test for NaN
	  * under -fast-math this won't work, but then you also won't
	  * have correct nan values anyways.  The alternative is
	  * to link with libmath (bad) or hack IEEE double bits (bad)
	  */
	if (! (v == v)) {
		buf[0] = 'n'; buf[1] = 'a'; buf[2] = 'n'; buf[3] = '\0';
		len = 3;
	}
	/* if input is larger than thres_max, revert to exponential */
	const double thres_max = (double)(0x7FFFFFFF);

	double diff = 0.0;
	char* wstr = buf;

	if (prec < 0) {
		prec = 0;
	} else if (prec > 9) {
		/* precision of >= 10 can lead to overflow errors */
		prec = 9;
	}


	/* we'll work in positive values and deal with the
		 negative sign issue later */
	int neg = 0;
	if (v < 0) {
		neg = 1;
		v = -v;
	}


	int whole = (int)v;
	double tmp = (v - whole) * powers_of_10[prec];
	std::uint32_t frac = (std::uint32_t)(tmp);
	diff = tmp - frac;

	if (diff > 0.5) {
		++frac;
		/* handle rollover, e.g.  case 0.99 with prec 1 is 1.0  */
		if (frac >= powers_of_10[prec]) {
			frac = 0;
			++whole;
		}
	} else if (diff == 0.5 && ((frac == 0) || (frac & 1))) {
		/* if halfway, round up if odd, OR
			  if last digit is 0.  That last part is strange */
		++frac;
	}

	/* for very large numbers switch back to native sprintf for exponentials.
		 anyone want to write code to replace this? */
	/*
		normal printf behavior is to print EVERY whole number digit
		which can be 100s of characters overflowing your buffers == bad
	 */
	if (v > thres_max) {
		sprintf(buf, "%e", neg ? -v : v);
		len = strlen(buf);
	}

	if (prec == 0) {
		diff = v - whole;
		if (diff > 0.5) {
			/* greater than 0.5, round up, e.g. 1.6 -> 2 */
			++whole;
		} else if (diff == 0.5 && (whole & 1)) {
			/* exactly 0.5 and ODD, then round up */
			/* 1.5 -> 2, but 2.5 -> 2 */
			++whole;
		}
	} else {
		int count = prec;
		// now do fractional part, as an unsigned number
		do {
			--count;
			*wstr++ = (char)(48 + (frac % 10));
		} while (frac /= 10);
		// add extra 0s
		while (count-- > 0) *wstr++ = '0';
		// add decimal
		*wstr++ = '.';
	}

	// do whole part
	// Take care of sign
	// Conversion. Number is reversed.
	do *wstr++ = (char)(48 + (whole % 10)); while (whole /= 10);
	if (neg) {
		*wstr++ = '-';
	}
	*wstr='\0';
	strreverse(buf, wstr-1);
	len = (wstr - buf);
}

/***************************************************************************/

} // ns detail
} // ns yas

#endif // _yas__default_traits_hpp
