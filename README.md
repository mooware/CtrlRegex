CtrlRegex
=========

Qt QRegExp bindings for the CONTROL scripting language of WinCC OA.

Usage
=====
Currently there are just two functions.

```c
// returns true if the pattern fully matches the input
bool reMatch(string input, string pattern, bool caseSensitive = true, int syntaxType = RE_REGEX)

// returns all entries of the input list for which the pattern fully matches the text
dyn_string reDynMatch(dyn_string input, string pattern, bool caseSensitive = true, int syntaxType = RE_REGEX)

// syntaxType can be one of the following values:
// - RE_REGEX: default, standard regex matching
// - RE_REGEX2: more "greedy" regex matching
// - RE_WILDCARD: globbing
// - RE_WILDCARD_UNIX: globbing with unix flavor
```

The [sample.ctl](sample.ctl) script contains a few examples.

Since this is just a simple wrapper around QRegExp from QtCore, the QRegExp documentation should answer most of your questions.

Build
=====

I got the build working on Linux with the non-qmake Makefile currently checked in. Windows builds with the Visual Studio project. Note that a few environment variables have to be set to point to the Qt headers (and lib on Windows).

A somewhat hackish aspect is that the WinCC OA API kit does not actually include headers for Qt, but the setup includes and uses a ```QtCore.so```. The current Makefile uses the same ```QT_NAMESPACE``` as WinCC OA, so that it works with the included shared library.

There are pre-built binaries for WinCC OA 3.12 in the Releases tab.

License
=======

Licensed under the MIT License, see the LICENSE file included in the repository.
