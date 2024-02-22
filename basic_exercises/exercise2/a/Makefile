CXX = g++
CXXFLAGS = -ggdb3 -Wall -Werror -Wno-unused -std=c++11
LDFLAGS = -Wl,-rpath,/usr/local/lib

OPTIMIZATION_LEVEL ?= -O2

OPENCV_INCDIR = /usr/local/include/opencv4
OPENCV_LIBDIR = /usr/local/lib
OPENCV_LIBS = -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs

PREFIX = exercise_02a
TARGET = $(PREFIX)_thresh
COMPILATION_FILES_FOLDER = $(TARGET).dSYM
SOURCE = $(PREFIX)_thresh.cpp
INPUT_IMAGE ?= $(PREFIX)_input_01.pgm
OUTPUT_IMAGE ?= $(PREFIX)_output_01.pgm
THRESHOLD ?= 100

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) $(OPTIMIZATION_LEVEL) $(LDFLAGS) -o $@ $< -I$(OPENCV_INCDIR) -L$(OPENCV_LIBDIR) $(OPENCV_LIBS)

run: $(TARGET) $(INPUT_IMAGE)
	./$(TARGET) $(INPUT_IMAGE) $(THRESHOLD) $(OUTPUT_IMAGE)

clean:
	rm -rf $(TARGET) $(COMPILATION_FILES_FOLDER) $(OUTPUT_IMAGE)
