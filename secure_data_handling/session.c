#include <stdlib.h>
#include <string.h>
#include "session.h"

static char *dup_string(const char *src)
{
	char *copy;
	size_t len;

	if (!src)
		return (NULL);

	len = strlen(src) + 1;
	copy = (char *)malloc(len);
	if (!copy)
		return (NULL);

	memcpy(copy, src, len);
	return (copy);
}

session_t *session_create(const char *id, unsigned int uid,
	const unsigned char *data, size_t data_len)
{
	session_t *s;

	if (!id)
		return (NULL);

	s = (session_t *)malloc(sizeof(*s));
	if (!s)
		return (NULL);

	s->id = NULL;
	s->uid = uid;
	s->data = NULL;
	s->data_len = 0;

	s->id = dup_string(id);
	if (!s->id)
	{
		free(s);
		return (NULL);
	}

	if (data_len > 0)
	{
		if (!data)
		{
			free(s->id);
			free(s);
			return (NULL);
		}

		s->data = (unsigned char *)malloc(data_len);
		if (!s->data)
		{
			free(s->id);
			free(s);
			return (NULL);
		}

		memcpy(s->data, data, data_len);
		s->data_len = data_len;
	}

	return (s);
}

int session_set_data(session_t *s, const unsigned char *data, size_t data_len)
{
	unsigned char *new_data;

	if (!s)
		return (0);

	if (data_len == 0)
	{
		free(s->data);
		s->data = NULL;
		s->data_len = 0;
		return (1);
	}

	if (!data)
		return (0);

	new_data = (unsigned char *)malloc(data_len);
	if (!new_data)
		return (0);

	memcpy(new_data, data, data_len);
	free(s->data);
	s->data = new_data;
	s->data_len = data_len;

	return (1);
}

void session_destroy(session_t *s)
{
	if (!s)
		return;

	free(s->id);
	free(s->data);
	free(s);
}
