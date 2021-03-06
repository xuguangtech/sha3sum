/* See LICENSE file for copyright and license details. */
#include <libkeccak.h>


#define COMMON_MAIN(CONFIGURATION, SUFFIX)\
	int main(int argc, char *argv[]) {\
		libkeccak_generalised_spec_t spec;\
		libkeccak_generalised_spec_initialise(&spec);\
		CONFIGURATION;\
		return run(argc, argv, &spec, SUFFIX);\
	}
#define KECCAK_MAIN(N)\
	COMMON_MAIN(libkeccak_spec_sha3((libkeccak_spec_t *)&spec, N), "")
#define SHA3_MAIN(N)\
	COMMON_MAIN(libkeccak_spec_sha3((libkeccak_spec_t *)&spec, N), LIBKECCAK_SHA3_SUFFIX)
#define RAWSHAKE_MAIN(N)\
	COMMON_MAIN(libkeccak_spec_rawshake((libkeccak_spec_t *)&spec, N, N), LIBKECCAK_RAWSHAKE_SUFFIX)
#define SHAKE_MAIN(N)\
	COMMON_MAIN(libkeccak_spec_shake((libkeccak_spec_t *)&spec, N, N), LIBKECCAK_SHAKE_SUFFIX)


/**
 * Message digest representation formats
 */
enum representation {
	/**
	 * Print the checksum in binary
	 */
	REPRESENTATION_BINARY,

	/**
	 * Print the checksum in upper case hexadecimal
	 */
	REPRESENTATION_UPPER_CASE,

	/**
	 * Print the checksum in lower case hexadecimal
	 */
	REPRESENTATION_LOWER_CASE
};


/**
 * Parse the command line and calculate the hashes of the selected files
 * 
 * @param   argc    The first argument from `main`
 * @param   argv    The second argument from `main`
 * @param   gspec   The default algorithm parameters
 * @param   suffix  Message suffix
 * @return          An appropriate exit value
 */
int run(int argc, char *argv[], libkeccak_generalised_spec_t *restrict gspec, const char *restrict suffix);
