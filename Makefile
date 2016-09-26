# Ultimate Makefile v1.0.1 (C) 2016 Ivan Chebykin
# NOTE: GNU Make only
#
PROJECTS=libgraph tests

all: $(PROJECTS)

$(PROJECTS): %:
	$(MAKE) -C $(PWD)/$@

test: $(PROJECTS)
	$(MAKE) -C $(PWD)/tests test

clean:
	for PROJECT in $(PROJECTS); do \
		$(MAKE) -C $(PWD)/$$PROJECT clean; \
	done

.PHONY: libgraph test clean
