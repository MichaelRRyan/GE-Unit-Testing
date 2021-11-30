CXX			:= g++

CXXFLAGS 	:= -I. -I./include

MSG_START	:= "Build Started"
MSG_END		:= "Build Complete"
MSG_CLEAN	:= "Cleaning up"

BUILD_DIR	:= ./bin
SRC_DIR		:= ./

TARGET		:= ${BUILD_DIR}/app

SRC			:= ${SRC_DIR}/*.cpp

all			:= build

build:
	@echo ${MSG_START}

	@echo ${CXXFLAGS}

	#remove directory if it exits and then create directory
	rm -rf ${BUILD_DIR} || true

	#create bin directory
	mkdir ${BUILD_DIR}

	${CXX} -o ${TARGET} ${SRC} ${CXXFLAGS}
	@echo ${MSG_END}
	${TARGET}