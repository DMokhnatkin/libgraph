include ../build-scripts/common.mk

GDB=gdb
GDBFLAGS=--args
PROJECT=tests
GRAPH_PATH=../libgraph
CFLAGS+=-I$(GRAPH_PATH)/src/include
LDFLAGS=-lgtest -L$(GRAPH_PATH)/$(BUILDDIR) -lgraph

include ../build-scripts/targets.mk

test: $(TARGET)
	LD_LIBRARY_PATH=$(GRAPH_PATH)/$(BUILDDIR) ./$(TARGET) $(ARGS)

debug:
	LD_LIBRARY_PATH=$(GRAPH_PATH)/$(BUILDDIR) $(GDB) $(GDBFLAGS) ./$(TARGET) $(ARGS)
