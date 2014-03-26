CtrlRegex
=========

Qt QRegExp bindings for the CONTROL scripting language.

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

Since this is just a simple wrapper around QRegExp from QtCore, the QRegExp documentation should answer most of your questions.

License
=======

Licensed under the MIT License, see the LICENSE file included in the repository.