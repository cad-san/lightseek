# this is set up to by default to make the top level and test with CppUTest
all: codeCppUTest

clean:
	@if [ -e cpputest/Makefile_using_MakefileWorker ]; \
	then make cleanCodeCppUTest; \
	else make cleanRelease; \
	fi

codeCppUTest: CppUTest CppUTestExt subsumption
	make -i -f scripts/MakefileCppUTest.mk

cleanCodeCppUTest:
	make -i -f scripts/MakefileCppUTest.mk clean

CppUTest: cpputest/lib/libCppUTest.a

CppUTestExt: cpputest/lib/libCppUTestExt.a

subsumption: subsumption/lib/libsubsumption.a

cpputest/lib/libCppUTest.a:
	pwd
	make -i -C cpputest -f Makefile_using_MakefileWorker

cpputest/lib/libCppUTestExt.a:
	make -i -C cpputest -f Makefile_using_MakefileWorker extensions

subsumption/lib/libsubsumption.a:
	make -i -C subsumption release

release: clean subsumption
	make -i -f scripts/MakefileRelease.mk

cleanRelease:
	make -i -f scripts/MakefileRelease.mk clean

gcov: clean
	make -i -f scripts/MakefileCppUTest.mk gcov

format:
	make -i -f scripts/MakefileUtil.mk uncrustify

check:
	make -i -f scripts/MakefileUtil.mk cppcheck
