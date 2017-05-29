/* openssl dhparam -C -2 512 */
#ifndef HEADER_DH_H
#include <openssl/dh.h>
#endif

static DH *get_dh512()
{
	static unsigned char dhp_512[]={
		0xED,0x78,0x7E,0x95,0xB9,0x05,0xD5,0x00,0x38,0xC6,0x6B,0x49,
		0x78,0x22,0x78,0x43,0x8D,0xCC,0xF9,0x83,0x18,0xBB,0x6E,0xFE,
		0xCD,0x90,0xC3,0x84,0xA8,0x5C,0x04,0x84,0xEB,0x85,0x1D,0x5B,
		0x81,0x68,0xA1,0xB5,0xCC,0x09,0x10,0x46,0x04,0x8B,0x0A,0x06,
		0xA5,0xA7,0x10,0x7D,0x43,0x1B,0x6F,0xAD,0xA8,0xA1,0xB0,0xD3,
		0xD9,0x23,0xD1,0x83,
	};
	static unsigned char dhg_512[]={
		0x02,
	};
	DH *dh;
	BIGNUM *dhp_bn, *dhg_bn;

	if ((dh=DH_new()) == NULL) return(NULL);
	dhp_bn = BN_bin2bn(dhp_512, sizeof (dhp_512), NULL);
	dhg_bn = BN_bin2bn(dhg_512, sizeof (dhg_512), NULL);
	if (!DH_set0_pqg(dh, dhp_bn, NULL, dhg_bn)) {
		DH_free(dh);
		BN_free(dhp_bn);
		BN_free(dhg_bn);
		return(NULL);
	}
	return(dh);
}
/*
-----BEGIN DH PARAMETERS-----
MEYCQQDteH6VuQXVADjGa0l4InhDjcz5gxi7bv7NkMOEqFwEhOuFHVuBaKG1zAkQ
RgSLCgalpxB9QxtvraihsNPZI9GDAgEC
-----END DH PARAMETERS-----
*/
