////////////////////////////////////////////////////////////////////////////////
//
// Copyright 2015 - 2018, Paul Beckingham, Federico Hernandez.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// http://www.opensource.org/licenses/mit-license.php
//
////////////////////////////////////////////////////////////////////////////////

#include <commands.h>
#include <timew.h>
#include <iostream>

////////////////////////////////////////////////////////////////////////////////
// Returns 0 if tracking is active, 1 if not.
int CmdDefault (Rules& rules, Database& database)
{
  // Load the most recent interval, summarize and display.
  auto interval = getLatestInterval (database);

  if (interval.range.is_open ())
  {
    if (rules.getBoolean ("verbose"))
    {
      std::cout << intervalSummarize (database, rules, interval);
    }

    return 0;
  }

  if (rules.getBoolean ("temp.shiny"))
  {
    std::cout << '\n'
              << "Welcome to Timewarrior.\n"
              << '\n'
              << "There is built-in help:\n"
              << "    timew help\n"
              << "    timew help <command>\n"
              << "    (and more)\n"
              << '\n'
              << "There is a fully-detailed man page:\n"
              << "    man timew\n"
              << '\n';
    return 0;
  }

  if (rules.getBoolean ("verbose"))
  {
    std::cout << "There is no active time tracking.\n";
  }

  return 1;
}

////////////////////////////////////////////////////////////////////////////////
