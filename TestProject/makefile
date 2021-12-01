PROD_DIR	:= ./../ProductionProject/

CXX			:= g++

CXXFLAGS 	:= -I. -I./include -I${PROD_DIR}/include

INCLUDE		:= -I"C:/msys64/mingw64/include/cppunit" -I"C:/msys64/mingw64/include/cppunit/ui/text"
LIBS		:= -L"C:/msys64/mingw64/lib" -llibcppunit -lmingw32

MSG_START	:= "Build Started"
MSG_END		:= "Build Complete"
MSG_CLEAN	:= "Cleaning up"

BUILD_DIR	:= ./bin
SRC_DIR		:= ./src

TARGET		:= ${BUILD_DIR}/app

SRC			:= ${SRC_DIR}/*.cpp ${PROD_DIR}/src/*.cpp

all			:= build

build:
	@echo ${MSG_START}

	@echo ${CXXFLAGS}

	#remove directory if it exits and then create directory
	rm -rf ${BUILD_DIR} || true

	#create bin directory
	mkdir ${BUILD_DIR}

	${CXX} -o ${TARGET} ${SRC} ${CXXFLAGS} ${INCLUDE} ${LIBS}
	@echo ${MSG_END}
	${TARGET}