TARGET=NODEBUG

all:
	@PATH=$(PATH):$(shell pwd)/toolchain/bin $(MAKE) $(TARGET) -C src -s
	@#@$(MAKE) clean -s

clean:
	@$(MAKE) clean -C src -s
