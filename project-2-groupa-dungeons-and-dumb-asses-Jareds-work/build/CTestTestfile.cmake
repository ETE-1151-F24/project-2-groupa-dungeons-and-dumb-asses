# CMake generated Testfile for 
# Source directory: C:/Users/e/project-2-groupa-dungeons-and-dumb-asses-1/project-2-groupa-dungeons-and-dumb-asses-Jareds-work
# Build directory: C:/Users/e/project-2-groupa-dungeons-and-dumb-asses-1/project-2-groupa-dungeons-and-dumb-asses-Jareds-work/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(GameInventoryFunctionsTest "C:/Users/e/project-2-groupa-dungeons-and-dumb-asses-1/project-2-groupa-dungeons-and-dumb-asses-Jareds-work/build/Debug/run_tests.exe")
  set_tests_properties(GameInventoryFunctionsTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/e/project-2-groupa-dungeons-and-dumb-asses-1/project-2-groupa-dungeons-and-dumb-asses-Jareds-work/CMakeLists.txt;56;add_test;C:/Users/e/project-2-groupa-dungeons-and-dumb-asses-1/project-2-groupa-dungeons-and-dumb-asses-Jareds-work/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(GameInventoryFunctionsTest "C:/Users/e/project-2-groupa-dungeons-and-dumb-asses-1/project-2-groupa-dungeons-and-dumb-asses-Jareds-work/build/Release/run_tests.exe")
  set_tests_properties(GameInventoryFunctionsTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/e/project-2-groupa-dungeons-and-dumb-asses-1/project-2-groupa-dungeons-and-dumb-asses-Jareds-work/CMakeLists.txt;56;add_test;C:/Users/e/project-2-groupa-dungeons-and-dumb-asses-1/project-2-groupa-dungeons-and-dumb-asses-Jareds-work/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(GameInventoryFunctionsTest "C:/Users/e/project-2-groupa-dungeons-and-dumb-asses-1/project-2-groupa-dungeons-and-dumb-asses-Jareds-work/build/MinSizeRel/run_tests.exe")
  set_tests_properties(GameInventoryFunctionsTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/e/project-2-groupa-dungeons-and-dumb-asses-1/project-2-groupa-dungeons-and-dumb-asses-Jareds-work/CMakeLists.txt;56;add_test;C:/Users/e/project-2-groupa-dungeons-and-dumb-asses-1/project-2-groupa-dungeons-and-dumb-asses-Jareds-work/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(GameInventoryFunctionsTest "C:/Users/e/project-2-groupa-dungeons-and-dumb-asses-1/project-2-groupa-dungeons-and-dumb-asses-Jareds-work/build/RelWithDebInfo/run_tests.exe")
  set_tests_properties(GameInventoryFunctionsTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/e/project-2-groupa-dungeons-and-dumb-asses-1/project-2-groupa-dungeons-and-dumb-asses-Jareds-work/CMakeLists.txt;56;add_test;C:/Users/e/project-2-groupa-dungeons-and-dumb-asses-1/project-2-groupa-dungeons-and-dumb-asses-Jareds-work/CMakeLists.txt;0;")
else()
  add_test(GameInventoryFunctionsTest NOT_AVAILABLE)
endif()
subdirs("PROJECT_1/googletest")
