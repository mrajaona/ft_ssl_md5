#include "sha256.h"

const unsigned int	g_sha256_const_table[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1,
	0x923f82a4, 0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786,
	0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147,
	0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b,
	0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a,
	0x5b9cca4f, 0x682e6ff3, 0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

void	sha256_calc_loop(t_calc_sha256 *calc)
{
	unsigned int	tmp[5];
	size_t	i;

	i = 0;
	while (i < 64)
	{
		if (i < 16)
			printf("%.8x_", calc->msg_schedule[i]);

        tmp[0] = (right_rot(calc->e, 6)) ^ (right_rot(calc->e, 11)) ^ (right_rot(calc->e, 25));
        tmp[1] = (calc->e & calc->f) ^ (~(calc->e) & calc->g);
        tmp[2] = calc->h + tmp[0] + tmp[1] + g_sha256_const_table[i] + calc->msg_schedule[i];
        tmp[3] = (right_rot(calc->a, 2)) ^ (right_rot(calc->a, 13)) ^ (right_rot(calc->a, 22));
        tmp[4] = (calc->a & calc->b) ^ (calc->a & calc->c) ^ (calc->b & calc->c);
        tmp[5] = tmp[3] + tmp[4];

        calc->h = calc->g;
        calc->g = calc->f;
        calc->f = calc->e;
        calc->e = calc->d + tmp[2];
        calc->d = calc->c;
        calc->c = calc->b;
        calc->b = calc->a;
        calc->a = tmp[2] + tmp[5];
		i++;
	}
	printf("\n");
}