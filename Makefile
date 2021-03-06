PROG=TerminatedProject
SRCS=TerminatedProject.c combine.c check.c will_and_die.c
SRCS_XDEP=TerminatedProject.c combine.c check.c
OBJS=$(SRCS:%.c=%.c.o)
OBJS_XDEP=$(SRCS_XDEP:%.c=%.c.o)
ALLDEP=$(MAKEFILE_LIST)
TOCLEAN=ms.txt

all: $(PROG)

CC:=cc
HEADERFLAGS:=-I.
OPTFLAGS:=-O0 -g
WARNFLAGS:=-ansi -pedantic -Wall -Wextra -W -Wundef -Wshadow -Wcast-qual -Winline -Wno-long-long -fsigned-char
RM:=rm -r -f
WC:=wc -c -l

COMPILE.c=$(CC) $(HEADERFLAGS) $(OPTFLAGS) $(WARNFLAGS) $(DEPFLAGS) $(ADDCFLAGS) $(CFLAGS) -c
LINK.o=$(CC) $(OPTFLAGS) $(WARNFLAGS) $(LINKFLAGS) $(LDFLAGS)

X?=5
X_VALFLAGS=-DX=$(X)
XNUM=.x
$(shell ([ -f $(XNUM) ] && [ `cat $(XNUM)` -eq $(X) ]) || echo $(X) >$(XNUM))

$(OBJS_XDEP): $(XNUM)
$(OBJS_XDEP): DEPFLAGS+=$(X_VALFLAGS)


$(PROG): $(OBJS) $(ALLDEP)
	$(LINK.o) $(OUTPUT_OPTION) $(OBJS)

%.c.o: %.c $(ALLDEP)
	$(COMPILE.c) $(OUTPUT_OPTION) $<

run: $(PROG)
	./$(PROG)

.PHONY: line
line:
	$(WC) $(SRCS) $(MAKEFILE_LIST)

.PHONY: clean
clean:
	$(RM) $(PROG) $(OBJS)
	$(RM) $(XNUM)
	$(RM) $(TOCLEAN)
