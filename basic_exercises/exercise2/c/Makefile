CXX = g++
CXXFLAGS = -ggdb3 -Wall -Werror -Wno-unused -std=c++11
LDFLAGS = -Wl,-rpath,/usr/local/lib

OPTIMIZATION_LEVEL ?= -O2

OPENCV_INCDIR = /usr/local/include/opencv4
OPENCV_LIBDIR = /usr/local/lib
OPENCV_LIBS = -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs

TARGET_SUP = exercise_02c_sup
TARGET_INF = exercise_02c_inf
SOURCE_SUP = $(TARGET_SUP).cpp
SOURCE_INF = $(TARGET_INF).cpp
COMPILATION_FILES_FOLDER_SUP = $(TARGET_SUP).dSYM
COMPILATION_FILES_FOLDER_INF = $(TARGET_INF).dSYM
INPUT_IMAGE_1 ?= $(PREFIX)_input_01.pgm
INPUT_IMAGE_2 ?= $(PREFIX)_input_02.pgm
OUTPUT_SUP = exercise_02c_sup_output_01.pgm
OUTPUT_INF = exercise_02c_inf_output_01.pgm

build: $(TARGET_SUP) $(TARGET_INF)

$(TARGET_SUP): $(SOURCE_SUP)
	$(CXX) $(CXXFLAGS) $(OPTIMIZATION_LEVEL) $(LDFLAGS) -o $@ $< -I$(OPENCV_INCDIR) -L$(OPENCV_LIBDIR) $(OPENCV_LIBS)

$(TARGET_INF): $(SOURCE_INF)
	$(CXX) $(CXXFLAGS) $(OPTIMIZATION_LEVEL) $(LDFLAGS) -o $@ $< -I$(OPENCV_INCDIR) -L$(OPENCV_LIBDIR) $(OPENCV_LIBS)

run_sup: $(TARGET_SUP)
	./$(TARGET_SUP) $(INPUT_IMAGE_1) $(INPUT_IMAGE_2)

run_inf: $(TARGET_INF)
	./$(TARGET_INF) $(INPUT_IMAGE_1) $(INPUT_IMAGE_2)

clean:
	rm -rf $(TARGET_SUP) $(TARGET_INF) $(COMPILATION_FILES_FOLDER_SUP) $(COMPILATION_FILES_FOLDER_INF) $(OUTPUT_SUP) $(OUTPUT_INF)
