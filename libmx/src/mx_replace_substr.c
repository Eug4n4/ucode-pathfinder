#include "libmx.h"



char *mx_replace_substr(const char *str, const char *sub, const char *replace)
{
	if (!str || !sub || !replace)
	{
		return NULL;
	}

	const char *substr = str;
	int substr_len = mx_strlen(sub);
	char *res = mx_strdup(str);
	int i = 0;
	int offset = 0;
	int flag = 0;


	while ((substr = mx_strstr(substr + i, sub)) != NULL)
	{
		char *replaced = mx_strjoin(replace, substr + substr_len);
		int replaced_len = mx_strlen(replaced);
		int right = mx_strlen(substr);

		offset = mx_strlen(str) - right; // if first substring was not at the beginning
		if (!flag && offset > 0)
		{
			mx_strdel(&res);
			res = mx_strnew(offset + replaced_len);
			mx_strncpy(res, str, offset);
			mx_strncpy(res + offset, replaced, replaced_len);

		}
		else
		{
			offset = mx_strlen(res) - right;

			char *tmp = mx_strnew(offset + replaced_len);

			mx_strncpy(tmp, res, offset);
			mx_strncpy(tmp + offset, replaced, replaced_len);
			mx_strdel(&res);
			res = mx_strdup(tmp);
			mx_strdel(&tmp);

		}

		i = substr_len;
		mx_strdel(&replaced);
		flag = 1;
		if (sub[0] == '\0')
		{
			break;
		}
	}
	return res;

}






