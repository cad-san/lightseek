#This makefile makes all the main book code with CppUTest test harness

#Set this to @ to keep the makefile quiet
SILENCE = @

#--- Outputs & Inputs ----#
include target.mk

#---- Setting ----#
CPPUTEST_WARNINGFLAGS = -Wall -Wswitch-default -Werror
CPPUTEST_CFLAGS += -Wall -Wstrict-prototypes -pedantic
CPPUTEST_CXXFLAGS += -include tests/PreIncludeFiles.h

CPPUTEST_LDFLAGS += -L$(SUBSUMPTION_DIR)/lib
LD_LIBRARIES = -lsubsumption -lboost_thread-mt -lboost_system-mt

CPPUTEST_USE_GCOV = Y
CPPUTEST_USE_EXTENSIONS = Y

include $(CPPUTEST_HOME)/build/MakefileWorker.mk
