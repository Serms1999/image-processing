CXX = g++
CXXFLAGS = -ggdb3 -Wall -Werror -Wno-unused -std=c++11
LDFLAGS = -Wl,-rpath,/usr/local/lib

OPTIMIZATION_LEVEL ?= -O2

OPENCV_INCDIR = /usr/local/include/opencv4
OPENCV_LIBDIR = /usr/local/lib
OPENCV_LIBS = -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs

PREFIX = exercise_02b
TARGET = $(PREFIX)_compare
COMPILATION_FILES_FOLDER = $(TARGET).dSYM
SOURCE = $(PREFIX)_compare.cpp
INPUT_IMAGE_1 ?= $(PREFIX)_input_01.pgm
INPUT_IMAGE_2 ?= $(PREFIX)_input_02.pgm
OUTPUT_FILE = $(PREFIX)_output_01.txt

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $(OPTIMIZATION_LEVEL) $(LDFLAGS) -o $@ $< -I$(OPENCV_INCDIR) -L$(OPENCV_LIBDIR) $(OPENCV_LIBS)

run: $(TARGET) $(INPUT_IMAGE_1) $(INPUT_IMAGE_2)
	./$(TARGET) $(INPUT_IMAGE_1) $(INPUT_IMAGE_2)

clean:
	rm -rf $(TARGET) $(COMPILATION_FILES_FOLDER) $(OUTPUT_FILE)
