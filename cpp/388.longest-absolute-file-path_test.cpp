#include "leetcode.h"
#include <gtest/gtest.h>

#include "388.longest-absolute-file-path.cpp"

#define FunName lengthLongestPath

TEST(testname, subname) {
  VERIFY(12, "file1.txt\nfile2.txt\nlongfile.txt");
  VERIFY(32, "dir/subdir2/subsubdir2/file2.ext");
  VERIFY(0, "a");
  VERIFY(20, "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext");
}
