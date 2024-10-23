#include "libmx.h"


static char *get_word_bounds(const char *str, int *start_idx, int *end_idx)
{
	char *trimmed = mx_strtrim(str);

	while (trimmed[*start_idx] != '\0' && !mx_isspace(trimmed[*start_idx]))
	{
		*start_idx += 1;
	}
	int end = *start_idx;

	while (trimmed[end] != '\0' && mx_isspace(trimmed[end]))
	{
		end++;
	}
	*end_idx = end;
	return trimmed;
}

// returns words length including spaces and
// 1 trailing space
static int get_words_len(const char *str)
{
	int len = 0;

	if (*str != '\0')
	{
		int end_idx = len;

		char *delete = get_word_bounds(str, &len, &end_idx);
		mx_strdel(&delete);

		return len + 1 + get_words_len(str + end_idx);
	}
	return len;

}

char *mx_del_extra_spaces(const char *str)
{
	if (str)
	{
		char *trimmed = mx_strtrim(str);
		int size = get_words_len(trimmed);

		if (size > 0)
		{
			char *res = mx_strnew(size - 1);

			if (res)
			{
				int place = 0;
				int start_idx = 0;
				int end_idx = 0;
				int j = end_idx;

				while(size - 1 > 0)
				{
					char *word = get_word_bounds(trimmed + j, &start_idx, &end_idx);

					j += end_idx;
					mx_strncpy(res + place, word, start_idx);
					mx_strdel(&word);
					place += start_idx;
					size -= start_idx;

					if (size - 1 > 0)
					{
						res[place] = ' ';
						size--;
					}
					place++;
					start_idx = 0;

				}
				return res;
			}
		}
		else
		{
			return trimmed;
		}
	}
	return NULL;
}



