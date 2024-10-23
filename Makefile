CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
INCDIR = inc
SRCDIR = src
OBJDIR = obj
DEBUG := false
SRCFILES = $(wildcard $(SRCDIR)/*.c)
INCFILES = $(INCDIR)/pathfinder.h
OBJFILES = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCFILES))
BINARY = pathfinder
ifeq ($(DEBUG), true)
	COMPILE = $(CC) -o $(BINARY) -g $(OBJFILES) -Llibmx -lmx
else
	COMPILE = $(CC) -o $(BINARY) $(OBJFILES) -Llibmx -lmx
endif

all: library | $(BINARY)

library:
	make -C libmx

$(BINARY) : $(OBJFILES)
	$(COMPILE)


$(OBJFILES) : | $(OBJDIR)


$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(INCDIR) -I libmx/inc

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	make -C libmx clean
	rm -rf $(OBJDIR)

uninstall: clean
	make -C libmx uninstall
	rm -f $(BINARY)

reinstall: uninstall all



