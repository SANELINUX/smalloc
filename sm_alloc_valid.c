/*
 * This file is a part of SMalloc.
 * SMalloc is MIT licensed.
 * Copyright (c) 2017 Andrey Rys.
 */

#include "smalloc_i.h"

int sm_alloc_valid_pool(struct smalloc_pool *spool, const void *p)
{
	struct smalloc_hdr *shdr;

	if (!p) return 0;

	shdr = USER_TO_HEADER(p);
	if (smalloc_is_alloc(spool, shdr)) return 1;
	return 0;
}

int sm_alloc_valid(const void *p)
{
	return sm_alloc_valid_pool(&smalloc_curr_pool, p);
}
