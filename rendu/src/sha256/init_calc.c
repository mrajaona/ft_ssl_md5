#include "sha256.h"

static void			init_msg_schedule(unsigned int msg[64], char *chunk)
{
	size_t			i;
	unsigned int	t[2];

	i = 0;
	while (i < 64)
	{
		if (i < 16)
		{
			ft_memcpy(&(msg[i]), chunk + (i * 4), 4);
			msg[i] = ft_endian_uint(msg[i]);
		}
		else
		{
			t[0] = (right_rot(msg[i - 15], 7)) ^ (right_rot(msg[i - 15], 18)) ^ (msg[i - 15] >> 3);
			t[1] = (right_rot(msg[i - 2], 17)) ^ (right_rot(msg[i - 2], 19)) ^ (msg[i - 2] >> 10);
			msg[i] = msg[i - 16] + t[0] + msg[i - 7] + t[1];
		}
		i++;
	}

}

void				sha256_init_calc(t_calc_sha256 *calc, unsigned int hash[8])
{
	init_msg_schedule(calc->msg_schedule, calc->chunk);
	calc->a = hash[0];
	calc->b = hash[1];
	calc->c = hash[2];
	calc->d = hash[3];
	calc->e = hash[4];
	calc->f = hash[5];
	calc->g = hash[6];
	calc->h = hash[7];
}