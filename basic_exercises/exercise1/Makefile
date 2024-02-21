CXX = g++
CXXFLAGS = -std=c++11
LDFLAGS = -Wl,-rpath,/usr/local/lib

OPENCV_INCDIR = /usr/local/include/opencv4
OPENCV_LIBDIR = /usr/local/lib
OPENCV_LIBS = -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_imgcodecs

TARGET = example_opencv_1
SOURCE = example_opencv_1.cpp
IMAGE = cam_74.pgm

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $@ $< -I$(OPENCV_INCDIR) -L$(OPENCV_LIBDIR) $(OPENCV_LIBS) $(LDFLAGS)

run: $(TARGET) $(IMAGE)
	./$(TARGET) $(IMAGE)

clean:
	rm -f output1.pgm $(TARGET)
