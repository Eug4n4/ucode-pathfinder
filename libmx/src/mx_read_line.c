#include "../inc/libmx.h"

static void write_from_remainder(char **remainder, char **lineptr)
{
	*lineptr = mx_strdup(*remainder);
	mx_strdel(remainder);
}


static void write_to_remainder(char **remainder, char *buf, int buflen, int idx)
{
	char *content = NULL;

	if (!*remainder)
	{
		content = mx_strdup(buf);
	}
	else if (buflen == idx)
	{
		content = mx_strjoin(*remainder, buf);
	}
	if (content)
	{
		mx_strdel(remainder);
		*remainder = content;
	}

}


int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd)
{
	if (lineptr && fd > 0)
	{
		static char *remainder = NULL;
		char buf[buf_size + 1];
		int bytes = 0;
		mx_memset(buf, 0, buf_size + 1);
		int bytesread = read(fd, buf, buf_size);

		if (bytesread > 0)
		{
			int idx = mx_get_char_index(buf, delim);

			if (idx != -1)
			{
				write_to_remainder(&remainder, buf, buf_size, idx);
				bytes += idx;
			}
			else
			{
				bytes += bytesread;
				write_to_remainder(&remainder, buf, buf_size, bytesread);

				while (bytesread > 0 && idx == -1)
				{
					bytesread = read(fd, buf, buf_size);
					if (bytesread > 0)
					{
						idx = mx_get_char_index(buf, delim);
						write_to_remainder(&remainder, buf, buf_size, idx == -1 ? (int)buf_size : idx);
						bytes += (idx == -1 ? bytesread : idx);
					}
				}

			}

		}
		else
		{
			if (bytesread == -1)
			{
				return -2;
			}
			return -1;
		}
		write_from_remainder(&remainder, lineptr);
		return bytes;
	}
	return -2;

}




