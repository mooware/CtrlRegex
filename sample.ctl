#uses "CtrlRegex"

int main(string input, string pattern)
{
  DebugN("matching", input, pattern);
  DebugN("re case", reMatch(input, pattern));
  DebugN("re nocase", reMatch(input, pattern, false));
  DebugN("wildcard case", reMatch(input, pattern, true, RE_WILDCARD));
  DebugN("wildcard nocase", reMatch(input, pattern, false, RE_WILDCARD));

  dyn_string list;
  list[1] = "foo";
  list[2] = "foo_";
  list[3] = "foo_2";
  dyn_string result = reDynMatch(list, pattern);
  DebugN(list, result);

  return 0;
}
