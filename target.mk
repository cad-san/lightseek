#---- Outputs ----#
COMPONENT_NAME = lightseek

#--- Inputs ----#
CPPUTEST_HOME = cpputest
CPP_PLATFORM = gcc
PROJECT_HOME_DIR = .
SCRIPT_DIR = $(PROJECT_HOME_DIR)/scripts
SUBSUMPTION_DIR = $(PROJECT_HOME_DIR)/subsumption

SRC_DIRS = \
	$(PROJECT_HOME_DIR)/src\
	$(PROJECT_HOME_DIR)/src/device\
	$(PROJECT_HOME_DIR)/src/world\
	$(PROJECT_HOME_DIR)/src/agent\

TEST_SRC_DIRS = \
	$(PROJECT_HOME_DIR)/tests\
	$(PROJECT_HOME_DIR)/tests/device\
	$(PROJECT_HOME_DIR)/tests/world\
	$(PROJECT_HOME_DIR)/tests/agent\

INC_DIRS = \
	$(PROJECT_HOME_DIR)/include\
	$(PROJECT_HOME_DIR)/include/device\
	$(PROJECT_HOME_DIR)/include/world\
	$(PROJECT_HOME_DIR)/include/agent\
	$(PROJECT_HOME_DIR)/mocks\
	$(SUBSUMPTION_DIR)/include/agent\
	$(SUBSUMPTION_DIR)/include/environment\
	$(SUBSUMPTION_DIR)/include/util\

INCLUDE_DIRS = \
	$(CPPUTEST_HOME)/include\
	$(PROJECT_HOME_DIR)/tests\
	${INC_DIRS}

MOCKS_SRC_DIRS = \
	$(PROJECT_HOME_DIR)/mocks\
	$(PROJECT_HOME_DIR)/mocks/device\
	$(PROJECT_HOME_DIR)/mocks/world\
	$(PROJECT_HOME_DIR)/mocks/agent\
