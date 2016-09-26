# Ultimate Makefile v1.0.1 (C) 2016 Ivan Chebykin
# NOTE: GNU Make only

# Targets----------------------------------------------------------------------
all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BUILDDIR)/$(OBJDIR)
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS)

$(OBJPATH)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILDDIR)

cleanobj:
	rm -rf $(OBJPATH)

remake: clean all

run: $(TARGET)
	./$(TARGET) $(ARGS)

.PHONY: all clean cleanobj remake run
