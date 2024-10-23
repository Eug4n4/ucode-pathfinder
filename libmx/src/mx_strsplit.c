#include "libmx.h"


char **mx_strsplit(char const *s, char c)
{
	if (s)
	{
		int start_idx = 0;
		int count = 0;
		int delim_idx = mx_get_char_index(s, c);
		int size = mx_count_words(s, c);
		char **words = malloc(sizeof(char *) * (size + 1));

		if (words)
		{
			while (count < size)
			{
				while (delim_idx != -1 && delim_idx + start_idx == start_idx)
				{
					start_idx++;
					delim_idx = mx_get_char_index(s + start_idx, c);
				}
				if (delim_idx == -1)
				{
					words[count] = mx_strnew(mx_strlen(s) - start_idx);
				}
				else
				{
					words[count] = mx_strnew(delim_idx);
				}
				mx_strncpy(words[count++], s + start_idx, delim_idx == -1 ? mx_strlen(s) - start_idx : delim_idx);
				start_idx += delim_idx;
				delim_idx = 0;
			}
			words[count] = NULL;
			return words;
		}
	}
	return NULL;
}



