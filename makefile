default:
	[ -d build ] || mkdir build
	(cd build; cmake ..; cmake --build .)
	build/src/kake