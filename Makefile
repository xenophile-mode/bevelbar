__NAME__ = bevelbar

CFLAGS += -Wall -Wextra -O2 -std=c99
CFLAGS_X11 = $(CFLAGS) `pkg-config --cflags x11 xrandr xft`
LDFLAGS_X11 = $(LDFLAGS) -lm `pkg-config --libs x11 xrandr xft`

INSTALL = install
INSTALL_PROGRAM = $(INSTALL)
INSTALL_DATA = $(INSTALL) -m 644

prefix = /usr/local
exec_prefix = $(prefix)
bindir = $(exec_prefix)/bin
datarootdir = $(prefix)/share
mandir = $(datarootdir)/man
man1dir = $(mandir)/man1


.PHONY: all clean install installdirs

all: $(__NAME__) $(__NAME__)-time

$(__NAME__): $(__NAME__).c
	$(CC) $(CFLAGS_X11) $(LDFLAGS_X11) -D__NAME__=\"$(__NAME__)\" -o $@ $<

$(__NAME__)-time: $(__NAME__)-time.c
	$(CC) $(CFLAGS) $(LDFLAGS) -D__NAME__=\"$(__NAME__)-time\" -o $@ $<

clean:
	rm -f $(__NAME__) $(__NAME__)-time

install: $(__NAME__) installdirs
	$(INSTALL_PROGRAM) $(__NAME__) $(DESTDIR)$(bindir)/$(__NAME__)
	$(INSTALL_PROGRAM) $(__NAME__)-time $(DESTDIR)$(bindir)/$(__NAME__)-time
	$(INSTALL_DATA) $(__NAME__).1 $(DESTDIR)$(man1dir)/$(__NAME__).1
	$(INSTALL_DATA) $(__NAME__)-time.1 $(DESTDIR)$(man1dir)/$(__NAME__)-time.1

installdirs:
	mkdir -p $(DESTDIR)$(bindir) $(DESTDIR)$(man1dir)
