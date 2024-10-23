CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
INCDIR = inc
SRCDIR = src
OBJDIR = obj
SRCFILES = $(wildcard $(SRCDIR)/*.c)
INCFILES = $(INCDIR)/libmx.h
OBJFILES = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCFILES))
LIB = libmx.a

all: $(LIB)

$(LIB) : $(OBJFILES)
	ar rcs $@ $^

$(OBJFILES) : | $(OBJDIR)


$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I $(INCDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

uninstall: clean
	rm -f $(LIB)

reinstall: uninstall all



