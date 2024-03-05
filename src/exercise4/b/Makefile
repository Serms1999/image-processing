CXX = g++
CXXFLAGS = -ggdb3 -Wall -Werror -Wno-unused -std=c++11
LDFLAGS = -Wl,-rpath,/usr/local/lib

OPTIMIZATION_LEVEL ?= -O2

OPENCV_INCDIR = /usr/local/include/opencv4
OPENCV_LIBDIR = /usr/local/lib
OPENCV_LIBS = -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs

PREFIX = exercise_04b
TARGET = $(PREFIX)_closing
SOURCES = $(TARGET).cpp erosion.cpp dilation.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = $(TARGET).hpp erosion.hpp dilation.hpp
COMPILATION_FILES_FOLDER = $(TARGET).dSYM
INPUT_IMAGE ?= $(PREFIX)_input_01.pgm
OUTPUT_IMAGE = $(PREFIX)_output_01.pgm
SIZE ?= 1

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OPTIMIZATION_LEVEL) $(LDFLAGS) -o $@ $^ -I$(OPENCV_INCDIR) -L$(OPENCV_LIBDIR) $(OPENCV_LIBS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(OPTIMIZATION_LEVEL) -c -o $@ $< -I$(OPENCV_INCDIR)

run: $(TARGET)
	./$(TARGET) $(SIZE) $(INPUT_IMAGE) $(OUTPUT_IMAGE)

clean:
	rm -rf $(TARGET) $(OBJECTS) $(COMPILATION_FILES_FOLDER) $(OUTPUT_IMAGE)
