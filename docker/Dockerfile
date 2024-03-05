FROM debian:bullseye

# Update package lists
RUN apt update && apt upgrade -y

# Install dependencies
RUN apt install -y \
    cmake \
    git \
    g++ \
    libgtk3.0-dev \
    libopencv-dev

# Create folder for OpenCV source
WORKDIR /opencv

# Clone OpenCV repository (adjust URL for specific version if needed)
RUN git clone https://github.com/opencv/opencv.git

# Create build directory
WORKDIR /opencv/build

# Configure OpenCV build (without Python bindings for smaller image)
RUN cmake  \
    -DCMAKE_BUILD_TYPE=RELEASE \
    -DCMAKE_INSTALL_PREFIX=/usr/local \
    ../opencv

# Build OpenCV
RUN make -j $(nproc)

# Install OpenCV libraries
RUN make install

# Clean up build files (optional)
RUN make clean

# Final image
CMD ["bash"]
