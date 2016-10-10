#pragma once

#define LG_REQ_COND(cond, ex) \
	if( !cond ) { \
		throw ex; \
	}