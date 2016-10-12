# Ultimate Makefile v1.0.1 (C) 2016 Ivan Chebykin
# NOTE: GNU Make only
#
PROJECTS=libgraph tests

INCLUDE_DIR=libgraph/src/include
SRCDIR?=libgraph/src
include build-scripts/common.mk

all: $(PROJECTS)

$(PROJECTS): %:
	$(MAKE) -C $(PWD)/$@

test: $(PROJECTS)
	$(MAKE) -C $(PWD)/tests test

debug-test: $(PROJECTS)
	$(MAKE) -C $(PWD)/tests debug

clean:
	for PROJECT in $(PROJECTS); do \
		$(MAKE) -C $(PWD)/$$PROJECT clean; \
	done

ctags:
	$(CC) $(CFLAGS) -M $(SOURCES) 2>/dev/null | \
	sed -e 's/[\\ ]/\n/g' | \
    sed -e '/^$$/d' -e '/\.o:/d' | \
    ctags -L - --c++-kinds=+p --fields=+iaS --extra=+q

.PHONY: libgraph test clean ctags
