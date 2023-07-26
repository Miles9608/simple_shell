#include "shell.h"

/**
 * is_cmd - determines an executable file command
 * @info: struct
 * @path: file path
 *
 * Return: 1 if successful, 0 failure
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - duplicates characters
 * @pathstr: string path
 * @start: index
 * @stop: stopping index
 *
 * Return: buffer pointer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int miles = 0, z = 0;

	for (z = 0, miles = start; miles < stop; miles++)
		if (pathstr[miles] != ':')
			buf[z++] = pathstr[miles];
	buf[z] = 0;
	return (buf);
}

/**
 * find_path - finds this cmd in the PATH string
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int miles = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[miles] || pathstr[miles] == ':')
		{
			path = dup_chars(pathstr, curr_pos, miles);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[miles])
				break;
			curr_pos = miles;
		}
		miles++;
	}
	return (NULL);
}
