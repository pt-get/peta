#include "math.h"
#include <avr/pgmspace.h>

namespace math
{
	namespace
	{
		const uint8_t SINETABLE_SIZE = 128;
		const PROGMEM int16_t sinetable[] =
		{
			0,
			402,
			804,
			1206,
			1608,
			2009,
			2411,
			2811,
			3212,
			3612,
			4011,
			4410,
			4808,
			5205,
			5602,
			5998,
			6393,
			6787,
			7180,
			7571,
			7962,
			8351,
			8740,
			9127,
			9512,
			9896,
			10279,
			10660,
			11039,
			11417,
			11793,
			12167,
			12540,
			12910,
			13279,
			13646,
			14010,
			14373,
			14733,
			15091,
			15447,
			15800,
			16151,
			16500,
			16846,
			17190,
			17531,
			17869,
			18205,
			18538,
			18868,
			19195,
			19520,
			19841,
			20160,
			20475,
			20788,
			21097,
			21403,
			21706,
			22006,
			22302,
			22595,
			22884,
			23170,
			23453,
			23732,
			24008,
			24279,
			24548,
			24812,
			25073,
			25330,
			25583,
			25833,
			26078,
			26320,
			26557,
			26791,
			27020,
			27246,
			27467,
			27684,
			27897,
			28106,
			28311,
			28511,
			28707,
			28899,
			29086,
			29269,
			29448,
			29622,
			29792,
			29957,
			30118,
			30274,
			30425,
			30572,
			30715,
			30853,
			30986,
			31114,
			31238,
			31357,
			31471,
			31581,
			31686,
			31786,
			31881,
			31972,
			32058,
			32138,
			32214,
			32286,
			32352,
			32413,
			32470,
			32522,
			32568,
			32610,
			32647,
			32679,
			32706,
			32729,
			32746,
			32758,
			32766,
		};
	}

	int16_t sin(uint16_t theta)
	{
		uint8_t sign = 0;

		if (theta > pi)
		{
			theta -= pi;
			sign = 1;
		}
		if (theta > pi / 2)
		{
			theta = pi - theta;
		}

		uint8_t ind = (uint8_t) ((uint32_t) theta * SINETABLE_SIZE * 2 / pi);
		uint16_t r;
		if (ind == SINETABLE_SIZE - 1)
		{
			r = sinetable[SINETABLE_SIZE - 1];
		}
		else
		{
			uint16_t lower = pgm_read_word(sinetable + ind);
			uint16_t upper = pgm_read_word(sinetable + ind + 1);

			r = lower + (upper - lower) * (theta % (pi / 2 / SINETABLE_SIZE)) / (pi / 2 / SINETABLE_SIZE);
		}

		return sign ? -r : r;
	}

	int16_t cos(uint16_t theta)
	{
		return sin(theta + pi / 2);
	}
}
