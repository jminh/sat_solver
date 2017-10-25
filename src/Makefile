all:
	rm -rf build
	mkdir build
	cd build; cmake .. -DCMAKE_BUILD_TYPE:STRING=Debug; make

clean:
	rm -rf build

ide:
	mkdir ../src_build
	cd ../src_build && cmake -G"Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug ../src
