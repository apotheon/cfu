# C Fu

This project is a catch-all "C practice" repository.  I'm basically just
spraying rust-remover all over my C skills.

I started going through the ANSI C "White Bible" (K&R, *The C Programming
Language*) again, and any excercises I tackle will be included here.

I may also play around with Unix tool implemenations.

## Roadmap

This isn't so much a map as a highly detailed napkin sketch, and it is not to
scale, so don't trust it to get you where you're going.

### [Core Unix Utilities][coreutil]

#### [cat][cat]

Reimplement cat, without bloat.  The new POSIX-compliant options list should
look something like the following:

        -h            Print this help information.
    
        -u            Disable output buffering.
    
        -W <COMMAND>  Print out information specified by <COMMAND>.
    
        --            If the first option, or the first option fol-
                      lowing -u, the -- option disables any further
                      option handling on the command line.

The `-W` commands should provide informational output, including `help`,
`license`, and `version`.

Relative to BSD cat, this adds `-h` and `-W`.  It also removes `-b`, `-e`,
`-n`, `-s`, `-t`, and the [harmful][cat-v] `-v`.  Let us not waste our time
enumerating the list of harmful and standards violating options in GNU cat,
whose name is Legion.

#### [echo][echo]

Reimplement echo, without heaps of unnecessary internal complexity, but with
informational options added.  The new options list should look something like
the following:

        -n            Do not print a trailing newline character.  This must
                      be the first argument.  Otherwise, it will be used as
                      an input string operand.  It must be followed by at
                      least one input string operand; otherwise, this usage
                      information will be printed to standard output and
                      the program will exit with an error value of 1.

#### [mimic][mimic]

The mimic utility is intended to be what a POSIX compliant implementation of
echo should probably be in a world where h(yste|isto)rical concerns particular
to that utility did not stand in the way of conscientious user-helpful utility
design in the POSIX standard.  It is currently in a transitional stage, but the
ultimate form of its options will probably look something like this:

        -h            Print this help information.
        
        -n            Do not print a trailing newline character.
        
        -W <COMMAND>  Print out information specified by <COMMAND>.
        
        --            If the first option, the -- option disables
                      further option handling on the command line.

The `-W` commands are as for cat.

#### printable

The printable utility will be a filter that translates between various forms of
printability and unprintability of characters.  The use case for this is
keeping other tools focused on their purposes and strengths, allowing them to
offload printability filtering to `|printable`.  The canonical example should
be obvious -- replacing `cat -v foo` with `cat foo|printable -v`.

[cat]: /artifact?ci=tip&filename=coreutil/posix/cat.c
[cat-v]: http://harmful.cat-v.org/cat-v/
[coreutil]: dir?ci=tip&name=coreutil
[echo]: artifact?ci=tip&filename=coreutil/posix/echo.c
[mimic]: artifact?ci=tip&filename=coreutil/mimic.c
