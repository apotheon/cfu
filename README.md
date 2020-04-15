# C-Fu

This project is a catch-all "C practice" repository.  I'm basically just
spraying rust-remover all over my C skills.

I started going through the ANSI C "White Bible" (K&R, *The C Programming
Language*) again, and any excercises I tackle will be included here.

I may also play around with Unix tool implemenations.

* [Fossil Repository](https://fossrec.com/u/apotheon/cfu)
* [GitHub Mirror](https://github.com/apotheon/cfu)
* [GitLab Mirror](https://gitlab.com/apotheon/cfu)

## Roadmap

This isn't so much a map as a highly detailed napkin sketch, and it is not to
scale, so don't trust it to get you where you're going.

### [adhockery][adhockery]

#### [copystring][copystring]

Provide an alternative implementation of the naive strcmp replacement shown in
Ted Jensen's public domain short ebook *A Tutorial On Pointers And Arrays In C*
from the beginning of Chapter 4 with an example of use.  Further, provide a
less naive implementation by including bounds checking, and demonstrate both
the ideal use case and the unhappy-path use case where the source string is
longer than the space allocated for the destination buffer.

#### [downcounter][downcounter]

Provide a simple console-based countdown timer that shows a number counting
down from the numeric command line argument to 1, then attempts a console beep
and prints a "TIME'S UP!" message before exiting.  It uses usleep to avoid too
much CPU churn for a trivial timer loop.

#### [floaters][floaters]

Demonstrate problems with the IEEE 754 standard used as the default fractional
numeric type, and incidentally test the host system's C implementation for
problems with IEEE 754 binary rounding translation to decimal.

#### [ptrmgc][ptrmgc]

Demonstrate simple use of function pointers with explicit dereference syntax.

#### [ternary_associativity][ternass]

Use the FIVE test to demonstrate ternary operator associativity in C, in
contrast with the utter brokenness of ternary operator associativity in PHP.

### [ANSI Bible][ansi]

Complete exercises from the ANSI C (second) edition of K&R's White Bible.

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

[adhockery]: /dir?ci=tip&name=adhockery
[ansi]: /dir?ci=tip&name=ansi_bible
[cat]: coreutil/posix/cat.c
[cat-v]: http://harmful.cat-v.org/cat-v/
[copystring]: /file?ci=tip&name=adhockery/copystring.c
[coreutil]: /dir?ci=tip&name=coreutil
[copystring]: /file?ci=tip&name=adhockery/downcounter.c
[echo]: coreutil/posix/echo.c
[floaters]: /file?ci=tip&name=adhockery/floaters.c
[mimic]: coreutil/mimic.c
[ptrmgc]: /file?ci=tip&name=adhockery/ptrmgc.c
[ternass]: /file?ci=tip&name=adhockery/ternary_associativity.c
